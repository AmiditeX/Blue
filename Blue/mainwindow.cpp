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
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                          PUBLIC                                                                  //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::displayGeneralError(const QString &err)
{
    BlueDialog *dialog = new BlueDialog();
    QObject::connect(this, SIGNAL(destroyed(QObject*)), dialog, SLOT(deleteLater()));
    QObject::connect(dialog, SIGNAL(closeClicked()), dialog, SLOT(deleteLater()));
    QObject::connect(dialog, SIGNAL(okClicked()), dialog, SLOT(deleteLater()));

    dialog->setTitle(tr("Error"));
    dialog->setMessage(err);
    dialog->show();
    dialog->activateWindow();
}



/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                          PUBLIC                                                                  //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Select the database file to load it afterwards
void MainWindow::openDatabase()
{
    QFileDialog *dialog = new QFileDialog(this, tr("Select the database file"), QDir::currentPath(), "*.blue");
    dialog->setVisible(true); //Display the dialog for the user to select the file

    //Delete the dialog when the URL was retrieved or dialog closed
    QObject::connect(dialog, SIGNAL(urlSelected(QUrl)), dialog, SLOT(deleteLater()));

    //Return database path to loadDatabse()
    QObject::connect(dialog, SIGNAL(urlSelected(QUrl)), this, SLOT(loadDatabase(QUrl)));
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
