#include "bluewidget.h"
#include "ui_bluewidget.h"

#include <QDebug>

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
        if(drop) {animation->setEndValue(QRect(0, 0, widget->width(), 50));}
        else {animation->setEndValue(QRect(0, 0, widget->width(), widget->getMaxValue()));}
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    });

    //Connect for the drop animation
    connect(widget, &DBWContainers::sizedChanged, [=](){
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

    ui->containerList->addItem(item);
    ui->containerList->setItemWidget(item, widget);
    _containers.push_back(widget);
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

BlueWidget::~BlueWidget()
{
    delete ui;
}
