#include "dbwemailfield.h"
#include "ui_dbwemailfield.h"

DBWEmailField::DBWEmailField(std::shared_ptr<AbstractDataBaseItem> item) : ui(new Ui::DBWEmailField), _item(item)
{
    ui->setupUi(this);
}

DBWEmailField::~DBWEmailField()
{
    delete ui;
}
