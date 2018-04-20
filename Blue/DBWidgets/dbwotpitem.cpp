#include "dbwotpitem.h"
#include "ui_dbwotpitem.h"

DBWOtpItem::DBWOtpItem(std::shared_ptr<AbstractDataBaseItem> item) : ui(new Ui::DBWOtpItem),_item(item)
{
    ui->setupUi(this);
}

DBWOtpItem::~DBWOtpItem()
{
    delete ui;
}
