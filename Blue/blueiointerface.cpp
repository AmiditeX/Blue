#include "blueiointerface.h"
#include "aesmodule.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMutex>

BlueIOInterface::BlueIOInterface()
{

}

//Converts a JSON document to a compressed Base64 encoded QString
QString BlueIOInterface::jsonDocToQStringBase64(const QJsonDocument &jsonDoc)
{
    QByteArray binaryDoc = qCompress(jsonDoc.toBinaryData(), 9);
    return AESModule::toQStringBase64(binaryDoc.toStdString());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BlueIOInterface::writeFile(const QString &filePath, const QJsonDocument jsonDoc, const QString &compositeKey,
                                const unsigned int iterations, const unsigned int stretchTime)
{
    try
    {
        QString kdfSalt = AESModule::generateSalt(); //Generate a 64 bytes salt
        QString derivedKey = AESModule::derivateKey(compositeKey, kdfSalt, iterations, stretchTime); //Derivate final key from the composite key
        QString initializationVector = AESModule::generateIV(); //Generate a random initialization vector
        QString aData = kdfSalt + initializationVector; //Compute authenticated data of IV and salt
        QString encryptedData = AESModule::encryptData(jsonDocToQStringBase64(jsonDoc), aData, derivedKey, initializationVector); //Encrypt compressed database

        if(kdfSalt.isEmpty() || derivedKey.isEmpty() || initializationVector.isEmpty() || encryptedData.isEmpty())
            throw std::runtime_error("Undefined database value on writing");

        QJsonObject finalObject; //Prepare the file with the database and its metadata
        finalObject.insert("DBField", encryptedData); //Add the encrypted database
        finalObject.insert("DBInitVector", initializationVector); //Add the initialization vector
        finalObject.insert("DBKeySalt", kdfSalt); //Add the KDF salt
        finalObject.insert("DBIterations", iterations); //Add KDF iteration count
        finalObject.insert("DBStretchTime", stretchTime); //Add KDF stretch time
        QJsonDocument finalDoc(finalObject);

        QMutex fileMutex; //Lock mutex to avoid multiple thread overlapping
        fileMutex.lock();

        QFile file(filePath); //Open the file and check for errors
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
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
    catch(const std::exception &exception)
    {
        emit errorSignal(exception.what());
    }
}

void BlueIOInterface::readFile(const QString &filePath, const QString &compositeKey)
{
    try
    {
        QMutex fileMutex; //Lock mutex to avoid multiple thread overlapping
        fileMutex.lock();

        QFile file(filePath); //Open the file and check for errors
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            fileMutex.unlock(); //Unlock mutex before throwing
            throw std::runtime_error("Failed to open reading device");
        }

        QString wrappedData = qUncompress(file.readAll(), 9); //Retrieve uncompressed data
        file.close();
        fileMutex.unlock();

        QJsonDocument doc = QJsonDocument::fromJson(wrappedData);
        QJsonObject jsonObject = doc.object(); //Recover JSON encapsulating object

        QString DBField = jsonObject.value("DBField").toString(); //Recover encrypted database
        QString DBInitVector = jsonObject.value("DBInitVector").toString(); //Recover initialization vector
        QString DBKeySalt = jsonObject.value("DBKeySalt").toString(); //Recover KDF salt
        unsigned int DBIterations = jsonObject.value("DBIterations").toInt(); //Recover KDF iterations
        unsigned int DBStretchTime = jsonObject.value("DBStretchTime").toInt(); //Recover KDF stretch time
        QString aData = DBKeySalt + DBInitVector; //Compute authenticated data

        if(DBField.isEmpty() || DBInitVector.isEmpty() || DBKeySalt.isEmpty() || DBIterations.isEmpty() || DBStretchTime.isEmpty())
            throw std::runtime_error("Undefined database value on reading");

        QString derivedKey = AESModule::derivateKey(compositeKey, DBKeySalt, DBIterations, DBStretchTime); //Derivate key using database parameters
        QString decryptedData = AESModule::decryptData(DBField, aData, derivedKey, DBInitVector); //Decrypt the database using database parameters

        DBParameters returnObject{QJsonDocument.fromJson(decryptedData), DBInitVector, DBKeySalt, DBIterations, DBStretchTime};
        emit readComplete(returnObject); //Return decrypted database + database parameters
    }
    catch(const std::exception &exception)
    {
        emit errorSignal(exception.what());
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
