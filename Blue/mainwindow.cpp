#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include "blueiointerface.h"
#include "bluedbmanager.h"
#include <iostream>


#include <QElapsedTimer> //to remove


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 5; i++)
    {
        QElapsedTimer timer;
              timer.start();
        qWarning() << AESModule::integrityCheck();
        qWarning() << "Milli " << timer.elapsed();
    }

    QJsonObject finalObject; //Prepare the file with the database and its metadata
    finalObject.insert("DBField", "HELLO"); //Add the encrypted database
    QJsonDocument finalDoc(finalObject);

    connect(&i, SIGNAL(readCompleted(DBParameters)), this, SLOT(read(DBParameters)));
    connect(&i, SIGNAL(writeCompleted()), this, SLOT(write()));
    connect(&i, SIGNAL(errorSignal(QString)), this, SLOT(error(QString)));
    i.writeFile("encryptedmessage.txt", finalDoc, "Password", 1500, 0);

}

void MainWindow::error(QString err)
{
    qWarning() << " Error " << err;
}

void MainWindow::write()
{
    qWarning() << "Write successful";
    BlueDBManager manager;
    manager.readDatabase("encryptedmessage.txt", "Password");
}

void MainWindow::read(DBParameters param)
{
    qWarning() << "Reading";
    qWarning() << param.DBDecrypted;
    qWarning() << param.DBKeySalt;
    qWarning() << param.DBIterations;
}

MainWindow::~MainWindow()
{
    delete ui;
}
