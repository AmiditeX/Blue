#include "dbwcontainers.h"
#include "ui_dbwcontainers.h"

#include <QDebug>

DBWContainers::DBWContainers(QWidget *parent, std::shared_ptr<DBContainers> containerPointer, QListWidgetItem *item) : QWidget(parent),
    ui(new Ui::DBWContainers), _dbContainer(containerPointer), _item(item)
{
    ui->setupUi(this);

    std::vector<std::shared_ptr<AbstractDataBaseItem>> itemList = _dbContainer->returnItemList();

    //Create all the items and store them in an array
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        QWidget* w = createItem(itemList.at(i)->getID(), itemList.at(i));
        _widgetList.push_back(w);
        w->hide();
    }

    QObject::connect(ui->containerButton, SIGNAL(toggled(bool)), this, SIGNAL(widgetClicked(bool)));
    setGeometry(0, 0, width(), 50);

    ui->containerButton->setText(containerPointer->getTitle());
    ui->containerButton->setStyleSheet("QPushButton { border:0px; " + containerPointer->getColor() + " " +
                                       containerPointer->getTextColor() + " font-weight: bold }");

    QObject::connect(ui->close, SIGNAL(clicked(bool)), this, SLOT(removeContainer()));

    ui->close->setVisible(false);
    ui->edit->setVisible(false);

    creator = new ContainerCreator(this);
    creator->setVisible(false);
    creator->setModify();
    QObject::connect(creator, SIGNAL(okPressed()), this, SLOT(editContainer()));
    connect(ui->edit, &QPushButton::clicked, [=](){
        creator->setVisible(true);
        creator->setTitle(ui->containerButton->text());
        QStringList exp = ui->containerButton->styleSheet().split(";");
        creator->setColor(exp.at(1));
        creator->setTitleColor(exp.at(2));
    });
}

//Factory
QWidget* DBWContainers::createItem(const QString &ID, std::shared_ptr<AbstractDataBaseItem> item)
{
    if(ID == "DBEmailField")
    {
        return new DBWEmailField(this, item);
    }
    else if(ID == "DBNameField")
    {
        return new DBWNameField(this, item);
    }
    else if(ID == "DBOtpItem")
    {
        return new DBWOtpItem(this, item);
    }
    else if(ID == "DBPasswordField")
    {
        return new DBWPasswordField(this, item);
    }
    else
    {
        throw std::runtime_error("Invalid type was provided in DBWContainers item factory");
    }
}

//Max heighth of the widget
int DBWContainers::getMaxValue()
{
    return _maxValue;
}

//Resize event, emit signal
void DBWContainers::resizeEvent(QResizeEvent *event)
{
    (void) event;
    emit sizedChanged();
}

//Return UI container
QListWidgetItem* DBWContainers::returnItem()
{
    return _item;
}

void DBWContainers::enterEvent(QEvent *e)
{
    (void)e;
    ui->close->setVisible(true);
    ui->edit->setVisible(true);
}

void DBWContainers::leaveEvent(QEvent *e)
{
    (void)e;
    ui->close->setVisible(false);
    ui->edit->setVisible(false);
}

//Remove a container from UI and structure
void DBWContainers::removeContainer()
{
    BlueDialog *dialog = new BlueDialog(this);
    dialog->setTitle(tr("Deleting a container"));
    dialog->setMessage(tr("Are you sure you want to remove this container ?"));
    dialog->show();

    connect(dialog, &BlueDialog::closeClicked, [=](){
        dialog->hide();
        dialog->deleteLater();
    });

    connect(dialog, &BlueDialog::okClicked, [=](){ //Delete the container from the connected structure, deleting UI
        emit pendingDelete(_dbContainer);
    });
}

//Edit the container properties
void DBWContainers::editContainer()
{
    _dbContainer->setColor(creator->returnParams().colorBackground);
    _dbContainer->setTitle(creator->returnParams().name);
    _dbContainer->setTextColor(creator->returnParams().colorText);

    ui->containerButton->setText(_dbContainer->getTitle());
    ui->containerButton->setStyleSheet("QPushButton { border:0px; " + _dbContainer->getColor() + " " +
                                       _dbContainer->getTextColor() + " font-weight: bold }");

    creator->clear();
    qWarning() << "EDIT";
    emit modified();
}

DBWContainers::~DBWContainers()
{
    delete ui;
}
