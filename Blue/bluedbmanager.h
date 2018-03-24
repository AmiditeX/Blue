#ifndef BLUEDBMANAGER_H
#define BLUEDBMANAGER_H

#include <QObject>
#include <vector>
#include "BlueCrypto/blueiointerface.h"
#include "bluedatabase.h"

class BlueDBManager : public QObject
{
    Q_OBJECT

public:
    BlueDBManager();

    //IO Functions using multiple threads
    void writeDatabase(const BlueDatabase &dataBase);
    void readDatabase(const QString &path, const QString &compositeKey);

    //Creating and deletin databases
    void createDatabaseObject(const QString &path, const QString &compositeKey);
    
public slots:
    void databaseWritten();
    void databaseRead(DBParameters dbParam);
    void error(QString errorString);
    void failedDecryption(QString errorString);

private:
    std::vector<std::shared_ptr<BlueDatabase>> _databaseList;

};

#endif // BLUEDBMANAGER_H
