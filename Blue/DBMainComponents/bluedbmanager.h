#ifndef BLUEDBMANAGER_H
#define BLUEDBMANAGER_H

#include <QObject>
#include <QMutex>
#include <vector>
#include "BlueCrypto/blueiointerface.h"
#include "bluedatabase.h"

class BlueDBManager : public QObject
{
    Q_OBJECT

public:
    BlueDBManager();
    ~BlueDBManager();

    //Creating and deletin databases
    void createDatabaseObject(const QString &path, const QString &compositeKey);
    void writeDatabaseObject();
    void createNewDatabase(const QString &path, const QString &compositeKey, const int iterations, const int stretchtime);
    
protected:
    //IO Functions using multiple threads
    void writeDatabase(const BlueDatabase &dataBase);
    void readDatabase(const QString &path, const QString &compositeKey);

public slots:
    void databaseRead(DBParameters dbParam);
    void databaseWritten();
    void error(QString errorString);
    void failedDecryption(QString errorString);

signals:
    void startReading(const QString &filePath, const QString &compositeKey);
    void startWriting(const QString &filePath, const QJsonDocument jsonDoc, const QString &compositeKey,
                      int iterations, int stretchTime);

private:
    std::shared_ptr<BlueDatabase> _database;
    QMutex _fileMutex;
    bool _canIoOperate = true;

};

#endif // BLUEDBMANAGER_H
