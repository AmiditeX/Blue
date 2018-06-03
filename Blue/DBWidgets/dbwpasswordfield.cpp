#include "dbwpasswordfield.h"
#include "ui_dbwpasswordfield.h"

DBWPasswordField::DBWPasswordField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : AbstractDBWidget(parent),
    ui(new Ui::DBWPasswordField), _item(item)
{
    ui->setupUi(this);

    setHeightParam(45, height());

    connect(ui->modify, &QPushButton::toggled, [=](bool toggled){
        emit expand(toggled);
    });

    connect(ui->see, &QPushButton::toggled, [=](bool toggled){
        if(toggled)
            ui->passwordField->setEchoMode(QLineEdit::Normal);
        else
            ui->passwordField->setEchoMode(QLineEdit::Password);
    });

    QObject::connect(ui->remove, SIGNAL(clicked(bool)), this, SLOT(removeWidget()));

    setGeometry(0, 0, width(), 45);

    expiration = new ExpirationWidget(ui->expiration);
    connect(expiration, &ExpirationWidget::expired, this, &DBWPasswordField::expiredDate);
    connect(expiration, &ExpirationWidget::stateChanged, this, &DBWPasswordField::changeExpirationState);

    std::shared_ptr<DBPasswordField> field = std::dynamic_pointer_cast<DBPasswordField>(_item);
    if(field)
    {
        expiration->setEnabled(field->isExpirable());
        if(field->isExpirable())
        {
            expiration->setExpiration(field->getExpireDate());
        }
        ui->expireLabel->setVisible(false);
        ui->passwordField->setText(field->getValue());
        ui->passwordModify->setText(field->getValue());
    }

    connect(ui->save, &QPushButton::clicked, [=](){
        ui->passwordField->setText(ui->passwordModify->text());
        field->setValue(ui->passwordModify->text());
        emit modified();
    });

    expiration->checkExpiration();
}

//Resize event, emit signal
void DBWPasswordField::resizeEvent(QResizeEvent *event)
{
    (void) event;
    emit sizeChanged();
}

//Remove widget
void DBWPasswordField::removeWidget()
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
void DBWPasswordField::expiredDate()
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
void DBWPasswordField::changeExpirationState()
{
    std::shared_ptr<DBPasswordField> field = std::dynamic_pointer_cast<DBPasswordField>(_item);
    if(!field)
        return;

    field->setExpireDate(expiration->getExpiration());
    field->setExpirable(expiration->isExpirable());

    emit modified();
}

DBWPasswordField::~DBWPasswordField()
{
    delete ui;
}
