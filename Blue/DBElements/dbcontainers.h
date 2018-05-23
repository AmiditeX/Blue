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
#include "spdlog/spdlog.h"

class DBContainers
{

public:
    DBContainers();
    DBContainers(const QJsonObject &obj);

    //Convert whole containers to a JSON Object
    QJsonObject toJson() const;

    //Add and remove items to the containers
    std::shared_ptr<AbstractDataBaseItem> addItem(const QString &ID);
    void removeItem(std::shared_ptr<AbstractDataBaseItem> ptr);

    //Return
    std::vector<std::shared_ptr<AbstractDataBaseItem>> returnItemList();

    //Special tags
    QString getTitle();
    void setTitle(const QString &title);

    QString getColor();
    void setColor(const QString &color);

    QString getTextColor();
    void setTextColor(const QString &color);

protected:
    std::shared_ptr<AbstractDataBaseItem> createItem(const QString &ID);
    std::shared_ptr<AbstractDataBaseItem> createItem(const QString &ID, const QJsonObject &doc);


private:
    std::vector<std::shared_ptr<AbstractDataBaseItem>> _itemList;
    QString _title;
    QString _color;
    QString _colorText;

};

#endif // DBCONTAINERS_H
