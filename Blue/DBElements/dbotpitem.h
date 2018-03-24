#ifndef DBOTPITEM_H
#define DBOTPITEM_H

#include <QDateTime>
#include <QJsonObject>
#include "abstractdatabaseitem.h"

class DBOtpItem : public AbstractDataBaseItem
{
    
public:
    DBOtpItem();
    DBOtpItem(const QJsonObject &obj);
    
    QString getValue() const override;
    QJsonObject toJson() const override;

    void setExpireDate(const QDateTime &datetime);
    QDateTime getExpireDate() const;

    void setExpirable(bool isExperiable);
    bool isExpirable() const;

    void setSeed(const QString &seed);

private:
    QString _seed;
    QString _otpValue;
    QDateTime _expires = QDateTime(QDate(2000,1,1));
    bool _isExpirable = false;
    
    
};

#endif // DBOTPITEM_H
