#include "dbcontainers.h"

DBContainers::DBContainers(const QJsonObject &obj)
{
    //Retrieve all items contained in the container in JSON format
    QJsonArray allElements = obj.value("Items").toArray();

    //Instanciate each of them and store pointers in a QVector
    for(int i = 0; i < allElements.size(); i++)
    {
        //Shared pointer of the new element, owned by DBContainers
        QJsonObject currentItem = allElements[i].toObject();

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
            //If the ID doesn't exist, data is flawed, the item won't be created nor displayed
            //Maybe display warning with ID
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
    obj.insert("Items", allElements);
    return obj;
}
