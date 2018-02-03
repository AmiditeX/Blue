#ifndef BLUEIOINTERFACE_H
#define BLUEIOINTERFACE_H

#include <QObject>

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

public slots:
    void writeFile(const QString &path, const QJsonDocument jsonDoc, const QString &compositeKey,
                   const unsigned int iterations, const unsigned int time);
    void readFile(const QString &path, const QString &compositeKey);

signals:
    void writeComplete();
    void readCompleted(DBParameters dbParam);
    void errorSignal(QString errorString);

};

#endif // BLUEIOINTERFACE_H
