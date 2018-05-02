#include "bluemanager.h"

BlueManager::BlueManager()
{
    //Create UI
    window = new MainWindow();
    window->show();

    //Self-test all cryptographic functions
    if(!AESModule::integrityCheck())
    {
        //Display error message, freeze the window
        window->displayGeneralError("An error occured while testing the cryptographic module. Decryption/encryption is flawed."
                                    "\nCorrect execution of the program is impossible. Error logs written to \"logs.txt\""
                                    "\nFatal error, terminating.");
    }

    QObject::connect(window, SIGNAL(openingRequest(QString,QString)), this, SLOT(openDatabase(QString,QString)));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Open a new database by creating a DatabaseManager and loading up the UI
void BlueManager::openDatabase(QString masterKey, QString filePath)
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

    QObject::connect(dbManager.get(), SIGNAL(createSignal(BlueWidget*)), window, SLOT(displayWidget(BlueWidget*)));
    dbManager->createDatabaseObject(filePath, masterKey);
}

/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BlueManager::~BlueManager()
{
    delete window;
}
