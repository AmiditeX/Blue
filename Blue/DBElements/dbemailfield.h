#ifndef DBEMAILFIELD_H
#define DBEMAILFIELD_H

#include <QJsonObject>
#include <QDateTime>
#include "abstractdatabaseitem.h"

class DBEmailField : public AbstractDataBaseItem
{

public:
    DBEmailField();
    DBEmailField(const QJsonObject &obj);

    QString getValue() const override;
    void setValue(const QString &value);
    QJsonObject toJson() const override;

    void setExpireDate(const QDateTime &datetime);
    QDateTime getExpireDate() const;

    void setExpirable(bool isExperiable);
    bool isExpirable() const;

    void setCheckEmail(bool check);
    bool isCheckEmail() const;

private:
    QString _email;
    QDateTime _expires = QDateTime(QDate(2000,1,1));
    bool _isExpirable = false;
    bool _checkEmail = false;

};

#endif // DBEMAILFIELD_H
