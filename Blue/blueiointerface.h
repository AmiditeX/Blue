#ifndef BLUEIOINTERFACE_H
#define BLUEIOINTERFACE_H

#include <QObject>
#include <QJsonDocument>

struct DBParameters
{
    const QJsonDocument DBDecrypted;
    const QByteArray DBInitVector, DBKeySalt;
    const int DBIterations = 0, DBStretchTime = 0;
};

class BlueIOInterface : public QObject
{
    Q_OBJECT

public:
    BlueIOInterface();

public slots:
    //Encrypt database, add the metadata and write it to a file
    void writeFile(const QString &filePath, const QJsonDocument jsonDoc, const QString &compositeKey,
                   int iterations, int stretchTime);
    //Read database file, decrypt it using metadata and return it decrypted
    void readFile(const QString &filePath, const QString &compositeKey);

signals:
    void writeCompleted();
    void readCompleted(DBParameters dbParam);
    void errorSignal(QString errorString);
    void decryptionFailed(QString errorString);

};

#endif // BLUEIOINTERFACE_H
