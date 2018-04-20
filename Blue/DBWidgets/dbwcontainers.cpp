#include "dbwcontainers.h"
#include "ui_dbwcontainers.h"

DBWContainers::DBWContainers(std::shared_ptr<DBContainers> containerPointer) : ui(new Ui::DBWContainers), _dbContainer(containerPointer)
{
    ui->setupUi(this);

    std::vector<std::shared_ptr<AbstractDataBaseItem>> itemList = _dbContainer->returnItemList();

    //Create all the items and store them in an array
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        _widgetList.push_back(createItem(itemList.at(i)->getID(), itemList.at(i)));
    }
}

std::shared_ptr<AbstractDBWidget> DBWContainers::createItem(const QString &ID, std::shared_ptr<AbstractDataBaseItem> item)
{
    if(ID == "DBEmailField")
    {
        return std::make_shared<DBWEmailField>(item);
    }
    else if(ID == "DBNameField")
    {
        return std::make_shared<DBWNameField>(item);
    }
    else if(ID == "DBOtpItem")
    {
        return std::make_shared<DBWOtpItem>(item);
    }
    else if(ID == "DBPasswordField")
    {
        return std::make_shared<DBWPasswordField>(item);
    }
    else
    {
        throw std::runtime_error("Invalid type was provided in DBWContainers item factory");
    }
}

DBWContainers::~DBWContainers()
{
    delete ui;
}
