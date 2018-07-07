#include "dbcontainers.h"

#include <algorithm>
#include <QDebug>

DBContainers::DBContainers()
{

}

DBContainers::DBContainers(const QJsonObject &obj)
{
    //Retrieve all items contained in the container in JSON format
    QJsonArray allElements = obj.value("DBItems").toArray();

    //Instanciate each of them and store pointers in a vector
    for(int i = 0; i < allElements.size(); i++)
    {
        //Current item as a JSON array element
        QJsonObject currentItem = allElements[i].toObject();

        //Fetch ID of the item to construct the matching object
        const QString ID = currentItem.value("ID").toString();

        try
        {
            _itemList.push_back(std::move(createItem(ID, currentItem)));
        }
        catch (std::exception &e)
        {
            spdlog::get("LOGGER")->error(e.what());
        }
    }

    //Special tags
    _title = obj.value("Name").toString();
    _color = obj.value("Color").toString();
    _colorText = obj.value("ColorText").toString();
    setRow(obj.value("ContainerRow").toInt());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Convert whole containers to a JSON Object
QJsonObject DBContainers::toJson() const
{
    QJsonArray allElements;

    //Retrieve all items contained in this container in JSON format
    for(unsigned int i = 0; i < _itemList.size(); i++)
    {
        //Store them in an array
        allElements.append(_itemList[i]->toJson());
    }

    //Return the object containing all the elements
    QJsonObject obj;
    obj.insert("DBItems", allElements);
    obj.insert("Name", _title);
    obj.insert("Color", _color);
    obj.insert("ColorText", _colorText);
    obj.insert("ContainerRow", getRow());
    return obj;
}

QString DBContainers::getValue() const
{
    return "Undefined, object is of type DBContainers";
}

std::shared_ptr<AbstractDataBaseItem> DBContainers::addItem(const QString &ID)
{
    try
    {
        std::shared_ptr<AbstractDataBaseItem> newObject = createItem(ID);
        _itemList.push_back(newObject);

        return newObject;
    }
    catch (std::exception &e)
    {
        spdlog::get("LOGGER")->error(e.what());
    }

    return nullptr;
}

void DBContainers::removeItem(std::shared_ptr<AbstractDataBaseItem> ptr)
{
    _itemList.erase(std::remove(_itemList.begin(), _itemList.end(), ptr));
}

std::vector<std::shared_ptr<AbstractDataBaseItem>> DBContainers::returnItemList()
{
    return _itemList;
}

QString DBContainers::getTitle()
{
    return _title;
}

void DBContainers::setTitle(const QString &title)
{
    _title = title;
}

QString DBContainers::getColor()
{
    return _color;
}

void DBContainers::setColor(const QString &color)
{
    _color = color;
}

QString DBContainers::getTextColor()
{
    return _colorText;
}

void DBContainers::setTextColor(const QString &color)
{
    _colorText = color;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PROTECTED                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Create an item without settings
std::shared_ptr<AbstractDataBaseItem> DBContainers::createItem(const QString &ID)
{
    if(ID == "DBEmailField")
    {
        return std::make_shared<DBEmailField>();
    }
    else if(ID == "DBNameField")
    {
        return std::make_shared<DBNameField>();
    }
    else if(ID == "DBOtpItem")
    {
        return std::make_shared<DBOtpItem>();
    }
    else if(ID == "DBPasswordField")
    {
        return std::make_shared<DBPasswordField>();
    }
    else
    {
        throw std::runtime_error("Invalid type was provided in DBContainers item factory");
    }
}

//Create an item given a JSON Object containing its settings
std::shared_ptr<AbstractDataBaseItem> DBContainers::createItem(const QString &ID, const QJsonObject &doc)
{
    if(ID == "DBEmailField")
    {
        return std::make_shared<DBEmailField>(doc);
    }
    else if(ID == "DBNameField")
    {
        return std::make_shared<DBNameField>(doc);
    }
    else if(ID == "DBOtpItem")
    {
        return std::make_shared<DBOtpItem>(doc);
    }
    else if(ID == "DBPasswordField")
    {
        return std::make_shared<DBPasswordField>(doc);
    }
    else
    {
        throw std::runtime_error("Invalid type was provided in DBContainers item factory");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PROTECTED                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
