#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include "BlueCrypto/blueiointerface.h"
#include "DBMainComponents/bluedbmanager.h"
#include <iostream>
#include <QPushButton>

#include <QElapsedTimer> //to remove


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

    for(int i = 0; i < 1; i++)
    {
        QElapsedTimer timer;
        timer.start();
        qWarning() << AESModule::integrityCheck();

        manager = new BlueDBManager();
        connect(manager, SIGNAL(createSignal(BlueWidget*)), this, SLOT(displayWidget(BlueWidget*)));
        manager->createNewDatabase("Testdb.txt", "password", 0, 1);
        //manager->writeDatabaseObject();
        qWarning() << "Milli " << timer.elapsed();
    }
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

    if(ui->buttonOpen == sender)
    {
        //buttonOpen checked, uncheck all others
        ui->buttonCreate->setChecked(false);
        ui->buttonSettings->setChecked(false);
    }
    else if(ui->buttonCreate == sender)
    {
        //buttonCreate checked, uncheck all others
        ui->buttonOpen->setChecked(false);
        ui->buttonSettings->setChecked(false);
    }
    else if(ui->buttonSettings == sender)
    {
        //buttonSettings checked, uncheck all others
        ui->buttonOpen->setChecked(false);
        ui->buttonCreate->setChecked(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
