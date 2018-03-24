#include "dbotpitem.h"

DBOtpItem::DBOtpItem()
{
    setID("DBOtpItem");
}

DBOtpItem::DBOtpItem(const QJsonObject &obj)
{
    //Retrieve seed
    _seed = obj.value("Seed").toString();
    _isExpirable = obj.value("IsExpirable").toBool();
    _expires = QDateTime::fromString(obj.value("DateTime").toString());
    setID(obj.value("ID").toString());
    setRow(obj.value("Row").toInt());

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QString DBOtpItem::getValue() const
{
    return _otpValue;
}

QJsonObject DBOtpItem::toJson() const
{
    QJsonObject obj;
    obj.insert("Seed", _seed);
    obj.insert("IsExpirable", _isExpirable);
    obj.insert("DateTime", _expires.toString());
    obj.insert("ID", getID());
    obj.insert("Row", getRow());
    return obj;
}

void DBOtpItem::setExpireDate(const QDateTime &datetime)
{
    _expires = datetime;
}

QDateTime DBOtpItem::getExpireDate() const
{
    return _expires;
}

void DBOtpItem::setExpirable(bool isExperiable)
{
    _isExpirable = isExperiable;
}

bool DBOtpItem::isExpirable() const
{
    return _isExpirable;
}

void DBOtpItem::setSeed(const QString &seed)
{
    _seed = seed;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
