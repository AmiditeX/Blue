#include "dbwemailfield.h"
#include "ui_dbwemailfield.h"

DBWEmailField::DBWEmailField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item) : AbstractDBWidget(parent),
    ui(new Ui::DBWEmailField), _item(item)
{
    ui->setupUi(this);

    setHeightParam(45, height());

    connect(ui->modify, &QPushButton::toggled, [=](bool toggled){
        emit expand(toggled);
    });

    QObject::connect(ui->remove, SIGNAL(clicked(bool)), this, SLOT(removeWidget()));

    setGeometry(0, 0, width(), 45);

    expiration = new ExpirationWidget(ui->expiration);
    connect(expiration, &ExpirationWidget::expired, this, &DBWEmailField::expiredDate);
    connect(expiration, &ExpirationWidget::stateChanged, this, &DBWEmailField::changeExpirationState);

    std::shared_ptr<DBEmailField> field = std::dynamic_pointer_cast<DBEmailField>(_item);
    if(field)
    {
        expiration->setEnabled(field->isExpirable());
        if(field->isExpirable())
        {
            expiration->setExpiration(field->getExpireDate());
        }
        ui->expireLabel->setVisible(false);
        ui->emailField->setText(field->getValue());
        ui->emailModify->setText(field->getValue());
        checkEmail();
    }

    connect(ui->save, &QPushButton::clicked, [=](){
        ui->emailField->setText(ui->emailModify->text());
        field->setValue(ui->emailModify->text());
        checkEmail();
        emit modified();
    });

    expiration->checkExpiration();
    ui->modify->setVisible(false);
    ui->compromised->setHidden(true);
    ui->compromiseButton->setHidden(true);
    connect(ui->compromiseButton, &QPushButton::clicked, [=](){
        BlueDialog *dialog = new BlueDialog(this);
        dialog->setTitle(tr("Compromised email"));
        dialog->setMessage(tr("Your email has been found on a stolen database, the password associated with it may have been cracked. "
                              "Your email, and accounts using this email may be at risk of being stolen. Change this email or your passwords !"
                                 "To learn more about your leak : https://haveibeenpwned.com and enter your email"));
        dialog->show();

        connect(dialog, &BlueDialog::closeClicked, [=](){
            dialog->hide();
            dialog->deleteLater();
        });

        connect(dialog, &BlueDialog::okClicked, [=](){ //Delete the container from the connected structure, deleting UI
            dialog->hide();
            dialog->deleteLater();
        });
    });

    connect(HIBPChecker::getInstance(), SIGNAL(requestProcessed(std::pair<QString, HIBPChecker::CheckType>, QString)), this, SLOT(checkerReturned(std::pair<QString,HIBPChecker::CheckType>,QString)));
}

//Resize event, emit signal
void DBWEmailField::resizeEvent(QResizeEvent *event)
{
    (void) event;
    emit sizeChanged();
}

//Remove widget
void DBWEmailField::removeWidget()
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
void DBWEmailField::expiredDate()
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
void DBWEmailField::changeExpirationState()
{
    std::shared_ptr<DBEmailField> field = std::dynamic_pointer_cast<DBEmailField>(_item);
    if(!field)
        return;

    field->setExpireDate(expiration->getExpiration());
    field->setExpirable(expiration->isExpirable());

    emit modified();
}

//Check the email on HIBP
void DBWEmailField::checkEmail()
{
    QString email = ui->emailField->text();
    currentRequest = std::make_pair(email, HIBPChecker::Account);
    HIBPChecker::getInstance()->makeRequest(email, HIBPChecker::Account);
}

void DBWEmailField::checkerReturned(std::pair<QString, HIBPChecker::CheckType> metadata, QString returnedData)
{
    ui->compromised->setHidden(true);
    ui->compromiseButton->setHidden(true);
    if(currentRequest != metadata)
        return;

    if(returnedData.isEmpty())
        return;

    ui->compromised->setVisible(true);
    ui->compromiseButton->setVisible(true);
}

void DBWEmailField::enterEvent(QEvent *e)
{
    (void)e;
    ui->modify->setVisible(true);
}

void DBWEmailField::leaveEvent(QEvent *e)
{
    (void)e;
    ui->modify->setVisible(false);
}

DBWEmailField::~DBWEmailField()
{
    delete ui;
}
