#include "databaseopener.h"
#include "ui_databaseopener.h"

DatabaseOpener::DatabaseOpener(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseOpener)
{
    ui->setupUi(this);
}

DatabaseOpener::~DatabaseOpener()
{
    delete ui;
}
