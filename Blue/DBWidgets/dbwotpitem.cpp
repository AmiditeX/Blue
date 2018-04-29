#include "dbwotpitem.h"
#include "ui_dbwotpitem.h"

DBWOtpItem::DBWOtpItem(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : QWidget(parent),
    ui(new Ui::DBWOtpItem),_item(item)
{
    ui->setupUi(this);
}

DBWOtpItem::~DBWOtpItem()
{
    delete ui;
}
