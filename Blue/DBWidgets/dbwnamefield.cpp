#include "dbwnamefield.h"
#include "ui_dbwnamefield.h"

DBWNameField::DBWNameField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : AbstractDBWidget(parent),
    ui(new Ui::DBWNameField), _item(item)
{
    ui->setupUi(this);

    setHeightParam(45, height());

    connect(ui->modify, &QPushButton::toggled, [=](bool toggled){
        emit expand(toggled);
    });

    setGeometry(0, 0, width(), 45);
}

//Resize event, emit signal
void DBWNameField::resizeEvent(QResizeEvent *event)
{
    (void) event;
    emit sizeChanged();
}

DBWNameField::~DBWNameField()
{
    delete ui;
}
