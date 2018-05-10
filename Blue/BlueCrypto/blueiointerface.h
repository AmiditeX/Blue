#ifndef BLUEIOINTERFACE_H
#define BLUEIOINTERFACE_H

#include <QObject>
#include <QMutex>
#include <QJsonDocument>

struct DBParameters
{
    QJsonDocument DBDecrypted;
    QByteArray DBInitVector, DBKeySalt;
    int DBIterations = 0, DBStretchTime = 0;
    QString DBPassword, DBPath;
};

class BlueIOInterface : public QObject
{
    Q_OBJECT

public:
    BlueIOInterface(QMutex *mutex);
    ~BlueIOInterface();

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

private:
    QMutex *_fileMutex;

};

#endif // BLUEIOINTERFACE_H
