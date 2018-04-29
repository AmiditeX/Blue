#include "dbwpasswordfield.h"
#include "ui_dbwpasswordfield.h"

DBWPasswordField::DBWPasswordField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : QWidget(parent),
    ui(new Ui::DBWPasswordField), _item(item)
{
    ui->setupUi(this);
}

DBWPasswordField::~DBWPasswordField()
{
    delete ui;
}
