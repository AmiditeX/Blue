#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <iostream>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_QuitOnClose, false); //Doesn't need to be closed for the program to close
    ui->databaseTab->tabBar()->hide();

    //Close and minimize
    connect(ui->close, &QPushButton::pressed, [=](){
        setDisabled(true);
        opener->setVisible(false);
        creator->setVisible(false);
        settings->setVisible(false);
        ui->shadow->setVisible(false);
        ui->databaseTab->setVisible(false);
        displayGeneralError("The program will close when all the opened databases finish saving");
        emit closing();
    });

    connect(ui->minimize, &QPushButton::pressed, [=](){
        setWindowState(Qt::WindowMinimized); //Minimize window
    });

    //UI connects
    QObject::connect(ui->buttonOpen, SIGNAL(clicked(bool)), this, SLOT(openDatabase()));
    QObject::connect(ui->buttonCreate, SIGNAL(clicked(bool)), this, SLOT(createDatabase()));


    //Database Opener
    opener = new DatabaseOpener(this);
    QObject::connect(opener, SIGNAL(openPressed()), this, SLOT(openerReturn()));
    QObject::connect(opener, SIGNAL(closePressed()), this, SLOT(openerClose()));
    QObject::connect(opener, SIGNAL(closePressed()), opener, SLOT(clear()));
    opener->setVisible(true);
    opener->move(260, 30);

    //Database Creator
    creator = new DatabaseCreator(this);
    QObject::connect(creator, SIGNAL(okPressed()), this, SLOT(creatorReturn()));
    QObject::connect(creator, SIGNAL(closePressed()), this, SLOT(creatorClose()));
    creator->setVisible(false);
    creator->move(260, 30);

    //Database settings modifier
    settings = new DatabaseSettings(this);
    QObject::connect(settings, SIGNAL(okPressed()), this, SLOT(settingsReturn()));
    QObject::connect(settings, SIGNAL(closePressed()), this, SLOT(settingsClose()));
    settings->setVisible(false);
    settings->move(260, 30);

    //Shadow effect
    bodyShadow = new CustomShadowEffect(this);
    bodyShadow->setBlurRadius(60.0);
    bodyShadow->setDistance(10.0);
    bodyShadow->setColor(QColor(0, 0, 0, 150));
    ui->shadow->setGraphicsEffect(bodyShadow);

    bodyShadow2 = new CustomShadowEffect(this);
    bodyShadow2->setBlurRadius(60.0);
    bodyShadow2->setDistance(10.0);
    bodyShadow2->setColor(QColor(0, 0, 0, 150));
    ui->shadow2->setGraphicsEffect(bodyShadow2);

    bodyShadow3 = new CustomShadowEffect(this);
    bodyShadow3->setBlurRadius(100.0);
    bodyShadow3->setDistance(30.0);
    bodyShadow3->setColor(QColor(0, 0, 0, 150));
    ui->label->setGraphicsEffect(bodyShadow3);

    ui->shadow->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete opener;
    delete creator;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                          PUBLIC                                                                  //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::displayGeneralError(const QString &err)
{
    BlueDialog *dialog = new BlueDialog(this);
    QObject::connect(this, SIGNAL(destroyed(QObject*)), dialog, SLOT(deleteLater()));
    QObject::connect(dialog, SIGNAL(closeClicked()), dialog, SLOT(deleteLater()));
    QObject::connect(dialog, SIGNAL(okClicked()), dialog, SLOT(deleteLater()));

    dialog->setTitle(tr("Error"));
    dialog->setMessage(err);
    dialog->show();
}

void MainWindow::setSavingStatus(const QString &text, int value)
{
    ui->textStatus->setText(text);
    ui->progressBar->setValue(value);
    ui->progressBar->setFormat(QString().setNum(value) + "s");
}

void MainWindow::setStatusHidden(bool hidden)
{
    ui->textStatus->setHidden(hidden);
    ui->progressBar->setHidden(hidden);
}

void MainWindow::setDatabaseNumber(unsigned int number)
{
    ui->textOpenDatabase->setText(tr("Open database : ") + QString().setNum(number));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                          PUBLIC                                                                  //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Select the database file to load it afterwards
void MainWindow::openDatabase()
{
    ui->databaseTab->setHidden(true);
    creator->setVisible(false);
    opener->setVisible(true);
    settings->setVisible(false);
}

void MainWindow::openerClose()
{
    opener->setVisible(false);
}

//Called when a DatabaseOpener has to return DB settings
void MainWindow::openerReturn()
{
    DatabaseOpener *opener = qobject_cast<DatabaseOpener*>(sender());
    //If a key path was returned, check for validity and open it
    if(!opener->getFilePath().isEmpty() && !opener->getMaster().isEmpty())
    {
        QDir dir;
        if(!dir.exists(opener->getFilePath()))
        {
            displayGeneralError(tr("The database file provided doesn't exist"));
            return;
        }

        if(!dir.exists(opener->getKey()) && !opener->getKey().isEmpty())
        {
            displayGeneralError(tr("The key file provided doesn't exist"));
            return;
        }
    }
    else
    {
        displayGeneralError(tr("Fill all the fields (Path to database, master password)"));
        return;
    }

    emit openingRequest(opener->getMaster(), opener->getFilePath(), opener->getKey());
    opener->clear();
    openerClose();
}


//UI to create a new database
void MainWindow::createDatabase()
{
    ui->databaseTab->setHidden(true);
    ui->shadow->setVisible(false);
    opener->setVisible(false);
    settings->setVisible(false);
    creator->setVisible(true);
}

//Pass settings to BlueManager, check for errors
void MainWindow::creatorReturn()
{
    DatabaseCreator::DatabaseParam params = creator->returnParams();
    if(params.dbPath.isEmpty()) //Error if file not provided, password not provided
    { displayGeneralError(tr("The path to the database wasn't provided")); return; }

    if(params.password.isEmpty())
    { displayGeneralError(tr("The password of the database wasn't provided")); return; }

    QDir dir; //Error if keyfile doesn't exist and if field isn't empty
    if(!dir.exists(params.keyPath) && !params.keyPath.isEmpty())
    {  displayGeneralError(tr("The key file doesn't exist")); return; }

    emit(createRequest(params));
    creatorClose();
}

//Close the creator UI
void MainWindow::creatorClose()
{
    creator->clear();
    creator->setVisible(false);
}

//Called when settings were confirmed
void MainWindow::settingsReturn()
{
    DatabaseSettings::DatabaseParam params = settings->returnParams();
    if(params.dbPath.isEmpty()) //Error if file not provided, password not provided
    { displayGeneralError(tr("The path to the database wasn't provided")); return; }

    if(params.password.isEmpty())
    { displayGeneralError(tr("The password of the database wasn't provided")); return; }

    QDir dir; //Error if keyfile doesn't exist and if field isn't empty
    if(!dir.exists(params.keyPath) && !params.keyPath.isEmpty())
    {  displayGeneralError(tr("The key file doesn't exist")); return; }

    BlueWidget *w = settings->getCurrentDatabase();
    emit settingsChanged(w, settings->returnParams());
    emit modified(w);

    settings->clear();
    settings->setVisible(false);
}

void MainWindow::settingsClose()
{
    settings->clear();
    settings->setVisible(false);
}

//Display the menu widget and the main database widget
void MainWindow::displayWidget(BlueWidget *w, const QString &path)
{
    //Add to mainwidget
    ui->databaseTab->addTab(w, path);
    ui->databaseTab->setCurrentWidget(w);
    creatorClose();
    openerClose();
    settingsClose();
    ui->databaseTab->setVisible(true);
    ui->shadow->setVisible(true);

    //Sidebar management
    QListWidgetItem *item = new QListWidgetItem();
    DatabaseButton *button = new DatabaseButton(this, w, item); //Button has a pointer on item for deletion
    item->setSizeHint(QSize(button->width(), 50));

    //Connect to remove from QListWidget and emit signal to close the database
    connect(button, &DatabaseButton::closeButtonClicked, [=](){
        QListWidgetItem *i = button->returnItem();
        ui->listDatabase->removeItemWidget(i); //Remove from sidebar
        delete i; //Remove i completely from the list (see QT doc)
        ui->databaseTab->removeTab(ui->databaseTab->indexOf(button->getWidget()));
        ui->databaseTab->setHidden(true);
        ui->shadow->setVisible(false);
        emit closeRequest(button->getWidget()); //Tell manager to terminate the database
        w->deleteLater();
    });

    //Connect for the drop animation
    connect(button, &DatabaseButton::dropMenu, [=](bool drop){
        QPropertyAnimation *animation = new QPropertyAnimation(button, "geometry");
        animation->setDuration(100);
        animation->setStartValue(button->geometry());
        if(drop) {animation->setEndValue(QRect(0, 0, button->width(), 55));}
        else {animation->setEndValue(QRect(0, 0, button->width(), 205));}
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    });

    //Connect for the drop animation
    connect(button, &DatabaseButton::sizeChanged, [=](){
        item->setSizeHint(QSize(button->width(), button->height()));
    });

    //Connect to display widget
    connect(button, &DatabaseButton::databaseButtonClicked, [=](){
        ui->databaseTab->setCurrentIndex(ui->databaseTab->indexOf(button->getWidget()));
        ui->databaseTab->setVisible(true);
        ui->shadow->setVisible(true);
        creator->setVisible(false);
        opener->setVisible(false);
        settings->setVisible(false);
    });

    //Connect to settings
    connect(button, &DatabaseButton::settingsButtonClicked, [=](){
        ui->databaseTab->setVisible(false);
        ui->shadow->setVisible(false);
        creator->setVisible(false);
        opener->setVisible(false);
        settings->setVisible(true);

        DBParameters parameters = button->getWidget()->returnParam();
        if(parameters.DBStretchTime > 0)
            parameters.DBIterations = 0;
        DatabaseSettings::DatabaseParam param{parameters.DBPath, "", "", parameters.DBIterations, parameters.DBStretchTime};
        settings->setParams(param);
        settings->setCurrentDatabase(button->getWidget());
    });

    connect(w, &BlueWidget::modified, [=](){
        emit modified(w);
    });

    //Add to sidebar
    ui->listDatabase->addItem(item);
    ui->listDatabase->setItemWidget(item, button);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::error(QString err)
{
    qWarning() << " Error " << err;
}

void MainWindow::write()
{
    qWarning() << "Write successful";
    BlueDBManager manager;
    //manager.readDatabase("encryptedmessage.txt", "Password");
}

void MainWindow::read(DBParameters param)
{
    qWarning() << "Reading";
    qWarning() << param.DBDecrypted;
    qWarning() << param.DBKeySalt;
    qWarning() << param.DBIterations;
}
