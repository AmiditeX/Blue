#ifndef BLUEIOINTERFACE_H
#define BLUEIOINTERFACE_H

#include <QObject>

class BlueIOInterface
{

public:
    BlueIOInterface();

public slots:
    void writeFile(const QString &path, const QJsonDocument jsonDoc, const QString &compositeKey,
                   const unsigned int iterations, const unsigned int time);
    QJsonDocument readFile(const QString &path, const QString &compositeKey);
};

#endif // BLUEIOINTERFACE_H
