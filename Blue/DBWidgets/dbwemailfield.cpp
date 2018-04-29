#include "dbwemailfield.h"
#include "ui_dbwemailfield.h"

DBWEmailField::DBWEmailField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : QWidget(parent),
    ui(new Ui::DBWEmailField), _item(item)
{
    ui->setupUi(this);
}

DBWEmailField::~DBWEmailField()
{
    delete ui;
}
