#ifndef DBCONTAINERS_H
#define DBCONTAINERS_H

#include <QVector>
#include <QJsonObject>
#include <QJsonArray>
#include <vector>
#include <memory>
#include "abstractdatabaseitem.h"
#include "dbemailfield.h"
#include "dbnamefield.h"
#include "dbotpitem.h"
#include "dbpasswordfield.h"

class DBContainers
{

public:
    DBContainers(const QJsonObject &obj);

    QJsonObject toJson() const;



private:
    std::vector<std::shared_ptr<AbstractDataBaseItem>> _itemList;

};

#endif // DBCONTAINERS_H
