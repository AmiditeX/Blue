#include "dbwpasswordfield.h"
#include "ui_dbwpasswordfield.h"

DBWPasswordField::DBWPasswordField(std::shared_ptr<AbstractDataBaseItem> item) : ui(new Ui::DBWPasswordField), _item(item)
{
    ui->setupUi(this);
}

DBWPasswordField::~DBWPasswordField()
{
    delete ui;
}
