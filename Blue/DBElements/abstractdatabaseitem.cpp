#include "abstractdatabaseitem.h"

AbstractDataBaseItem::AbstractDataBaseItem()
{

}

AbstractDataBaseItem::~AbstractDataBaseItem()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QString AbstractDataBaseItem::getID() const
{
    return _ID;
}

void AbstractDataBaseItem::setID(const QString &ID)
{
    _ID = ID;
}

int AbstractDataBaseItem::getRow() const
{
    return _row;
}

void AbstractDataBaseItem::setRow(const int &row)
{
    _row = row;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
