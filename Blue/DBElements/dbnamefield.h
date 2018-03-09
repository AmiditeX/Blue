#ifndef DBNAMEFIELD_H
#define DBNAMEFIELD_H

#include <QJsonObject>
#include <QDateTime>
#include "abstractdatabaseitem.h"

class DBNameField : public AbstractDataBaseItem
{

public:
    DBNameField(const QJsonObject &obj);

    QString getValue() const override;
    void setValue(const QString &value);
    QJsonObject toJson() const override;

    void setExpireDate(const QDateTime &datetime);
    QDateTime getExpireDate() const;

    void setExpirable(bool isExperiable);
    bool isExpirable() const;

private:
    QString _name;
    QDateTime _expires;
    bool _isExpirable;

};

#endif // DBNAMEFIELD_H
