#ifndef BLUEDATABASE_H
#define BLUEDATABASE_H

#include <QObject>
#include <QJsonDocument>
#include <vector>
#include "DBElements/dbcontainers.h"
#include "BlueCrypto/blueiointerface.h"

class BlueDatabase
{

public:
    BlueDatabase(const DBParameters &param);

    const DBParameters getParameters() const;
    const QJsonDocument getJsonDocument() const;

    std::shared_ptr<DBContainers> addContainer();
    void removeContainer(std::shared_ptr<DBContainers> ptr);
    std::vector<std::shared_ptr<DBContainers>> returnContainerList();


private:
    DBParameters _dbData;
    std::vector<std::shared_ptr<DBContainers>> _containerList;
    
};

#endif // BLUEDATABASE_H
