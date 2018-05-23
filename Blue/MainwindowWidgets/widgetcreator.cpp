#include "widgetcreator.h"
#include "ui_widgetcreator.h"

WidgetCreator::WidgetCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WidgetCreator)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    QObject::connect(ui->close, SIGNAL(clicked(bool)), this, SLOT(hide()));
    connect(ui->add, &QPushButton::clicked, [=](){
        if(!currentItem.isEmpty())
           { emit okClicked(currentItem); hide(); }
    });

    std::vector<std::pair<QString, QString>> widgetTypeList {
        {"DBNameField", tr("Name field")},
        {"DBEmailField", tr("Email field")},
        {"DBOtpItem", tr("One-Time Password")},
        {"DBPasswordField", tr("Password field")}
    };

    for(unsigned int i = 0; i < widgetTypeList.size(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem();
        QLabel *widgetName = new QLabel(this);
        widgetName->setStyleSheet("color: rgb(238, 238, 236); font-weight: bold");

        std::pair<QString, QString> &pair = widgetTypeList.at(i);
        widgetName->setText(pair.second);

        ui->widgetList->addItem(item);
        ui->widgetList->setItemWidget(item, widgetName);
    }

    connect(ui->widgetList, &QListWidget::itemClicked, [=](QListWidgetItem *w){
        QLabel *text = static_cast<QLabel*>(ui->widgetList->itemWidget(w));
        ui->currentSelection->setText(text->text());

        for(std::pair<QString, QString> pair : widgetTypeList)
        {
            if(pair.second == text->text())
            {
                currentItem = pair.first;
                break;
            }
        }
    });
}

WidgetCreator::~WidgetCreator()
{
    for(int i = 0; i < ui->widgetList->count(); i++)
    {
        QListWidgetItem *item = ui->widgetList->item(i);
        ui->widgetList->removeItemWidget(item); //Remove from QListWidget
        delete item; //Remove i completely from the list (see QT doc)
    }
    ui->widgetList->clear();

    delete ui;
}
