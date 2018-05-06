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

            qWarning() << "OPEN KEY " << compositeKey;
    QObject::connect(dbManager.get(), SIGNAL(createSignal(BlueWidget*, QString)), window, SLOT(displayWidget(BlueWidget*, QString)));
    dbManager->createDatabaseObject(filePath, compositeKey);
}

//Create a new database by creating a DatabaseManager and loading up the UI
void BlueManager::createDatabase(DatabaseCreator::DatabaseParam parameters)
{
    //Create a new DBManager and store it
    std::shared_ptr<BlueDBManager> dbManager = std::make_shared<BlueDBManager>();
    _dbManagerList.push_back(dbManager);
    QObject::connect(dbManager.get(), SIGNAL(createSignal(BlueWidget*, QString)), window, SLOT(displayWidget(BlueWidget*, QString)));

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

            qWarning() << "CREATE KEY " << compositeKey;
    dbManager->createNewDatabase(parameters.dbPath, compositeKey, parameters.iterations, parameters.stretchTime);
    dbManager->writeDatabaseObject();
}

/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BlueManager::~BlueManager()
{
    delete window;
}
