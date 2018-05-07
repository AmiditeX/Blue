#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <iostream>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set UI up
    ui->buttonColor_1->setVisible(false);
    ui->buttonColor_2->setVisible(false);
    ui->buttonColor_3->setVisible(false);
    ui->databaseTab->tabBar()->hide();

    //UI connects
    QObject::connect(ui->buttonOpen, SIGNAL(clicked(bool)), this, SLOT(switchButtonStatus()));
    QObject::connect(ui->buttonCreate, SIGNAL(clicked(bool)), this, SLOT(switchButtonStatus()));
    QObject::connect(ui->buttonSettings, SIGNAL(clicked(bool)), this, SLOT(switchButtonStatus()));

    QObject::connect(ui->buttonOpen, SIGNAL(clicked(bool)), this, SLOT(openDatabase()));
    QObject::connect(ui->buttonCreate, SIGNAL(clicked(bool)), this, SLOT(createDatabase()));


    //Database Opener
    opener = new DatabaseOpener(this);
    QObject::connect(opener, SIGNAL(openPressed()), this, SLOT(openerReturn()));
    QObject::connect(opener, SIGNAL(closePressed()), this, SLOT(openerClose()));
    QObject::connect(opener, SIGNAL(closePressed()), opener, SLOT(clear()));
    opener->setVisible(false);
    opener->move(260, 30);

    creator = new DatabaseCreator(this);
    QObject::connect(creator, SIGNAL(okPressed()), this, SLOT(creatorReturn()));
    QObject::connect(creator, SIGNAL(closePressed()), this, SLOT(creatorClose()));
    creator->setVisible(false);
    creator->move(260, 30);
}

MainWindow::~MainWindow()
{
    qWarning() << "DELETING MAINWINDOW";
    delete ui;
    delete opener;
    delete creator;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                          PUBLIC                                                                  //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::displayGeneralError(const QString &err)
{
    BlueDialog *dialog = new BlueDialog(this);
    QObject::connect(this, SIGNAL(destroyed(QObject*)), dialog, SLOT(deleteLater()));
    QObject::connect(dialog, SIGNAL(closeClicked()), dialog, SLOT(deleteLater()));
    QObject::connect(dialog, SIGNAL(okClicked()), dialog, SLOT(deleteLater()));

    dialog->setTitle(tr("Error"));
    dialog->setMessage(err);
    dialog->show();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                          PUBLIC                                                                  //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Select the database file to load it afterwards
void MainWindow::openDatabase()
{
    ui->databaseTab->setHidden(true);
    creator->setVisible(false);
    opener->setVisible(true);
}

void MainWindow::openerClose()
{
    opener->setVisible(false);
}

//Called when a DatabaseOpener has to return DB settings
void MainWindow::openerReturn()
{
    DatabaseOpener *opener = qobject_cast<DatabaseOpener*>(sender());
    //If a key path was returned, check for validity and open it
    if(!opener->getFilePath().isEmpty() && !opener->getMaster().isEmpty())
    {
        QDir dir;
        if(!dir.exists(opener->getFilePath()))
        {
            displayGeneralError(tr("The database file provided doesn't exist"));
            return;
        }

        if(!dir.exists(opener->getKey()) && !opener->getKey().isEmpty())
        {
            displayGeneralError(tr("The key file provided doesn't exist"));
            return;
        }
    }
    else
    {
        displayGeneralError(tr("Fill all the fields (Path to database, master password)"));
        return;
    }

    emit openingRequest(opener->getMaster(), opener->getFilePath(), opener->getKey());
    opener->clear();
    openerClose();
}


//UI to create a new database
void MainWindow::createDatabase()
{
    ui->databaseTab->setHidden(true);
    opener->setVisible(false);
    creator->setVisible(true);
}

//Pass settings to BlueManager, check for errors
void MainWindow::creatorReturn()
{
    DatabaseCreator::DatabaseParam params = creator->returnParams();
    if(params.dbPath.isEmpty()) //Error if file not provided, password not provided
    { displayGeneralError(tr("The path to the database wasn't provided")); return; }

    if(params.password.isEmpty())
    { displayGeneralError(tr("The password of the database wasn't provided")); return; }

    QDir dir; //Error if keyfile doesn't exist and if field isn't empty
    if(!dir.exists(params.keyPath) && !params.keyPath.isEmpty())
    {  displayGeneralError(tr("The key file doesn't exist")); return; }

    emit(createRequest(params));
    creatorClose();
}

//Close the creator UI
void MainWindow::creatorClose()
{
    creator->clear();
    creator->setVisible(false);
}

//Display the menu widget and the main database widget
void MainWindow::displayWidget(BlueWidget *w, const QString &path)
{
    //Add to mainwidget
    ui->databaseTab->addTab(w, path);
    ui->databaseTab->setCurrentWidget(w);
    creatorClose();
    openerClose();
    ui->databaseTab->setVisible(true);

    QListWidgetItem *item = new QListWidgetItem(); //Button has a pointer on item for deletion
    DatabaseButton *button = new DatabaseButton(this, w, item);
    item->setSizeHint(QSize(button->width(), 150));

    //Connect to remove from QListWidget and emit signal to close the database
    connect(button, &DatabaseButton::closeButtonClicked, [=](){
        QListWidgetItem *i = button->returnItem();
        ui->listDatabase->removeItemWidget(i); //Remove from sidebar
        delete i; //Remove i completly from the list (see QT doc)
        ui->databaseTab->removeTab(ui->databaseTab->indexOf(button->getWidget()));
        w->deleteLater();
        ui->databaseTab->setHidden(true);
        emit closeRequest(button->getWidget()); //Ask manager to terminate the database
    });

    //Connect for the drop animation
    connect(button, &DatabaseButton::dropMenu, [=](bool drop){
        QPropertyAnimation *animation = new QPropertyAnimation(button, "geometry");
        animation->setDuration(100);
        animation->setStartValue(button->geometry());
        if(drop) {animation->setEndValue(QRect(0, 0, button->width(), 55));}
        else {animation->setEndValue(QRect(0, 0, button->width(), 200));}
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    });

    //Connect for the drop animation
    connect(button, &DatabaseButton::sizeChanged, [=](){
        item->setSizeHint(QSize(button->width(), button->height()));
    });

    //Add to sidebar
    ui->listDatabase->addItem(item);
    ui->listDatabase->setItemWidget(item, button);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::error(QString err)
{
    qWarning() << " Error " << err;
}

void MainWindow::write()
{
    qWarning() << "Write successful";
    BlueDBManager manager;
    //manager.readDatabase("encryptedmessage.txt", "Password");
}

void MainWindow::read(DBParameters param)
{
    qWarning() << "Reading";
    qWarning() << param.DBDecrypted;
    qWarning() << param.DBKeySalt;
    qWarning() << param.DBIterations;
}

//Beautifulness UI related SLOTS

//Uncheck mainbuttons when one of them is checked
void MainWindow::switchButtonStatus()
{
    QPushButton *sender = qobject_cast<QPushButton*>(QObject::sender()); //Retrieve SIGNAL sender

    //Hide all the blue square selectors
    ui->buttonColor_1->setVisible(false);
    ui->buttonColor_2->setVisible(false);
    ui->buttonColor_3->setVisible(false);

    if(ui->buttonOpen == sender)
    {
        //buttonOpen checked, uncheck all others
        ui->buttonCreate->setChecked(false);
        ui->buttonSettings->setChecked(false);

        ui->buttonColor_1->setVisible(true);
    }
    else if(ui->buttonCreate == sender)
    {
        //buttonCreate checked, uncheck all others
        ui->buttonOpen->setChecked(false);
        ui->buttonSettings->setChecked(false);

        ui->buttonColor_2->setVisible(true);
    }
    else if(ui->buttonSettings == sender)
    {
        //buttonSettings checked, uncheck all others
        ui->buttonOpen->setChecked(false);
        ui->buttonCreate->setChecked(false);

        ui->buttonColor_3->setVisible(true);
    }
}
