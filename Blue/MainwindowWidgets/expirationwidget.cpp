#include "expirationwidget.h"
#include "ui_expirationwidget.h"
#include <QDebug>

ExpirationWidget::ExpirationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpirationWidget)
{
    ui->setupUi(this);
    ui->dateTime->setDateTime(QDateTime::currentDateTime());

    autoCheck = new QTimer(this);
    autoCheck->setInterval(900000); //Check for expiration every 15mn = (900s * 1000) ms
    connect(autoCheck, &QTimer::timeout, this, &ExpirationWidget::checkExpiration);
    connect(ui->dateTime, &QDateTimeEdit::dateTimeChanged, [=](){
        _expiration = ui->dateTime->dateTime();
        checkExpiration();
        emit stateChanged();
    });

    connect(ui->expirationToggle, &QCheckBox::clicked, [=](){
        _isEnabled = ui->expirationToggle->isChecked();
        checkExpiration();
        emit stateChanged();
    });
    autoCheck->start();

    ui->dateTime->setDateTime(QDateTime::currentDateTime());
}

void ExpirationWidget::setExpiration(const QDateTime &d)
{
    _expiration = d;
    ui->dateTime->setDateTime(d);
}

QDateTime ExpirationWidget::getExpiration()
{
    return _expiration;
}

void ExpirationWidget::setEnabled(bool enable)
{
    ui->expirationToggle->setChecked(enable);
    _isEnabled = enable;
}

void ExpirationWidget::checkExpiration()
{
    if(!_isEnabled) //Triggers only if expiration has been enabled
    {
        _isExpired = false;
        emit expired();
        return;
    }

    QDateTime current = QDateTime::currentDateTime();
    qint64 timestampDifference = current.msecsTo(_expiration);
    qWarning() << current << " " << timestampDifference <<_expiration;
    if(timestampDifference <= 0 ) //The date has passed
    {
        _isExpired = true;
        emit expired();
        return;
    }

    _isExpired = false; //Date hasn't passed
    emit expired();
}

bool ExpirationWidget::isExpired()
{
    return _isExpired;
}

bool ExpirationWidget::isExpirable()
{
    return ui->expirationToggle->isChecked();
}

ExpirationWidget::~ExpirationWidget()
{
    delete ui;
}
