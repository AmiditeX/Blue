#ifndef DBPASSWORDFIELD_H
#define DBPASSWORDFIELD_H

#include <QJsonObject>
#include <QDateTime>
#include "abstractdatabaseitem.h"

class DBPasswordField : public AbstractDataBaseItem
{

public:
    DBPasswordField();
    DBPasswordField(const QJsonObject &obj);

    QString getValue() const override;
    void setValue(const QString &value);
    QJsonObject toJson() const override;

    void setExpireDate(const QDateTime &datetime);
    QDateTime getExpireDate() const;

    void setExpirable(bool isExperiable);
    bool isExpirable() const;

private:
    QString _password;
    QDateTime _expires = QDateTime(QDate(2000,1,1));
    bool _isExpirable = false;

};

#endif // DBPASSWORDFIELD_H
