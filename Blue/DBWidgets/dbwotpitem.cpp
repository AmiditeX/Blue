#include "dbwotpitem.h"
#include "ui_dbwotpitem.h"

DBWOtpItem::DBWOtpItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBWOtpItem)
{
    ui->setupUi(this);
}

DBWOtpItem::~DBWOtpItem()
{
    delete ui;
}
