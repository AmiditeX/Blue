#ifndef BLUEIOINTERFACE_H
#define BLUEIOINTERFACE_H

#include <QObject>
#include <QJsonDocument>

struct DBParameters
{
    const QJsonDocument DBDecrypted;
    const QString DBInitVector, DBKeySalt;
    const unsigned int DBIterations = 0, DBStretchTime = 0;
};

class BlueIOInterface
{

public:
    BlueIOInterface();
    
    //Converts a JSON document to a compressed Base64 encoded QString
    QString jsonDocToQStringBase64(const QJsonDocument &jsonDoc);

public slots:
    //Encrypt database, add the metadata and write it to a file
    void writeFile(const QString &filePath, const QJsonDocument jsonDoc, const QString &compositeKey,
                   const unsigned int iterations, const unsigned int stretchTime);
    //Read database file, decrypt it using metadata and return it decrypted
    void readFile(const QString &filePath, const QString &compositeKey);

signals:
    void writeCompleted();
    void readCompleted(DBParameters dbParam);
    void errorSignal(QString errorString);

};

#endif // BLUEIOINTERFACE_H
