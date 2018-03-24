#ifndef DBNAMEFIELD_H
#define DBNAMEFIELD_H

#include <QJsonObject>
#include <QDateTime>
#include "abstractdatabaseitem.h"

class DBNameField : public AbstractDataBaseItem
{

public:
    DBNameField();
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
    QDateTime _expires = QDateTime(QDate(2000,1,1));
    bool _isExpirable = false;

};

#endif // DBNAMEFIELD_H
