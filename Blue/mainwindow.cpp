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

    //Database Opener
    opener = new DatabaseOpener(this);
    QObject::connect(opener, SIGNAL(openPressed()), this, SLOT(openerReturn()));
    QObject::connect(opener, SIGNAL(closePressed()), this, SLOT(openerClose()));
    QObject::connect(opener, SIGNAL(closePressed()), opener, SLOT(clear()));
    opener->setVisible(false);
    CustomShadowEffect *bodyShadow = new CustomShadowEffect(this);
    bodyShadow->setBlurRadius(50.0);
    bodyShadow->setDistance(10.0);
    bodyShadow->setColor(QColor(0, 0, 0, 150));
    opener->setGraphicsEffect(bodyShadow);
    opener->move(260, 30);
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

        if(!dir.exists(opener->getKey()))
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

    QFile keyFile(opener->getKey());
    if(!keyFile.open(QFile::ReadOnly))
    {
        displayGeneralError(tr("Couldn't open key file"));
        return;
    }

    QString key = keyFile.readAll();

    emit openingRequest(opener->getMaster() + key, opener->getFilePath());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Open a database given its path, handle UI to display database buttons
void MainWindow::loadDatabase(const QUrl &url)
{
    qWarning() << url.path();
}

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

void MainWindow::displayWidget(BlueWidget *w)
{
    qWarning() << "Displaying w";

    manager->writeDatabaseObject();
    ui->databaseTab->addTab(w, "BAR");
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

MainWindow::~MainWindow()
{
    qWarning() << "DELETING MAINWINDOW";
    delete ui;
}
