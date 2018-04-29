#include "dbwnamefield.h"
#include "ui_dbwnamefield.h"

DBWNameField::DBWNameField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : QWidget(parent),
    ui(new Ui::DBWNameField), _item(item)
{
    ui->setupUi(this);
}

DBWNameField::~DBWNameField()
{
    delete ui;
}
