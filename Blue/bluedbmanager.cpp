#include "bluedbmanager.h"

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

BlueDBManager::BlueDBManager()
{
    createFile("TEST.JSON");
}


void BlueDBManager::createFile(const QString &path)
{
    QJsonObject databaseMain;
    databaseMain.insert("DBMain", QJsonValue());
    databaseMain.insert("III", QJsonValue());
    databaseMain.insert("II2", QJsonValue());

    QJsonDocument jdoc(databaseMain);

    writeFile("encrypted.txt", jdoc, "Password", 150000);
}

//Write the file containg the encrypted database and its metadata
void BlueDBManager::writeFile(const QString &path, const QJsonDocument jsonDoc, const QString &compositeKey, const unsigned int iterations)
{
    QString derivedKey = AESModule::generateKey(compositeKey, iterations); //Derivate final key from the composite key
    QString initializationVector = AESModule::generateIV(); //Generate a random initialization vector
    QString encryptedData = AESModule::encryptData(jsonDoc.toBinaryData(), ADATA, derivedKey, initializationVector); //Encrypt database

    //Retrieve the steps to encrypt/decrypt the database
    QJsonObject docObject = jsonDoc.object();
    QJsonArray decryptionSteps = docObject.value("Steps").toArray();


    QJsonObject finalObject; //Prepare the file with the database and its metadata
    finalObject.insert("DBField", encryptedData); //Add the encrypted database
    finalObject.insert("DBInitVector", initializationVector); //Add the initialization vector
    finalObject.insert("DBDecryptionSteps", decryptionSteps); //Add the steps to encrypt/decrypt the database
    QJsonDocument finalDoc(finalObject);

    QFile file(path); //Open the file and check for errors
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text ))
        throw std::runtime_error("Failed to open write device");

    //Write the encrypted database and metada as a compressed binary file
    file.write(qCompress(finalDoc.toJson(), 9));
}
