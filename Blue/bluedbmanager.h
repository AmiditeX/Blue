#ifndef BLUEDBMANAGER_H
#define BLUEDBMANAGER_H

#include <QObject>
#include "bluedatabase.h"
#include "blueiointerface.h"

class BlueDBManager : public QObject
{
    Q_OBJECT

public:
    BlueDBManager();

    //IO Functions using multiple threads
    void writeDatabase(const BlueDatabase &dataBase);
    void readDatabase(const QString &path, const QString &compositeKey);
    
public slots:
    void databaseWritten();
    void databaseRead(DBParameters dbParam);
    void error(QString errorString);
    void failedDecryption(QString errorString);

private:

};

#endif // BLUEDBMANAGER_H
