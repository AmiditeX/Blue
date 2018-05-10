#include "bluedatabase.h"
#include <QJsonDocument>
#include <QDebug>

BlueDatabase::BlueDatabase(const DBParameters &param)
{
    //Retrieve settings and content of the database
    _dbData = param;

    //Construct all the containers
    QJsonObject dbObject = _dbData.DBDecrypted.object(); //Retrieve DB object
    QJsonArray containerArray = dbObject.value("DBContainers").toArray();

    for(int i = 0; i < containerArray.size(); i++)
    {
        //Create a new container and construct it with the matching JsonObject containing the widgets
        _containerList.push_back(std::move(std::make_shared<DBContainers>(containerArray.at(i).toObject())));
    }

    _dbData.DBDecrypted = QJsonDocument(); //Remove useless data to spare memory
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const DBParameters BlueDatabase::getParameters() const
{
    return _dbData;
}

void BlueDatabase::setParameters(const DBParameters &param)
{
    _dbData.DBIterations = param.DBIterations;
    _dbData.DBStretchTime = param.DBStretchTime;
    _dbData.DBPassword = param.DBPassword;
    _dbData.DBPath = param.DBPath;
}

const QJsonDocument BlueDatabase::getJsonDocument() const
{
    //Retrieve all the containers in JSON and push them in a list
    QJsonArray containerArray;
    for(unsigned int i = 0; i < _containerList.size() ; i++)
    {
        QJsonObject currentContainer = _containerList[i]->toJson();
        containerArray.push_back(currentContainer);
    }

    QJsonObject dbObject;
    dbObject.insert("DBContainers", containerArray);

    return QJsonDocument(dbObject);
}

std::shared_ptr<DBContainers> BlueDatabase::addContainer()
{
    std::shared_ptr<DBContainers> containerPtr = std::make_shared<DBContainers>();
    _containerList.push_back(containerPtr);

    return containerPtr;
}

void BlueDatabase::removeContainer(std::shared_ptr<DBContainers> ptr)
{
    _containerList.erase(std::remove(_containerList.begin(), _containerList.end(), ptr));
}

std::vector<std::shared_ptr<DBContainers>> BlueDatabase::returnContainerList()
{
    return _containerList;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
