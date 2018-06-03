#include "dbwotpitem.h"
#include "ui_dbwotpitem.h"

#include <QDateTime>
#include "Tools/libcppotp/otp.h"

DBWOtpItem::DBWOtpItem(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : AbstractDBWidget(parent),
    ui(new Ui::DBWOtpItem), _item(item)
{
    ui->setupUi(this);
}

void DBWOtpItem::calculateTotp()
{
    CppTotp::Bytes::ByteString key = CppTotp::Bytes::fromUnpaddedBase32(_totpKey.toStdString());
    std::uint32_t result = CppTotp::totp(key, QDateTime::currentSecsSinceEpoch(), 0, 30, 6);


}

DBWOtpItem::~DBWOtpItem()
{
    delete ui;
}
