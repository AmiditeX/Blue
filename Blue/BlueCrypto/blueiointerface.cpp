#include "BlueCrypto/blueiointerface.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QThread>
#include <filters.h>
#include "BlueCrypto/aesmodule.h"

BlueIOInterface::BlueIOInterface(QMutex *mutex)
{
    _fileMutex = mutex;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Encrypt database, add the metadata and write it to a file
void BlueIOInterface::writeFile(const QString &filePath, const QJsonDocument jsonDoc, const QString &compositeKey,
                                int iterations, int stretchTime)
{
    try
    {
        QMutexLocker locker(_fileMutex); //Lock mutex to avoid multiple thread overlapping

        QByteArray kdfSalt = AESModule::generateSalt(); //Generate a 64 bytes salt
        AESModule::DerivedObject devObject = AESModule::derivateKey(compositeKey.toUtf8(), kdfSalt, iterations, stretchTime); //Derivate final key from the composite key
        QByteArray derivedKey = devObject.derivedKey;
        QByteArray initializationVector = AESModule::generateIV(); //Generate a random initialization vector
        QByteArray iter, stretch; iter.setNum(devObject.iterations); stretch.setNum(stretchTime); //Int parameters to binary
        QByteArray aData = kdfSalt + initializationVector + iter + stretch; //Compute authenticated data of IV and salt

        //Convert JSON to Binary, compress it, encrypt it
        QByteArray encryptedData = AESModule::encryptBinary(qCompress(jsonDoc.toBinaryData(), 9), aData, derivedKey, initializationVector);

        if(kdfSalt.isEmpty() || derivedKey.isEmpty() || initializationVector.isEmpty() || encryptedData.isEmpty())
            throw std::runtime_error("Undefined database value on writing");

        QJsonObject finalObject; //Prepare the file with the database and its metadata
        finalObject.insert("DBField", QString(encryptedData.toBase64())); //Add the encrypted database
        finalObject.insert("DBInitVector", QString(initializationVector.toBase64())); //Add the initialization vector
        finalObject.insert("DBKeySalt", QString(kdfSalt.toBase64())); //Add the KDF salt
        finalObject.insert("DBIterations", devObject.iterations); //Add KDF iteration count
        finalObject.insert("DBStretchTime", stretchTime); //Add KDF stretch time
        QJsonDocument finalDoc(finalObject);

        QFile file(filePath); //Open the file and check for errors
        if(!file.open(QIODevice::WriteOnly))
        {
            throw std::runtime_error("Failed to open writing device");
        }

        //Write the encrypted database and metada as a compressed binary file
        file.write(qCompress(finalDoc.toBinaryData(), 9));
        file.close();

        _fileMutex->unlock();
        //Emit completion signal
        emit writeCompleted();
    }
    catch(const std::exception &exception) //Fatal error
    {
        emit errorSignal(exception.what());
    }
}

//Read database file, decrypt it using metadata and return it decrypted
void BlueIOInterface::readFile(const QString &filePath, const QString &compositeKey)
{
    try
    {
        QMutexLocker locker(_fileMutex); //Lock mutex to avoid multiple thread overlapping

        QFile file(filePath); //Open the file and check for errors
        if(!file.open(QIODevice::ReadOnly))
        {
            throw std::runtime_error("Failed to open reading device");
        }

        QByteArray wrappedData = qUncompress(file.readAll()); //Retrieve uncompressed data
        file.close();

        QJsonDocument doc = QJsonDocument::fromBinaryData(wrappedData);
        QJsonObject jsonObject = doc.object(); //Recover JSON encapsulating object

        QByteArray DBField = QByteArray::fromBase64(jsonObject.value("DBField").toString().toUtf8()); //Recover encrypted database
        QByteArray DBInitVector = QByteArray::fromBase64(jsonObject.value("DBInitVector").toString().toUtf8()); //Recover initialization vector
        QByteArray DBKeySalt = QByteArray::fromBase64(jsonObject.value("DBKeySalt").toString().toUtf8()); //Recover KDF salt
        int DBIterations = jsonObject.value("DBIterations").toInt(); //Recover KDF iterations
        int DBStretchTime = jsonObject.value("DBStretchTime").toInt(); //Recover KDF stretch time
        QByteArray iter, stretch; iter.setNum(DBIterations); stretch.setNum(DBStretchTime); //Int parameters to binary
        QByteArray aData = DBKeySalt + DBInitVector + iter + stretch; //Compute authenticated data

        if(DBField.isEmpty() || DBInitVector.isEmpty() || DBKeySalt.isEmpty() || iter.isEmpty() || stretch.isEmpty())
            throw std::runtime_error("Undefined database value on reading");

        AESModule::DerivedObject devObject = AESModule::derivateKey(compositeKey.toUtf8(), DBKeySalt, DBIterations, 0); //Derivate key using database parameters
        QByteArray derivedKey = devObject.derivedKey;

        //Decrypt data, uncompress it
        QByteArray decryptedData = qUncompress(AESModule::decryptBinary(DBField, aData, derivedKey, DBInitVector));

        DBParameters returnObject{QJsonDocument::fromBinaryData(decryptedData), DBInitVector, DBKeySalt, DBIterations, DBStretchTime, compositeKey, filePath};

        _fileMutex->unlock();
        emit readCompleted(returnObject); //Return decrypted database + database parameters
    }
    catch(CryptoPP::HashVerificationFilter::HashVerificationFailed &exception) //Decryption failed (bad composite key, tampered file..)
    {
        emit decryptionFailed(exception.what());
    }
    catch(const std::exception &exception) //Fatal error
    {
        emit errorSignal(exception.what());
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
