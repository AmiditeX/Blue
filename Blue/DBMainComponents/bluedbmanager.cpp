#include "bluedbmanager.h"
#include <QObject>
#include <QThread>
#include <QJsonDocument>
#include <QMutex>
#include <QFile>
#include "BlueCrypto/blueiointerface.h"
#include "bluedatabase.h"

#include <QDebug>

BlueDBManager::BlueDBManager()
{

}

BlueDBManager::~BlueDBManager()
{
    qWarning() << "BlueDBManager destructor called";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Create a new database object, when done signal databaseRead is emitted
void BlueDBManager::createDatabaseObject(const QString &path, const QString &compositeKey)
{
    readDatabase(path, compositeKey);
    _path = path;
}

//Save the current database managed by the manager to a file
void BlueDBManager::writeDatabaseObject()
{
    writeDatabase(*_database);
}

//Create a new database with nothing inside of it, instanciate a BlueDatabase
void BlueDBManager::createNewDatabase(const QString &path, const QString &compositeKey, const int iterations, const int stretchtime)
{
    //Create a file for the database
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        error("Failed to create a new file");
    }

    _path = path;

    //Set settings to the database
    DBParameters parameters;
    parameters.DBIterations = iterations;
    parameters.DBStretchTime = stretchtime;
    parameters.DBPassword = compositeKey;
    parameters.DBPath = path;

    //Act as if the database was read
    databaseRead(parameters);
}

//Instanciate a new database and construct it with its parameters
void BlueDBManager::databaseRead(DBParameters dbParam)
{
    //Create a new database
    _database = std::make_shared<BlueDatabase>(dbParam);
    //Create a new widget and emit finish signal
    _widget = new BlueWidget(_database);
    emit createSignal(_widget, _path);

    //Return IO to normal state
    _canIoOperate = true;

    //Debug TODO REMOVE
    qWarning() << "READ";
}

void BlueDBManager::databaseWritten()
{
    _canIoOperate = true;
    qWarning() << "database has been written";
}

void BlueDBManager::failedDecryption(QString errorString)
{
    qWarning() << " ERROR " << errorString;
}

void BlueDBManager::error(QString errorString)
{
    qWarning() << "FATAL ERROR" << errorString;
}

BlueWidget* BlueDBManager::returnWidget()
{
    return _widget;
}

QString BlueDBManager::getPath()
{
    return _path;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PROTECTED                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Write the database in a separate thread to avoid a GUI freeze
void BlueDBManager::writeDatabase(const BlueDatabase &dataBase)
{
    if(!_canIoOperate) //Cannot do an IO operation if one is pending
        return;

    _canIoOperate = false;

    QThread *ioDeviceThread = new QThread();
    BlueIOInterface *ioDevice = new BlueIOInterface(&_fileMutex);
    ioDevice->moveToThread(ioDeviceThread); //Working in a separate thread

    //Basic signals, retrieve status after completion or failure
    QObject::connect(ioDevice, SIGNAL(writeCompleted()), this, SLOT(databaseWritten()));
    QObject::connect(ioDevice, SIGNAL(errorSignal(QString)), this, SLOT(error(QString)));
    QObject::connect(this, SIGNAL(startWriting(QString,QJsonDocument,QString,int,int)), ioDevice, SLOT(writeFile(QString,QJsonDocument,QString,int,int)));

    //When task completed or failed, destroy the device and the thread
    QObject::connect(ioDeviceThread, SIGNAL(finished()), ioDeviceThread, SLOT(deleteLater()));
    QObject::connect(ioDeviceThread, SIGNAL(finished()), ioDevice, SLOT(deleteLater()));

    //Start the thread and start writing the file
    ioDeviceThread->start();

    emit startWriting(dataBase.getParameters().DBPath, //Path to the database
                      dataBase.getJsonDocument(), //JSON of the database
                      dataBase.getParameters().DBPassword, //Compositekey to be derivated
                      dataBase.getParameters().DBIterations, //Iteration count to derivate
                      dataBase.getParameters().DBStretchTime); //Time to be taken to derivate
}

//Read the database using a separate thread to avoid a GUI freeze
void BlueDBManager::readDatabase(const QString &path, const QString &compositeKey)
{
    if(!_canIoOperate) //Cannot do an IO operation if one is pending
        return;

    _canIoOperate = false;

    QThread *ioDeviceThread = new QThread();
    BlueIOInterface *ioDevice = new BlueIOInterface(&_fileMutex);
    ioDevice->moveToThread(ioDeviceThread); //Working in a separate thread

    //Basic signals, retrieve status after completion or failure
    QObject::connect(ioDevice, SIGNAL(readCompleted(DBParameters)), this, SLOT(databaseRead(DBParameters)));
    QObject::connect(ioDevice, SIGNAL(errorSignal(QString)), this, SLOT(error(QString)));
    QObject::connect(ioDevice, SIGNAL(decryptionFailed(QString)), this, SLOT(failedDecryption(QString)));
    QObject::connect(this, SIGNAL(startReading(QString,QString)), ioDevice, SLOT(readFile(QString,QString)));

    //When task completed or failed, destroy the device and the thread
    QObject::connect(ioDeviceThread, SIGNAL(finished()), ioDeviceThread, SLOT(deleteLater()));
    QObject::connect(ioDeviceThread, SIGNAL(finished()), ioDevice, SLOT(deleteLater()));

    //Start the thread and start reading the file
    ioDeviceThread->start();

    emit startReading(path, compositeKey);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PROTECTED                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
