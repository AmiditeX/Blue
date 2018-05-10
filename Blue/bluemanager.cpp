#include "bluemanager.h"

#include <QDebug>

BlueManager::BlueManager()
{
    //Create UI
    window = new MainWindow();
    window->show();

    //Self-test all cryptographic functions
    if(!AESModule::integrityCheck())
    {
        //Display error message, freeze the window
        window->displayGeneralError(tr("An error occured while testing the cryptographic module. Decryption/encryption is flawed."
                                       "\nCorrect execution of the program is impossible. Error logs written to \"logs.txt\""
                                       "\nFatal error, terminating."));
    }

    QObject::connect(window, SIGNAL(openingRequest(QString,QString,QString)), this, SLOT(openDatabase(QString,QString,QString)));
    QObject::connect(window, SIGNAL(createRequest(DatabaseCreator::DatabaseParam)), this, SLOT(createDatabase(DatabaseCreator::DatabaseParam)));
    QObject::connect(window, SIGNAL(closeRequest(BlueWidget*)), this, SLOT(closeDatabase(BlueWidget*)));
    QObject::connect(window, SIGNAL(settingsChanged(BlueWidget*,DatabaseSettings::DatabaseParam)), this, SLOT(settingsChanged(BlueWidget*,DatabaseSettings::DatabaseParam)));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Open a new database by creating a DatabaseManager and loading up the UI
void BlueManager::openDatabase(QString masterKey, QString filePath, QString keyPath)
{
    //Check if DB not already open
    for(unsigned int i = 0; i < _dbManagerList.size(); i++)
    {
        if(_dbManagerList[i]->getPath() == filePath)
        {
            window->displayGeneralError(tr("This database is already opened"));
            return;
        }
    }

    //Create a new DBManager and store it
    std::shared_ptr<BlueDBManager> dbManager = std::make_shared<BlueDBManager>();
    _dbManagerList.push_back(dbManager);

    QString compositeKey; //Compute the compositekey with keyfile (if provided) and password
    if(!keyPath.isEmpty())
    {
        QFile keyFile(keyPath);
        if(!keyFile.open(QIODevice::ReadOnly))
        { window->displayGeneralError(tr("Couldn't open the key file, verify it exists and isn't currently used by another program")); return; }

        compositeKey = masterKey + QString::fromUtf8(QCryptographicHash::hash(keyFile.readAll(), QCryptographicHash::Sha256).toBase64());
    }
    else { compositeKey = masterKey; }

    QObject::connect(dbManager.get(), SIGNAL(createSignal(BlueWidget*, QString)), window, SLOT(displayWidget(BlueWidget*, QString)));
    QObject::connect(dbManager.get(), SIGNAL(writtenSignal()), this, SLOT(terminateDatabase()));
    QObject::connect(dbManager.get(), SIGNAL(errorSignal(QString)), this, SLOT(databaseError(QString)));
    QObject::connect(dbManager.get(), SIGNAL(decryptionErrSignal(QString)), this, SLOT(databaseDecryptionError(QString)));

    dbManager->createDatabaseObject(filePath, compositeKey);
}

//Create a new database by creating a DatabaseManager and loading up the UI
void BlueManager::createDatabase(DatabaseCreator::DatabaseParam parameters)
{
    //Check if DB not already open
    for(unsigned int i = 0; i < _dbManagerList.size(); i++)
    {
        if(_dbManagerList[i]->getPath() == parameters.dbPath)
        {
            window->displayGeneralError(tr("This database is already opened"));
            return;
        }
    }

    //Create a new DBManager and store it
    std::shared_ptr<BlueDBManager> dbManager = std::make_shared<BlueDBManager>();
    _dbManagerList.push_back(dbManager);
    QObject::connect(dbManager.get(), SIGNAL(createSignal(BlueWidget*, QString)), window, SLOT(displayWidget(BlueWidget*, QString)));
    QObject::connect(dbManager.get(), SIGNAL(writtenSignal()), this, SLOT(terminateDatabase()));
    QObject::connect(dbManager.get(), SIGNAL(errorSignal(QString)), this, SLOT(databaseError(QString)));
    QObject::connect(dbManager.get(), SIGNAL(decryptionErrSignal(QString)), this, SLOT(databaseDecryptionError(QString)));

    QString compositeKey; //Compute the compositekey with keyfile (if provided) and password
    if(!parameters.keyPath.isEmpty())
    {
        QFile keyFile(parameters.keyPath);
        if(!keyFile.open(QIODevice::ReadOnly))
        { window->displayGeneralError(tr("Couldn't open the key file, verify it exists and isn't currently used by another program")); return; }

        compositeKey = parameters.password + QString::fromUtf8(QCryptographicHash::hash(keyFile.readAll(), QCryptographicHash::Sha256).toBase64());
    }
    else { compositeKey = parameters.password; }

    if(parameters.iterations > 0) //Iterations override the stretchtime
    { parameters.stretchTime = 0; }

    dbManager->createNewDatabase(parameters.dbPath, compositeKey, parameters.iterations, parameters.stretchTime);
    dbManager->writeDatabaseObject();
}

//Connect the DatabaseManager to its ending slot
void BlueManager::closeDatabase(BlueWidget *w)
{
    for(unsigned int i = 0; i < _dbManagerList.size(); i++)
    {
        if(_dbManagerList[i]->returnWidget() == w)
        {
            if(_dbManagerList[i]->isIoOperate()) //Database is not already being written
            {
                _dbManagerList[i]->setDeletionStatus(true); //Mark database as deletetable
                _dbManagerList[i]->writeDatabaseObject(); //Send a write signal for final saving
            }
            else //Database already getting written, needing to write it a last time
            {
                _dbManagerList[i]->setFinalSave(true); //Mark it as needing a last time save
            }
            return;
        }
    }
}

//Called when settings for one database were changed
void BlueManager::settingsChanged(BlueWidget *w, DatabaseSettings::DatabaseParam param)
{
    for(unsigned int i = 0; i < _dbManagerList.size(); i++)
    {
        if(_dbManagerList[i]->returnWidget() == w)
        {
            QString compositeKey; //Compute the compositekey with keyfile (if provided) and password
            if(!param.keyPath.isEmpty())
            {
                QFile keyFile(param.keyPath);
                if(!keyFile.open(QIODevice::ReadOnly))
                { window->displayGeneralError(tr("Couldn't open the key file, verify it exists and isn't currently used by another program")); return; }

                compositeKey = param.password + QString::fromUtf8(QCryptographicHash::hash(keyFile.readAll(), QCryptographicHash::Sha256).toBase64());
            }
            else { compositeKey = param.password; }

            DBParameters parameters{QJsonDocument(), "", "", param.iterations, param.stretchTime, compositeKey, param.dbPath};
            _dbManagerList[i]->changeParameters(parameters); //Change parameters of the database linked to this widget
            return;
        }
    }
}

//Fatal error from the database
void BlueManager::databaseError(const QString &err)
{
    BlueDBManager* manager = qobject_cast<BlueDBManager*>(sender());
    std::shared_ptr<BlueDBManager> dbManager;

    for(unsigned int i = 0; i < _dbManagerList.size(); i++)
    {
        if(_dbManagerList[i].get() == manager)
        {
            dbManager = _dbManagerList[i];
        }
    }

    QString errorStr = tr("Error during encryption or decryption of the database %1 \nError returned : %2").arg(dbManager->getPath(), err);
    window->displayGeneralError(errorStr);
    _dbManagerList.erase(std::remove(_dbManagerList.begin(), _dbManagerList.end(), dbManager), _dbManagerList.end()); //Delete the database
}

//Decryption error occured while opening a database
void BlueManager::databaseDecryptionError(const QString &err)
{
    qWarning() <<"decryption error";
    BlueDBManager* manager = qobject_cast<BlueDBManager*>(sender());
    std::shared_ptr<BlueDBManager> dbManager;

    for(unsigned int i = 0; i < _dbManagerList.size(); i++)
    {
        if(_dbManagerList[i].get() == manager)
        {
            dbManager = _dbManagerList[i];
        }
    }

    QString errorStr = tr("Error during decryption, the password or the key file provided may be wrong for database \n%1 \nError returned : %2").arg(dbManager->getPath(), err);
    window->displayGeneralError(errorStr);
    _dbManagerList.erase(std::remove(_dbManagerList.begin(), _dbManagerList.end(), dbManager), _dbManagerList.end()); //Delete the database

}

//Called everytime the database is written, if it is marked as deleted, it is removed
void BlueManager::terminateDatabase()
{
    BlueDBManager* manager = qobject_cast<BlueDBManager*>(sender());
    std::shared_ptr<BlueDBManager> dbManager;

    for(unsigned int i = 0; i < _dbManagerList.size(); i++)
    {
        if(_dbManagerList[i].get() == manager)
        {
            dbManager = _dbManagerList[i];
        }
    }

    if(dbManager->isDeletionReady()) //This database has already been written for its last time and is ready to die
    {
        _dbManagerList.erase(std::remove(_dbManagerList.begin(), _dbManagerList.end(), dbManager), _dbManagerList.end()); //Remove DBManager, ending its life, farewell
        return;
    }

    if(dbManager->isFinalSave()) //This database has yet to be written for its last time, mark it as dying
    {
        dbManager->setDeletionStatus(true);
        dbManager->writeDatabaseObject();
        return;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BlueManager::~BlueManager()
{
    delete window;
}
