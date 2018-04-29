#include "dbwcontainers.h"
#include "ui_dbwcontainers.h"

#include <QDebug>

DBWContainers::DBWContainers(QWidget *parent, std::shared_ptr<DBContainers> containerPointer) : QWidget(parent),
    ui(new Ui::DBWContainers), _dbContainer(containerPointer)
{
    ui->setupUi(this);

    std::vector<std::shared_ptr<AbstractDataBaseItem>> itemList = _dbContainer->returnItemList();

    //Create all the items and store them in an array
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        _widgetList.push_back(createItem(itemList.at(i)->getID(), itemList.at(i)));
    }
}

AbstractDBWidget* DBWContainers::createItem(const QString &ID, std::shared_ptr<AbstractDataBaseItem> item)
{
    if(ID == "DBEmailField")
    {
        qWarning() << "1";
        return new DBWEmailField(this, item);
    }
    else if(ID == "DBNameField")
    {
        qWarning() << "2";
        return new DBWNameField(this, item);
    }
    else if(ID == "DBOtpItem")
    {
        qWarning() << "3";
        return new DBWOtpItem(this, item);
    }
    else if(ID == "DBPasswordField")
    {
        qWarning() << "4";
        return new DBWPasswordField(this, item);
    }
    else
    {
        throw std::runtime_error("Invalid type was provided in DBWContainers item factory");
    }
}

DBWContainers::~DBWContainers()
{
    delete ui;
    qWarning() << "DBWContainers destructor called";
}
