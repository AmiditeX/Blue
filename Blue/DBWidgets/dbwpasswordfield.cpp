#include "dbwpasswordfield.h"
#include "ui_dbwpasswordfield.h"

DBWPasswordField::DBWPasswordField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBWPasswordField)
{
    ui->setupUi(this);
}

DBWPasswordField::~DBWPasswordField()
{
    delete ui;
}
