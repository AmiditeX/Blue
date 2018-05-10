#include "databasebutton.h"
#include "ui_databasebutton.h"

DatabaseButton::DatabaseButton(QWidget *parent, BlueWidget *w, QListWidgetItem *listItem) :
    QWidget(parent), ui(new Ui::DatabaseButton), _widget(w), _listItem(listItem)
{
    ui->setupUi(this);

    //UI connects
    QObject::connect(ui->databaseButton, SIGNAL(toggled(bool)), this, SIGNAL(dropMenu(bool)));
    QObject::connect(ui->databaseButton, SIGNAL(clicked(bool)), this, SIGNAL(databaseButtonClicked()));
    QObject::connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SIGNAL(closeButtonClicked()));
    QObject::connect(ui->dashBoard, SIGNAL(clicked(bool)), this, SIGNAL(dashboardButtonClicked()));
    QObject::connect(ui->settingsButton, SIGNAL(clicked(bool)), this, SIGNAL(settingsButtonClicked()));

    //Default geometry doesn't contain the dropdown menu
    setGeometry(QRect(0, 0, ui->databaseButton->width(), ui->databaseButton->height() + 5));
}

BlueWidget* DatabaseButton::getWidget() const
{
    return _widget;
}

QListWidgetItem* DatabaseButton::returnItem() const
{
    return _listItem;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Resize event, emit signal
void DatabaseButton::resizeEvent(QResizeEvent *event)
{
    (void) event;
    emit sizeChanged();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DatabaseButton::~DatabaseButton()
{
    delete ui;
}
