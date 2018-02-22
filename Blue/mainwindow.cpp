#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << AESModule::integrityCheck(); //TODO REACTIVATE HEXADECIMAL INTEGRITY CHECK
    //BlueDBManager db;
}

MainWindow::~MainWindow()
{
    delete ui;
}
