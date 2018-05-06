#include "bluewidget.h"
#include "ui_bluewidget.h"

#include <QDebug>

BlueWidget::BlueWidget(std::shared_ptr<BlueDatabase> databasePointer) : ui(new Ui::BlueWidget), _dataBase(databasePointer)
{
    ui->setupUi(this);

    std::vector<std::shared_ptr<DBContainers>> containerList = _dataBase->returnContainerList();

    //Create container widgets from DBContainers, store in an array
    for(unsigned int i = 0; i < containerList.size(); i++)
    {
        _containers.push_back(new DBWContainers(this, containerList.at(i)));
    }
    qWarning() << _dataBase.get();
}

BlueWidget::~BlueWidget()
{
    delete ui;
    qWarning() << "BlueWidget destructor called";
}
