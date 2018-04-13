#include "dbwcontainers.h"
#include "ui_dbwcontainers.h"

DBWContainers::DBWContainers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBWContainers)
{
    ui->setupUi(this);
}

DBWContainers::~DBWContainers()
{
    delete ui;
}
