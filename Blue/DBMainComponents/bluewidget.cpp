#include "bluewidget.h"
#include "ui_bluewidget.h"

BlueWidget::BlueWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlueWidget)
{
    ui->setupUi(this);
}

BlueWidget::~BlueWidget()
{
    delete ui;
}
