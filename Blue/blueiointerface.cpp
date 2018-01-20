#include "blueiointerface.h"
#include "aesmodule.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

BlueIOInterface::BlueIOInterface()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BlueIOInterface::writeFile(const QString &path, const QJsonDocument jsonDoc, const QString &compositeKey,
                                const unsigned int iterations, const unsigned int time)
{
    QString kdfSalt = AESModule::generateSalt(); //Generate a 64 bytes salt
    QString derivedKey = AESModule::generateKey(compositeKey, kdfSalt, iterations, time); //Derivate final key from the composite key
    QString initializationVector = AESModule::generateIV(); //Generate a random initialization vector
    QString ADATA = kdfSalt + initializationVector; //Authenticate data of IV and salt
    QString encryptedData = AESModule::encryptData(jsonDoc.toBinaryData(), ADATA, derivedKey, initializationVector); //Encrypt database

    QJsonObject finalObject; //Prepare the file with the database and its metadata
    finalObject.insert("DBField", encryptedData); //Add the encrypted database
    finalObject.insert("DBInitVector", initializationVector); //Add the initialization vector
    finalObject.insert("DBSaltKey", kdfSalt); //Add the KDF salt
    finalObject.insert("DBIterations", iterations); //Add iteration count
    finalObject.insert("DBStretchTime", time); //Add key stretching time
    QJsonDocument finalDoc(finalObject);

    QFile file(path); //Open the file and check for errors
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        throw std::runtime_error("Failed to open writing device");

    //Write the encrypted database and metada as a compressed binary file
    file.write(qCompress(finalDoc.toJson(), 9));
    file.close();
}

QJsonDocument BlueIOInterface::readFile(const QString &path, const QString &compositeKey)
{
    QFile file(path); //Open the file and check for errors
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::runtime_error("Failed to open reading device");

    QString wrappedData = qUncompress(file.readAll(), 9);
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(wrappedData));
    QJsonObject jsonObject = doc.object();
    QString DBField = jsonObject.value

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
