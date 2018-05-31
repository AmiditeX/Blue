#include "dbnamefield.h"
#include <QDebug>

DBNameField::DBNameField()
{
    setID("DBNameField");
}

DBNameField::DBNameField(const QJsonObject &obj)
{
    //Retrieve name
    _name = obj.value("Name").toString();
    _isExpirable = obj.value("IsExpirable").toBool();
    _expires = QDateTime::fromString(obj.value("DateTime").toString());
    setID(obj.value("ID").toString());
    setRow(obj.value("Row").toInt());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QString DBNameField::getValue() const
{
    return _name;
}

void DBNameField::setValue(const QString &value)
{
    _name = value;
}

QJsonObject DBNameField::toJson() const
{
    QJsonObject obj;
    obj.insert("Name", _name);
    obj.insert("IsExpirable", _isExpirable);
    obj.insert("DateTime", _expires.toString());
    obj.insert("ID", getID());
    obj.insert("Row", getRow());
    return obj;
}

void DBNameField::setExpireDate(const QDateTime &datetime)
{
    _expires = datetime;
}

QDateTime DBNameField::getExpireDate() const
{
    return _expires;
}

void DBNameField::setExpirable(bool isExperiable)
{
    _isExpirable = isExperiable;
}

bool DBNameField::isExpirable() const
{
    return _isExpirable;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
