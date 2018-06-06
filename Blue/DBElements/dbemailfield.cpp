#include "dbemailfield.h"

DBEmailField::DBEmailField()
{
    setID("DBEmailField");
}

DBEmailField::DBEmailField(const QJsonObject &obj)
{
    //Retrieve email and bool
    _email = obj.value("Email").toString();
    _isExpirable = obj.value("IsExpirable").toBool();
    _expires = QDateTime::fromString(obj.value("DateTime").toString());
    _checkEmail = obj.value("CheckEmail").toBool();
    setID(obj.value("ID").toString());
    setRow(obj.value("Row").toInt());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QString DBEmailField::getValue() const
{
    return _email;
}

void DBEmailField::setValue(const QString &value)
{
    _email = value;
}

QJsonObject DBEmailField::toJson() const
{
    QJsonObject obj;
    obj.insert("Email", _email);
    obj.insert("IsExpirable", _isExpirable);
    obj.insert("DateTime", _expires.toString());
    obj.insert("CheckEmail", _checkEmail);
    obj.insert("ID", getID());
    obj.insert("Row", getRow());
    return obj;
}

void DBEmailField::setExpireDate(const QDateTime &datetime)
{
    _expires = datetime;
}

QDateTime DBEmailField::getExpireDate() const
{
    return _expires;
}

void DBEmailField::setExpirable(bool isExperiable)
{
    _isExpirable = isExperiable;
}

bool DBEmailField::isExpirable() const
{
    return _isExpirable;
}

void DBEmailField::setCheckEmail(bool check)
{
    _checkEmail = check;
}

bool DBEmailField::isCheckEmail() const
{
    return _checkEmail;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
