#include "dbpasswordfield.h"

DBPasswordField::DBPasswordField(const QJsonObject &obj)
{
    //Retrieve password
    _password = obj.value("Password").toString();
    _isExpirable = obj.value("IsExpirable").toBool();
    _expires = QDateTime::fromString(obj.value("DateTime").toString());
    setID(obj.value("ID").toInt());
    setRow(obj.value("Row").toInt());

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QString DBPasswordField::getValue() const
{
    return _password;
}

void DBPasswordField::setValue(const QString &value)
{
    _password = value;
}

QJsonObject DBPasswordField::toJson() const
{
    QJsonObject obj;
    obj.insert("Password", _password);
    obj.insert("IsExpirable", _isExpirable);
    obj.insert("DateTime", _expires.toString());
    obj.insert("ID", getID());
    obj.insert("Row", getRow());
    return obj;
}

void DBPasswordField::setExpireDate(const QDateTime &datetime)
{
    _expires = datetime;
}

QDateTime DBPasswordField::getExpireDate() const
{
    return _expires;
}

void DBPasswordField::setExpirable(bool isExperiable)
{
    _isExpirable = isExperiable;
}

bool DBPasswordField::isExpirable() const
{
    return _isExpirable;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
