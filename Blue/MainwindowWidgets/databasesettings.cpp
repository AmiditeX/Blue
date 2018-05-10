#include "databasesettings.h"
#include "ui_databasesettings.h"

DatabaseSettings::DatabaseSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseSettings)
{
    ui->setupUi(this);

    creator = new PasswordCreator(ui->widget);
    QObject::connect(creator, SIGNAL(sizeChanged(bool)), this, SLOT(changeSize(bool)));

    QObject::connect(ui->openKey, SIGNAL(clicked(bool)), this, SLOT(openKeySelector()));
    QObject::connect(ui->open, SIGNAL(clicked(bool)), this, SLOT(openDbSelector()));

    QObject::connect(ui->ok, SIGNAL(clicked(bool)), this, SIGNAL(okPressed()));
    QObject::connect(ui->close, SIGNAL(clicked(bool)), this, SIGNAL(closePressed()));

    connect(ui->iterationTime, qOverload<int>(&QSpinBox::valueChanged), [=](int i){
        if(i != 0) {ui->stretchTime->setDisabled(true);}
        else {ui->stretchTime->setDisabled(false);}
    });

    //Shadow effect
    bodyShadow = new CustomShadowEffect(this);
    bodyShadow->setBlurRadius(50.0);
    bodyShadow->setDistance(10.0);
    bodyShadow->setColor(QColor(0, 0, 0, 150));
    setGraphicsEffect(bodyShadow);

    changeSize(false);
}

void DatabaseSettings::openDbSelector()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), QDir::currentPath(), "*.blue");
    if(!fileName.endsWith(".blue") && !fileName.isEmpty())
    {
        fileName.append(".blue");
    }
    ui->database->setText(fileName);
}

void DatabaseSettings::openKeySelector()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select key"), QDir::currentPath(), "*");
    ui->key->setText(fileName);
}

void DatabaseSettings::changeSize(bool expanded)
{
    if(!expanded)
    {
        ui->label->setGeometry(ui->label->x(), ui->label->y(), ui->label->width(), 425);
        ui->widget->setGeometry(ui->widget->x(), ui->widget->y(), ui->widget->width(), 145);
        ui->ok->setGeometry(340, 110, ui->ok->width(), ui->ok->height());
        ui->close->setGeometry(460, 110, ui->close->width(), ui->close->height());
    }
    else
    {
        ui->label->setGeometry(ui->label->x(), ui->label->y(), ui->label->width(), 600);
        ui->widget->setGeometry(ui->widget->x(), ui->widget->y(), ui->widget->width(), 325);
        ui->ok->setGeometry(340, 290, ui->ok->width(), ui->ok->height());
        ui->close->setGeometry(460, 290, ui->close->width(), ui->close->height());
    }
    update();
}

DatabaseSettings::DatabaseParam DatabaseSettings::returnParams()
{
    DatabaseParam returnObject {ui->database->text(), ui->key->text(), creator->returnPassword(), ui->iterationTime->value(), ui->stretchTime->value()};
    return returnObject;
}

void DatabaseSettings::setParams(DatabaseParam param)
{
    ui->database->setText(param.dbPath);
    ui->key->setText(param.keyPath);
    creator->setPassword(param.password);
    ui->iterationTime->setValue(param.iterations);
    ui->stretchTime->setValue(param.stretchTime);
}

void DatabaseSettings::clear()
{
    ui->database->clear();
    ui->key->clear();
    ui->iterationTime->setValue(0);
    ui->stretchTime->setValue(2);
    creator->clear();
}

void DatabaseSettings::setCurrentDatabase(BlueWidget *ptr)
{
    _currentDatabase = ptr;
}

BlueWidget* DatabaseSettings::getCurrentDatabase()
{
    return _currentDatabase;
}

DatabaseSettings::~DatabaseSettings()
{
    delete ui;
    delete creator;
    delete bodyShadow;
}
