#include "dbwnamefield.h"
#include "ui_dbwnamefield.h"

DBWNameField::DBWNameField(std::shared_ptr<AbstractDataBaseItem> item) : ui(new Ui::DBWNameField), _item(item)
{
    ui->setupUi(this);
}

DBWNameField::~DBWNameField()
{
    delete ui;
}
