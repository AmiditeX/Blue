#include "bluewidget.h"
#include "ui_bluewidget.h"

BlueWidget::BlueWidget(std::shared_ptr<BlueDatabase> databasePointer) : ui(new Ui::BlueWidget), _dataBase(databasePointer)
{
    ui->setupUi(this);

    std::vector<std::shared_ptr<DBContainers>> containerList = _dataBase->returnContainerList();

    //Create container widgets from DBContainers, store in an array
    for(unsigned int i = 0; i < containerList.size(); i++)
    {
        addContainer(containerList.at(i));
    }

    ui->containerList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    creator = new ContainerCreator(this);
    creator->setVisible(false);
    QObject::connect(ui->addContainer, SIGNAL(clicked(bool)), this, SLOT(createNewContainer()));
    QObject::connect(creator, SIGNAL(okPressed()), this, SLOT(creatorReturned()));

    connect(ui->fold, &QPushButton::clicked, [=](){
        for(unsigned int i = 0; i < _containers.size(); i++)
            _containers[i]->retract();
    });

    connect(ui->scrollBar, &QScrollBar::valueChanged, [=](int value){
        ui->containerList->verticalScrollBar()->setValue(value);
    });

    connect(ui->scrollBar, &QScrollBar::rangeChanged, [=](int min, int max){
        ui->containerList->verticalScrollBar()->setRange(min, max);
    });
}

//Add a container as an UI
void BlueWidget::addContainer(std::shared_ptr<DBContainers> container)
{
    QListWidgetItem *item = new QListWidgetItem();
    DBWContainers *widget;
    widget = new DBWContainers(this, container, item);

    item->setSizeHint(QSize(widget->width(), 50));

    //Expand the widget
    connect(widget, &DBWContainers::widgetClicked, [=](bool drop){
        QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
        animation->setDuration(100);
        animation->setStartValue(widget->geometry());
        if(widget->getTotalItemSize() == 0) {return;}
        if(drop) {animation->setEndValue(QRect(widget->x(), widget->y(), widget->width(), 50));}
        else {animation->setEndValue(QRect(widget->x(), widget->y(), widget->width(), 50 + widget->getTotalItemSize()));}
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    });

    //Connect for the drop animation
    connect(widget, &DBWContainers::sizedChanged, [item, widget](){
        item->setSizeHint(QSize(widget->width(), widget->height()));
    });

    //Connect delete signal
    connect(widget, &DBWContainers::pendingDelete, [=](std::shared_ptr<DBContainers> container){
        QListWidgetItem *i = widget->returnItem();
        ui->containerList->removeItemWidget(i); //Remove from QListWidget
        delete i; //Remove i completely from the list (see QT doc)

        _dataBase->removeContainer(container); //Remove container from structure
        _containers.erase(std::remove(_containers.begin(), _containers.end(), widget), _containers.end()); //Remove UI from list
        widget->deleteLater(); //Delete container UI

        emit modified();
    });

    QObject::connect(widget, SIGNAL(modified()), this, SIGNAL(modified()));
    connect(widget, &DBWContainers::up, [=](){
        handleRow(true, item);
    });
    connect(widget, &DBWContainers::down, [=](){
        handleRow(false, item);
    });

    ui->containerList->addItem(item);
    ui->containerList->setItemWidget(item, widget);
    _containers.push_back(widget);

    if(container->getRow() == 0)
    {
        container->setRow(_containers.size());
    }
    item->setData(0, container->getRow());
}

//Create a new container (UI and underneath structure)
void BlueWidget::createNewContainer()
{
    creator->setVisible(true);
}

//Triggered when creatorOk is pressed
void BlueWidget::creatorReturned()
{
    std::shared_ptr<DBContainers> container = _dataBase->addContainer();
    container->setColor(creator->returnParams().colorBackground);
    container->setTitle(creator->returnParams().name);
    container->setTextColor(creator->returnParams().colorText);

    creator->clear();
    addContainer(container);
    emit modified();
}

//Return the parameters of the link database
DBParameters BlueWidget::returnParam()
{
    return _dataBase->getParameters();
}

//Handle row position of the containers
void BlueWidget::handleRow(bool up, QListWidgetItem *listItem)
{
    for(int i = 0; i < ui->containerList->count(); i++)
    {
        QListWidgetItem *item = ui->containerList->item(i);
        DBWContainers *dbwcontainer = qobject_cast<DBWContainers*>(ui->containerList->itemWidget(item));
        std::shared_ptr<DBContainers> container = dbwcontainer->getContainer();

        if(listItem == item)
        {
            if(up)
            {
                if(container->getRow() > 1)
                {
                    container->setRow(container->getRow() - 1);

                    QListWidgetItem *previousItem = ui->containerList->item(i - 1);
                    DBWContainers *previouswContainer = qobject_cast<DBWContainers*>(ui->containerList->itemWidget(previousItem));
                    std::shared_ptr<DBContainers> previousContainer = previouswContainer->getContainer();

                    previousContainer->setRow(previousContainer->getRow() + 1);
                    previousItem->setData(0, previousContainer->getRow());
                }
            }
            else
            {
                if(container->getRow() != ui->containerList->count() - 1)
                {
                    container->setRow(container->getRow() + 1);

                    QListWidgetItem *previousItem = ui->containerList->item(i + 1);
                    DBWContainers *previouswContainer = qobject_cast<DBWContainers*>(ui->containerList->itemWidget(previousItem));
                    std::shared_ptr<DBContainers> previousContainer = previouswContainer->getContainer();

                    previousContainer->setRow(previousContainer->getRow() - 1);
                    previousItem->setData(0, previousContainer->getRow());
                }
            }
            item->setData(0, container->getRow());
            emit modified();
            break;
        }
    }

}

BlueWidget::~BlueWidget()
{
    ui->containerList->clear();
    delete ui;
}
