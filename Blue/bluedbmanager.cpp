#include "bluedbmanager.h"

#include <QObject>
#include <QThread>
#include <QJsonDocument>
#include "BlueCrypto/blueiointerface.h"
#include "bluedatabase.h"

#include <QDebug>

BlueDBManager::BlueDBManager()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Write the database in a separate thread to avoid a GUI freeze
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
    ioDevice->writeFile(dataBase.getParameters().DBPath, //Path to the database
                        dataBase.getJsonDocument(), //JSON of the database
                        dataBase.getParameters().DBPassword, //Compositekey to be derivated
                        dataBase.getParameters().DBIterations, //Iteration count to derivate
                        dataBase.getParameters().DBStretchTime); //Time to be taken to derivate
}

void BlueDBManager::databaseWritten()
{
    qWarning() << "database has been written";
}

//Read the database using a separate thread to avoid a GUI freeze
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

void BlueDBManager::createDatabaseObject(const QString &path, const QString &compositeKey)
{
    readDatabase(path, compositeKey);
}

//Instanciate a new database and construct it with its parameters
void BlueDBManager::databaseRead(DBParameters dbParam)
{
    //Create a new database
    std::shared_ptr<BlueDatabase> dbPointer = std::make_shared<BlueDatabase>(dbParam);

    //Store the database in a list containing all the currently opened DB
    _databaseList.push_back(std::move(dbPointer));
}

void BlueDBManager::failedDecryption(QString errorString)
{
    qWarning() << " ERROR " << errorString;
}

void BlueDBManager::error(QString errorString)
{
    qWarning() << "FATAL ERROR" << errorString;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
