#ifndef BLUEDBMANAGER_H
#define BLUEDBMANAGER_H

#include <aesmodule.h>

class BlueDBManager
{

public:
    BlueDBManager();
    void createFile(const QString &path);
    void writeFile(const QString &path, const QJsonDocument jsonDoc, const QString &compositeKey, const unsigned int iterations);
    //QJsonDocument readFile()

private:
    const QString ADATA = "Blue Password Manager Database";

};

#endif // BLUEDBMANAGER_H
