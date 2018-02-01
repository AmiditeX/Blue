#include "blueiointerface.h"
#include "aesmodule.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

BlueIOInterface::BlueIOInterface()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BlueIOInterface::writeFile(const QString &path, const QJsonDocument jsonDoc, const QString &compositeKey,
                                const unsigned int iterations, const unsigned int time)
{
    try
    {
        QString kdfSalt = AESModule::generateSalt(); //Generate a 64 bytes salt
        QString derivatedKey = AESModule::derivateKey(compositeKey, kdfSalt, iterations, time); //Derivate final key from the composite key
        QString initializationVector = AESModule::generateIV(); //Generate a random initialization vector
        QString aData = kdfSalt + initializationVector; //Compute authenticated data of IV and salt
        QString encryptedData = AESModule::encryptData(jsonDoc.toBinaryData(), aData, derivatedKey, initializationVector); //Encrypt database

        QJsonObject finalObject; //Prepare the file with the database and its metadata
        finalObject.insert("DBField", encryptedData); //Add the encrypted database
        finalObject.insert("DBInitVector", initializationVector); //Add the initialization vector
        finalObject.insert("DBKeySalt", kdfSalt); //Add the KDF salt
        finalObject.insert("DBIterations", iterations); //Add KDF iteration count
        finalObject.insert("DBStretchTime", time); //Add KDF stretch time
        QJsonDocument finalDoc(finalObject);

        QFile file(path); //Open the file and check for errors
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
            throw std::runtime_error("Failed to open writing device");

        //Write the encrypted database and metada as a compressed binary file
        file.write(qCompress(finalDoc.toBinaryData(), 9));
        file.close();
    }
    catch(...)
    {

    }
}

void BlueIOInterface::readFile(const QString &path, const QString &compositeKey)
{
    try
    {
        QFile file(path); //Open the file and check for errors
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            throw std::runtime_error("Failed to open reading device");

        QString wrappedData = qUncompress(file.readAll(), 9); //Uncompress data
        file.close();

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

        QString derivatedKey = AESModule::derivateKey(compositeKey, DBKeySalt, DBIterations, DBStretchTime); //Derivate key using database parameters
        QString decryptedData = AESModule::decryptData(DBField, aData, derivatedKey, DBInitVector); //Decrypt the database using database parameters

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
