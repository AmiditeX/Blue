#include "BlueCrypto/blueiointerface.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMutex>
#include <filters.h>
#include "BlueCrypto/aesmodule.h"

BlueIOInterface::BlueIOInterface()
{

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
        QByteArray kdfSalt = AESModule::generateSalt(); //Generate a 64 bytes salt
        QByteArray derivedKey = AESModule::derivateKey(compositeKey.toUtf8(), kdfSalt, iterations, stretchTime); //Derivate final key from the composite key
        QByteArray initializationVector = AESModule::generateIV(); //Generate a random initialization vector
        QByteArray iter, stretch; iter.setNum(iterations); stretch.setNum(stretchTime); //Int parameters to binary
        QByteArray aData = kdfSalt + initializationVector + iter + stretch; //Compute authenticated data of IV and salt

        //Convert JSON to Binary, compress it, encrypt it
        QByteArray encryptedData = AESModule::encryptBinary(qCompress(jsonDoc.toBinaryData(), 9), aData, derivedKey, initializationVector);

        if(kdfSalt.isEmpty() || derivedKey.isEmpty() || initializationVector.isEmpty() || encryptedData.isEmpty())
            throw std::runtime_error("Undefined database value on writing");

        QJsonObject finalObject; //Prepare the file with the database and its metadata
        finalObject.insert("DBField", QString(encryptedData.toBase64())); //Add the encrypted database
        finalObject.insert("DBInitVector", QString(initializationVector.toBase64())); //Add the initialization vector
        finalObject.insert("DBKeySalt", QString(kdfSalt.toBase64())); //Add the KDF salt
        finalObject.insert("DBIterations", iterations); //Add KDF iteration count
        finalObject.insert("DBStretchTime", stretchTime); //Add KDF stretch time
        QJsonDocument finalDoc(finalObject);

        QMutex fileMutex; //Lock mutex to avoid multiple thread overlapping
        fileMutex.lock();

        QFile file(filePath); //Open the file and check for errors
        if(!file.open(QIODevice::WriteOnly))
        {
            fileMutex.unlock(); //Unlock mutex before throwing
            throw std::runtime_error("Failed to open writing device");
        }

        //Write the encrypted database and metada as a compressed binary file
        file.write(qCompress(finalDoc.toBinaryData(), 9));
        file.close();
        fileMutex.unlock();

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
        QMutex fileMutex; //Lock mutex to avoid multiple thread overlapping
        fileMutex.lock();

        QFile file(filePath); //Open the file and check for errors
        if(!file.open(QIODevice::ReadOnly))
        {
            fileMutex.unlock(); //Unlock mutex before throwing
            throw std::runtime_error("Failed to open reading device");
        }

        QByteArray wrappedData = qUncompress(file.readAll()); //Retrieve uncompressed data
        file.close();
        fileMutex.unlock();

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

        QByteArray derivedKey = AESModule::derivateKey(compositeKey.toUtf8(), DBKeySalt, DBIterations, DBStretchTime); //Derivate key using database parameters

        //Decrypt data, uncompress it
        QByteArray decryptedData = qUncompress(AESModule::decryptBinary(DBField, aData, derivedKey, DBInitVector));

        DBParameters returnObject{QJsonDocument::fromBinaryData(decryptedData), DBInitVector, DBKeySalt, DBIterations, DBStretchTime};
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
