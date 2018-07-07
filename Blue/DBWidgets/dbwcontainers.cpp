#include "dbwcontainers.h"
#include "ui_dbwcontainers.h"

DBWContainers::DBWContainers(QWidget *parent, std::shared_ptr<DBContainers> containerPointer, QListWidgetItem *item) : AbstractDBWidget(parent),
    ui(new Ui::DBWContainers), _dbContainer(containerPointer), _item(item)
{
    ui->setupUi(this);

    std::vector<std::shared_ptr<AbstractDataBaseItem>> itemList = _dbContainer->returnItemList();

    //Create all the items and store them in an array
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        try
        {
            QWidget* widget;

            widget = createItem(itemList.at(i)->getID(), itemList.at(i));
            _widgetList.push_back(widget);

            //Display the widget
            QListWidgetItem *listItem = new QListWidgetItem();
            listItem->setSizeHint(widget->size());
            ui->widgetList->addItem(listItem);
            ui->widgetList->setItemWidget(listItem, widget);

            //Retrieve abstract to connect signals
            AbstractDBWidget *abstract = dynamic_cast<AbstractDBWidget*>(widget);

            //New widget added, expand both widget display and container
            unsigned int currentSize = getTotalItemSize();
            ui->widgetList->setGeometry(ui->widgetList->x(), ui->widgetList->y(), width(), currentSize);
            setGeometry(0, 0, width(), 50 + currentSize);

            //Expand the widget
            connect(abstract, &AbstractDBWidget::expand, [=](bool drop){
                QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
                animation->setDuration(100);
                animation->setStartValue(widget->geometry());
                if(drop) {animation->setEndValue(QRect(0, 0, widget->width(), abstract->getMin()));}
                else {animation->setEndValue(QRect(0, 0, widget->width(), abstract->getMax()));}
                animation->start(QAbstractAnimation::DeleteWhenStopped);
            });

            //Connect for the drop animation
            connect(abstract, &AbstractDBWidget::sizeChanged, [this , listItem, widget](){
                listItem->setSizeHint(QSize(widget->width(), widget->height()));

                unsigned int currentSize = getTotalItemSize();
                ui->widgetList->setGeometry(ui->widgetList->x(), ui->widgetList->y(), width(), currentSize);
                setGeometry(0, 0, width(), 50 + currentSize);
            });

            //Connect to remove the widget from the display and delete it
            connect(abstract, &AbstractDBWidget::remove, [=](std::shared_ptr<AbstractDataBaseItem> item){
                ui->widgetList->removeItemWidget(listItem);
                delete listItem;

                _dbContainer->removeItem(item);
                _widgetList.erase(std::remove(_widgetList.begin(), _widgetList.end(), widget), _widgetList.end()); //Remove UI from list
                widget->deleteLater(); //Delete container UI

                unsigned int currentSize = getTotalItemSize();
                ui->widgetList->setGeometry(ui->widgetList->x(), ui->widgetList->y(), width(), currentSize);
                setGeometry(0, 0, width(), 50 + currentSize);

                emit modified();
            });

            connect(abstract, &AbstractDBWidget::modified, [=](){
                emit modified();
            });

            connect(abstract, &AbstractDBWidget::changePos, [=](bool up){
                handleRow(up, listItem);
            });
        }
        catch (std::exception &e)
        {
            spdlog::get("LOGGER")->error(e.what());
        }
    }

    QObject::connect(ui->containerButton, SIGNAL(toggled(bool)), this, SIGNAL(widgetClicked(bool)));
    QObject::connect(ui->close, SIGNAL(clicked(bool)), this, SLOT(removeContainer()));


    ui->containerButton->setText(containerPointer->getTitle());
    ui->containerButton->setStyleSheet("QPushButton { border:0px; " + containerPointer->getColor() + " " +
                                       containerPointer->getTextColor() + " font-weight: bold }");

    ui->close->setVisible(false);
    ui->edit->setVisible(false);
    ui->add->setVisible(false);
    ui->up->setVisible(false);
    ui->down->setVisible(false);

    connect(ui->up, &QPushButton::clicked, [=](){
        emit up();
    });

    connect(ui->down, &QPushButton::clicked, [=](){
        emit down();
    });

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

    widgetCreator = new WidgetCreator(this);
    widgetCreator->setVisible(false);
    QObject::connect(widgetCreator, SIGNAL(okClicked(QString)), this, SLOT(addWidget(QString)));
    connect(ui->add, &QPushButton::clicked, [=](){
        widgetCreator->setVisible(true);
    });

    setGeometry(0, 0, width(), 50);
    emit widgetClicked(true);
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
    ui->add->setVisible(true);
    ui->up->setVisible(true);
    ui->down->setVisible(true);
}

void DBWContainers::leaveEvent(QEvent *e)
{
    (void)e;
    ui->close->setVisible(false);
    ui->edit->setVisible(false);
    ui->add->setVisible(false);
    ui->up->setVisible(false);
    ui->down->setVisible(false);
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
    emit modified();
}

//Add a new widget to the displayer
void DBWContainers::addWidget(const QString &widgetName)
{
    std::shared_ptr<AbstractDataBaseItem> item = _dbContainer->addItem(widgetName);
    QWidget *widget;

    try
    {
        widget = createItem(widgetName, item);
        _widgetList.push_back(widget);
    }
    catch (std::exception &e)
    {
        spdlog::get("LOGGER")->error(e.what());
        return;
    }

    //Display the widget
    QListWidgetItem *listItem = new QListWidgetItem();
    listItem->setSizeHint(widget->size());
    ui->widgetList->addItem(listItem);
    ui->widgetList->setItemWidget(listItem, widget);

    //Retrieve abstract to connect signals
    AbstractDBWidget *abstract = dynamic_cast<AbstractDBWidget*>(widget);

    //New widget added, expand both widget display and container
    unsigned int currentSize = getTotalItemSize();
    ui->widgetList->setGeometry(ui->widgetList->x(), ui->widgetList->y(), width(), currentSize);
    setGeometry(0, 0, width(), 50 + currentSize);

    //Expand the widget
    connect(abstract, &AbstractDBWidget::expand, [=](bool drop){
        QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
        animation->setDuration(100);
        animation->setStartValue(widget->geometry());
        if(drop) {animation->setEndValue(QRect(0, 0, widget->width(), abstract->getMin()));}
        else {animation->setEndValue(QRect(0, 0, widget->width(), abstract->getMax()));}
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    });

    //Connect for the drop animation
    connect(abstract, &AbstractDBWidget::sizeChanged, [=](){
        listItem->setSizeHint(QSize(widget->width(), widget->height()));

        unsigned int currentSize = getTotalItemSize();
        ui->widgetList->setGeometry(ui->widgetList->x(), ui->widgetList->y(), width(), currentSize);
        setGeometry(0, 0, width(), 50 + currentSize);
    });

    //Connect to remove the widget from the display and delete it
    connect(abstract, &AbstractDBWidget::remove, [=](std::shared_ptr<AbstractDataBaseItem> item){
        ui->widgetList->removeItemWidget(listItem);
        delete listItem;

        _dbContainer->removeItem(item);
        _widgetList.erase(std::remove(_widgetList.begin(), _widgetList.end(), widget), _widgetList.end()); //Remove UI from list
        widget->deleteLater(); //Delete container UI

        unsigned int currentSize = getTotalItemSize();
        ui->widgetList->setGeometry(ui->widgetList->x(), ui->widgetList->y(), width(), currentSize);
        setGeometry(0, 0, width(), 50 + currentSize);

        emit modified();
    });

    connect(abstract, &AbstractDBWidget::modified, [=](){
        emit modified();
    });

    connect(abstract, &AbstractDBWidget::changePos, [=](bool up){
        handleRow(up, listItem);
    });

    emit modified();
}

unsigned int DBWContainers::getTotalItemSize()
{
    unsigned int currentSize = 0;

    for(unsigned int i = 0; i < _widgetList.size(); i++)
    {
        //Sum all the widgets height
        currentSize += _widgetList.at(i)->height();
    }

    return currentSize;
}

void DBWContainers::retract()
{
    emit widgetClicked(true);
    ui->containerButton->setChecked(true);
}

std::shared_ptr<DBContainers> DBWContainers::getContainer()
{
    return _dbContainer;
}

//Handle row position of the items
void DBWContainers::handleRow(bool up, QListWidgetItem *listItemReceived)
{
    for(int i = 0; i < ui->widgetList->count(); i++)
    {
        QListWidgetItem *listitem = ui->widgetList->item(i);
        AbstractDBWidget *dbWidget = qobject_cast<AbstractDBWidget*>(ui->widgetList->itemWidget(listitem));
        std::shared_ptr<AbstractDataBaseItem> item = dbWidget->getAbstractItem();

        if(listitem == listItemReceived)
        {
            if(up)
            {
                if(item->getRow() > 1)
                {
                    item->setRow(item->getRow() - 1);

                    QListWidgetItem *previousItem = ui->widgetList->item(i - 1);
                    AbstractDBWidget *previouswItem = qobject_cast<AbstractDBWidget*>(ui->widgetList->itemWidget(previousItem));
                    std::shared_ptr<AbstractDataBaseItem> previousDBItem = previouswItem->getAbstractItem();

                    previousDBItem->setRow(previousDBItem->getRow() + 1);
                    previousItem->setData(0, previousDBItem->getRow());
                }
            }
            else
            {
                if(item->getRow() != ui->widgetList->count() - 1)
                {
                    item->setRow(item->getRow() + 1);

                    QListWidgetItem *previousItem = ui->widgetList->item(i - 1);
                    AbstractDBWidget *previouswItem = qobject_cast<AbstractDBWidget*>(ui->widgetList->itemWidget(previousItem));
                    std::shared_ptr<AbstractDataBaseItem> previousDBItem = previouswItem->getAbstractItem();

                    previousDBItem->setRow(previousDBItem->getRow() - 1);
                    previousItem->setData(0, previousDBItem->getRow());
                }
            }
            listitem->setData(0, item->getRow());
            emit modified();
            break;
        }
    }
}

std::shared_ptr<AbstractDataBaseItem> DBWContainers::getAbstractItem()
{
    return nullptr;
}

DBWContainers::~DBWContainers()
{
    ui->widgetList->clear();
    delete ui;
}
