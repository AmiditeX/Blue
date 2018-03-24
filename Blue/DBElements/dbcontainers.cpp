#include "dbcontainers.h"

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
        if(ID == "DBEmailField")
        {
            _itemList.push_back(std::move(std::make_shared<DBEmailField>(currentItem)));
        }
        else if(ID == "DBNameField")
        {
            _itemList.push_back(std::move(std::make_shared<DBNameField>(currentItem)));
        }
        else if(ID == "DBOtpItem")
        {
            _itemList.push_back(std::move(std::make_shared<DBOtpItem>(currentItem)));
        }
        else if(ID == "DBPasswordField")
        {
            _itemList.push_back(std::move(std::make_shared<DBPasswordField>(currentItem)));
        }
        else
        {
            throw std::runtime_error("Invalid type was provided in DBContainers constructor");
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    return obj;
}
