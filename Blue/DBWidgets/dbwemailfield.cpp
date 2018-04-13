#include "dbwemailfield.h"
#include "ui_dbwemailfield.h"

DBWEmailField::DBWEmailField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBWEmailField)
{
    ui->setupUi(this);
}

DBWEmailField::~DBWEmailField()
{
    delete ui;
}
