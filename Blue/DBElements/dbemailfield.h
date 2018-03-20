#ifndef DBEMAILFIELD_H
#define DBEMAILFIELD_H

#include <QJsonObject>
#include <QDateTime>
#include "abstractdatabaseitem.h"

class DBEmailField : public AbstractDataBaseItem
{

public:
    DBEmailField(const QJsonObject &obj);

    QString getValue() const override;
    void setValue(const QString &value);
    QJsonObject toJson() const override;

    void setExpireDate(const QDateTime &datetime);
    QDateTime getExpireDate() const;

    void setExpirable(bool isExperiable);
    bool isExpirable() const;

private:
    QString _email;
    QDateTime _expires;
    bool _isExpirable;

};

#endif // DBEMAILFIELD_H