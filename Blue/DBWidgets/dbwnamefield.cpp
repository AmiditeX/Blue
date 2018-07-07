#include "dbwnamefield.h"
#include "ui_dbwnamefield.h"

DBWNameField::DBWNameField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : AbstractDBWidget(parent),
    ui(new Ui::DBWNameField), _item(item)
{
    ui->setupUi(this);

    setHeightParam(45, height());

    connect(ui->modify, &QPushButton::toggled, [=](bool toggled){
        emit expand(toggled);
    });

    QObject::connect(ui->remove, SIGNAL(clicked(bool)), this, SLOT(removeWidget()));

    setGeometry(0, 0, width(), 45);

    expiration = new ExpirationWidget(ui->expiration);
    connect(expiration, &ExpirationWidget::expired, this, &DBWNameField::expiredDate);
    connect(expiration, &ExpirationWidget::stateChanged, this, &DBWNameField::changeExpirationState);

    std::shared_ptr<DBNameField> field = std::dynamic_pointer_cast<DBNameField>(_item);
    if(field)
    {
        expiration->setEnabled(field->isExpirable());
        if(field->isExpirable())
        {
            expiration->setExpiration(field->getExpireDate());
        }
        ui->expireLabel->setVisible(false);
        ui->nameField->setText(field->getValue());
        ui->nameModify->setText(field->getValue());
    }

    connect(ui->save, &QPushButton::clicked, [=](){
        ui->nameField->setText(ui->nameModify->text());
        field->setValue(ui->nameModify->text());
        emit modified();
    });

    expiration->checkExpiration();
    ui->modify->setVisible(false);
}

//Resize event, emit signal
void DBWNameField::resizeEvent(QResizeEvent *event)
{
    (void) event;
    emit sizeChanged();
}

//Remove widget
void DBWNameField::removeWidget()
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
void DBWNameField::expiredDate()
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
void DBWNameField::changeExpirationState()
{
    std::shared_ptr<DBNameField> field = std::dynamic_pointer_cast<DBNameField>(_item);
    if(!field)
        return;

    field->setExpireDate(expiration->getExpiration());
    field->setExpirable(expiration->isExpirable());

    emit modified();
}

void DBWNameField::enterEvent(QEvent *e)
{
    (void)e;
    ui->modify->setVisible(true);
}

void DBWNameField::leaveEvent(QEvent *e)
{
    (void)e;
    ui->modify->setVisible(false);
}

DBWNameField::~DBWNameField()
{
    delete ui;
}
