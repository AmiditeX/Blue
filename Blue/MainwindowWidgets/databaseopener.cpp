#include "databaseopener.h"
#include "ui_databaseopener.h"

DatabaseOpener::DatabaseOpener(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseOpener)
{
    ui->setupUi(this);

    QObject::connect(ui->ok, SIGNAL(clicked(bool)), this, SIGNAL(openPressed()));
    QObject::connect(ui->close, SIGNAL(clicked(bool)), this, SIGNAL(closePressed()));

    QObject::connect(ui->see, SIGNAL(toggled(bool)), this, SLOT(switchEcho(bool)));

    QObject::connect(ui->openDatabase, SIGNAL(clicked(bool)), this, SLOT(openDbSelector()));
    QObject::connect(ui->openKey, SIGNAL(clicked(bool)), this, SLOT(openKeySelector()));

    //Shadow effect
    bodyShadow = new CustomShadowEffect(this);
    bodyShadow->setBlurRadius(50.0);
    bodyShadow->setDistance(10.0);
    bodyShadow->setColor(QColor(0, 0, 0, 150));
    setGraphicsEffect(bodyShadow);

    QSettings settings;
    settings.beginGroup("LatestDatabase");
    ui->database->setText(settings.value("DBPath", "").toString());
    ui->key->setText(settings.value("KeyPath", "").toString());
    settings.endGroup();
}

//Switch the echo mode of the password field
void DatabaseOpener::switchEcho(bool isChecked)
{
    if(isChecked == true)
    {
        ui->master->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->master->setEchoMode(QLineEdit::Password);
    }
}

QString DatabaseOpener::getFilePath()
{
    return ui->database->text();
}

QString DatabaseOpener::getKey()
{
    return ui->key->text();
}

QString DatabaseOpener::getMaster()
{
    return ui->master->text();
}

void DatabaseOpener::openDbSelector()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select the database file"), QDir::currentPath(), "*.blue");
    ui->database->setText(fileName);
}

void DatabaseOpener::openKeySelector()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Select the key file"), QDir::currentPath(), "*");
   ui->key->setText(fileName);
}

void DatabaseOpener::clear()
{
    ui->key->clear();
    ui->master->clear();
    ui->database->clear();
}

DatabaseOpener::~DatabaseOpener()
{
    delete ui;
    delete bodyShadow;
}
