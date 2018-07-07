#ifndef ABSTRACTDATABASEITEM_H
#define ABSTRACTDATABASEITEM_H

#include <QObject>
#include <QJsonObject>
#include <memory>
#include "abstractdatabaseitem.h"

class AbstractDataBaseItem
{

public:
    AbstractDataBaseItem();
    virtual ~AbstractDataBaseItem();

    virtual QString getID() const;
    virtual void setID(const QString &ID);
    virtual int getRow() const;
    virtual void setRow(const int &row);
    virtual QString getValue() const = 0;
    virtual QJsonObject toJson() const = 0;

private:
    QString _ID; //ID of the Item to determine which type it is constructed as
    int _row = 0; //Row of the Item inside its container

};

#endif // ABSTRACTDATABASEITEM_H
