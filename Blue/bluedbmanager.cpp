#include "bluedbmanager.h"

#include <QObject>
#include <QThread>
#include <QJsonDocument>
#include "aesmodule.h"
#include "blueiointerface.h"
#include "bluedatabase.h"

#include <QDebug>

BlueDBManager::BlueDBManager()
{

}

void BlueDBManager::writeDatabase(const BlueDatabase &dataBase)
{
    QThread *ioDeviceThread = new QThread();
    BlueIOInterface *ioDevice = new BlueIOInterface();
    ioDevice->moveToThread(ioDeviceThread); //Working in a separate thread

    //Basic signals, retrieve status after completion or failure
    QObject::connect(ioDevice, SIGNAL(writeCompleted()), this, SLOT(databaseWritten()));
    QObject::connect(ioDevice, SIGNAL(errorSignal(QString)), this, SLOT(error(QString)));

    //When task completed or failed, destroy the device and the thread
    QObject::connect(ioDeviceThread, SIGNAL(finished()), ioDeviceThread, SLOT(deleteLater()));
    QObject::connect(ioDeviceThread, SIGNAL(finished()), ioDevice, SLOT(deleteLater()));

    //Start the thread and start writing the file
    ioDeviceThread->start();
    ioDevice->writeFile(dataBase.mData.path, //Path to the database
                        dataBase.getJsonDocument(), //JSON of the database
                        dataBase.mData.compositeKey, //Compositekey to be derivated
                        dataBase.mData.iterations, //Iteration count to derivate
                        dataBase.mData.stretchTime); //Time to be taken to derivate
}

void BlueDBManager::databaseWritten()
{
    qWarning() << "database has been written";
}

void BlueDBManager::readDatabase(const QString &path, const QString &compositeKey)
{
    QThread *ioDeviceThread = new QThread();
    BlueIOInterface *ioDevice = new BlueIOInterface();
    ioDevice->moveToThread(ioDeviceThread); //Working in a separate thread

    //Basic signals, retrieve status after completion or failure
    QObject::connect(ioDevice, SIGNAL(readCompleted(DBParameters)), this, SLOT(databaseRead(DBParameters)));
    QObject::connect(ioDevice, SIGNAL(errorSignal(QString)), this, SLOT(error(QString)));
    QObject::connect(ioDevice, SIGNAL(decryptionFailed(QString)), this, SLOT(failedDecryption(QString)));

    //When task completed or failed, destroy the device and the thread
    QObject::connect(ioDeviceThread, SIGNAL(finished()), ioDeviceThread, SLOT(deleteLater()));
    QObject::connect(ioDeviceThread, SIGNAL(finished()), ioDevice, SLOT(deleteLater()));

    //Start the thread and start reading the file
    ioDeviceThread->start();
    ioDevice->readFile(path, compositeKey);
}

void BlueDBManager::databaseRead(DBParameters dbParam)
{
    qWarning() << " GOING ON ";
    qWarning() << dbParam.DBDecrypted;
}

void BlueDBManager::failedDecryption(QString errorString)
{
    qWarning() << " ERROR " << errorString;
}

void BlueDBManager::error(QString errorString)
{
    qWarning() << "FATAL ERROR" << errorString;
}
