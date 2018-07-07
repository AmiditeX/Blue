#include "dbwotpitem.h"
#include "ui_dbwotpitem.h"

#include <QDateTime>
#include "Tools/libcppotp/otp.h"

DBWOtpItem::DBWOtpItem(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : AbstractDBWidget(parent),
    ui(new Ui::DBWOtpItem), _item(item)
{
    ui->setupUi(this);

    setHeightParam(45, height());
    ui->upColor->setVisible(false);
    ui->sideColor->setVisible(false);
    ui->sideColor_2->setVisible(false);
    ui->downColor->setVisible(false);

    connect(ui->modify, &QPushButton::toggled, [=](bool toggled){
        ui->upColor->setVisible(!toggled);
        ui->sideColor->setVisible(!toggled);
        ui->sideColor_2->setVisible(!toggled);
        ui->downColor->setVisible(!toggled);
        emit expand(toggled);
    });

    QObject::connect(ui->remove, SIGNAL(clicked(bool)), this, SLOT(removeWidget()));

    setGeometry(0, 0, width(), 45);

    expiration = new ExpirationWidget(ui->expiration);
    connect(expiration, &ExpirationWidget::expired, this, &DBWOtpItem::expiredDate);
    connect(expiration, &ExpirationWidget::stateChanged, this, &DBWOtpItem::changeExpirationState);

    std::shared_ptr<DBOtpItem> field = std::dynamic_pointer_cast<DBOtpItem>(_item);
    if(field)
    {
        expiration->setEnabled(field->isExpirable());
        if(field->isExpirable())
        {
            expiration->setExpiration(field->getExpireDate());
        }
        ui->expireLabel->setVisible(false);
        ui->otpSeed->setText(field->getValue());
        calculateTotp();
    }

    connect(ui->save, &QPushButton::clicked, [=](){
        field->setSeed(ui->otpSeed->text());
        emit modified();
        calculateTotp();
    });

    expiration->checkExpiration();

    _progressTimer = new QTimer(this);
    connect(_progressTimer, &QTimer::timeout, this, &DBWOtpItem::setProgressStatus);
    _progressTimer->start(1000);

    ui->modify->setVisible(false);
}

//Calculate the otp value from the key
void DBWOtpItem::calculateTotp()
{
    std::shared_ptr<DBOtpItem> field = std::dynamic_pointer_cast<DBOtpItem>(_item);

    CppTotp::Bytes::ByteString key = CppTotp::Bytes::fromUnpaddedBase32(field->getValue().toStdString());
    std::uint32_t result = CppTotp::totp(key, QDateTime::currentSecsSinceEpoch(), 0, 30, 6);
    QString otpValue;
    otpValue.setNum(result);
    while(otpValue.size() < 6)
    {
        otpValue.prepend("0");
    }
    ui->otpField->setText(otpValue);
}

//Resize event, emit signal
void DBWOtpItem::resizeEvent(QResizeEvent *event)
{
    (void) event;
    emit sizeChanged();
}

//Remove widget
void DBWOtpItem::removeWidget()
{
    BlueDialog *dialog = new BlueDialog(this);
    dialog->setTitle(tr("Deleting an item"));
    dialog->setMessage(tr("Are you sure you want to remove this item ?"));
    dialog->show();

    connect(dialog, &BlueDialog::closeClicked, [=](){
        dialog->hide();
        dialog->deleteLater();
    });

    connect(dialog, &BlueDialog::okClicked, [=](){ //Delete the container from the connected structure, deleting UI
        emit remove(_item);
    });
}

//The date has expired
void DBWOtpItem::expiredDate()
{
    if(expiration->isExpired())
    {
        ui->expireLabel->setVisible(true);
    }
    else
    {
        ui->expireLabel->setVisible(false);
    }
}

//Parameters for expiration have changed
void DBWOtpItem::changeExpirationState()
{
    std::shared_ptr<DBOtpItem> field = std::dynamic_pointer_cast<DBOtpItem>(_item);
    if(!field)
        return;

    field->setExpireDate(expiration->getExpiration());
    field->setExpirable(expiration->isExpirable());

    emit modified();
}

void DBWOtpItem::setProgressStatus()
{
    if(ui->progressBar->value() == 0)
    {
        ui->progressBar->setValue(30);
        calculateTotp();
    }
    else
        ui->progressBar->setValue(ui->progressBar->value() - 1);

    ui->progressBar->setFormat(tr("%1 seconds left").arg(ui->progressBar->value()));
}

void DBWOtpItem::enterEvent(QEvent *e)
{
    (void)e;
    ui->modify->setVisible(true);
}

void DBWOtpItem::leaveEvent(QEvent *e)
{
    (void)e;
    ui->modify->setVisible(false);
}

std::shared_ptr<AbstractDataBaseItem> DBWOtpItem::getAbstractItem()
{
    return _item;
}

DBWOtpItem::~DBWOtpItem()
{
    delete ui;
}
