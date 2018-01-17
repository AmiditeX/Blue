#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AESModule::integrityCheck();
    BlueDBManager db;
}

MainWindow::~MainWindow()
{
    delete ui;
}
