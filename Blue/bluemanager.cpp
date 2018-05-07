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
    dbManager->createDatabaseObject(filePath, compositeKey);
}

//Create a new database by creating a DatabaseManager and loading up the UI
void BlueManager::createDatabase(DatabaseCreator::DatabaseParam parameters)
{
    //Create a new DBManager and store it
    std::shared_ptr<BlueDBManager> dbManager = std::make_shared<BlueDBManager>();
    _dbManagerList.push_back(dbManager);
    QObject::connect(dbManager.get(), SIGNAL(createSignal(BlueWidget*, QString)), window, SLOT(displayWidget(BlueWidget*, QString)));
    QObject::connect(dbManager.get(), SIGNAL(writtenSignal()), this, SLOT(terminateDatabase()));

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
        qWarning() << dbManager->isDeletionReady() << dbManager->isFinalSave() << dbManager->isIoOperate();
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
