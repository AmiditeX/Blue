#include "databasecreator.h"
#include "ui_databasecreator.h"

DatabaseCreator::DatabaseCreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseCreator)
{
    ui->setupUi(this);
}

DatabaseCreator::~DatabaseCreator()
{
    delete ui;
}
