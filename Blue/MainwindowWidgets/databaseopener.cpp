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
    QFileDialog *dialog = new QFileDialog(this, tr("Select the database file"), QDir::currentPath(), "*.blue");
    dialog->setVisible(true); //Display the dialog for the user to select the file

    //Delete the dialog when the URL was retrieved or dialog closed
    QObject::connect(dialog, SIGNAL(urlSelected(QUrl)), dialog, SLOT(deleteLater()));

    //Return database path to loadDatabse()
    QObject::connect(dialog, SIGNAL(urlSelected(QUrl)), this, SLOT(retrieveDbUrl(QUrl)));
}

void DatabaseOpener::retrieveDbUrl(const QUrl &url)
{
    ui->database->setText(url.path());
}

void DatabaseOpener::openKeySelector()
{
    QFileDialog *dialog = new QFileDialog(this, tr("Select the key file"), QDir::currentPath(), "*.bluekey");
    dialog->setVisible(true); //Display the dialog for the user to select the file

    //Delete the dialog when the URL was retrieved or dialog closed
    QObject::connect(dialog, SIGNAL(urlSelected(QUrl)), dialog, SLOT(deleteLater()));

    //Return database path to loadDatabse()
    QObject::connect(dialog, SIGNAL(urlSelected(QUrl)), this, SLOT(retrieveKeyUrl(QUrl)));
}

void DatabaseOpener::retrieveKeyUrl(const QUrl &url)
{
    ui->key->setText(url.path());
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
}
