#include "dbwnamefield.h"
#include "ui_dbwnamefield.h"

DBWNameField::DBWNameField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBWNameField)
{
    ui->setupUi(this);
}

DBWNameField::~DBWNameField()
{
    delete ui;
}
