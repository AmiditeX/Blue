#include <iostream>
#include <sstream>
#include "passwordcreator.h"
#include "ui_passwordcreator.h"

PasswordCreator::PasswordCreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordCreator)
{
    ui->setupUi(this);

    QObject::connect(ui->password, SIGNAL(textChanged(QString)), this, SLOT(evaluateSubject(QString)));
    QObject::connect(ui->see, SIGNAL(toggled(bool)), this, SLOT(switchEcho(bool)));
    QObject::connect(ui->generate, SIGNAL(toggled(bool)), this, SLOT(switchGeneratorVisibility(bool)));
    QObject::connect(ui->genPassword, SIGNAL(clicked(bool)), this, SLOT(generatePassword()));
    QObject::connect(ui->genCustom, SIGNAL(toggled(bool)), this, SLOT(uncheckAll(bool)));
    QObject::connect(ui->genPassphrase, SIGNAL(clicked(bool)), this, SLOT(generatePassphrase()));

    setGeometry(x(), y(), 569, 101);
}

PasswordCreator::~PasswordCreator()
{
    delete ui;
}


//Evaluate the entropy of the password
void PasswordCreator::evaluateSubject(QString subject)
{
    zxcppvbn::result result = passwordChecker(subject.toStdString());

    ui->progressBar->setFormat(tr("Entropy : %1 bits").arg(result.entropy));
    ui->progressBar->setValue(result.entropy);
    if(result.entropy > 130)
        ui->progressBar->setValue(130);

    std::ostringstream out;
    out << result.crack_time.count();
    ui->crack->setText(QString::fromStdString(result.crack_time_display + " (" + out.str() + "s)"));

    switch(result.score)
    {
    case 0:
        ui->progressBar->setStyleSheet("QProgressBar {"
                                       "background-color: rgb(255, 255, 255);"
                                       "border-radius:0px}"
                                       "QProgressBar::chunk {"
                                       "background-color: rgb(255, 0, 0);"
                                       "width: 20px;};");
        break;
    case 1:
        ui->progressBar->setStyleSheet("QProgressBar {"
                                       "background-color: rgb(255, 255, 255);"
                                       "border-radius:0px}"
                                       "QProgressBar::chunk {"
                                       "background-color: rgb(252, 175, 62);"
                                       "width: 20px;};");
        break;

    case 2:
        ui->progressBar->setStyleSheet("QProgressBar {"
                                       "background-color: rgb(255, 255, 255);"
                                       "border-radius:0px}"
                                       "QProgressBar::chunk {"
                                       "background-color: rgb(245, 121, 0);"
                                       "width: 20px;};");
        break;

    case 3:
        ui->progressBar->setStyleSheet("QProgressBar {"
                                       "background-color: rgb(255, 255, 255);"
                                       "border-radius:0px}"
                                       "QProgressBar::chunk {"
                                       "background-color: rgb(252, 233, 79);"
                                       "width: 20px;};");
        break;

    case 4:
        ui->progressBar->setStyleSheet("QProgressBar {"
                                       "background-color: rgb(235, 255, 255);"
                                       "border-radius:0px}"

                                       "QProgressBar::chunk {"
                                       "background-color: rgb(0, 255, 0);"
                                       "width: 20px;};");
        break;
    }
}

//Switch the echo mode of the password field
void PasswordCreator::switchEcho(bool isChecked)
{
    if(isChecked == true)
    {
        ui->password->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->password->setEchoMode(QLineEdit::Password);
    }
}

//Show or hide the generator UI
void PasswordCreator::switchGeneratorVisibility(bool visible)
{
    if(visible)
    {
        setGeometry(x(), y(), 569, 282);
        emit sizeChanged(true);
    }
    else
    {
        setGeometry(x(), y(), 569, 101);
        emit sizeChanged(false);
    }
}

//Uncheck/check the QCheckBox if genCustom is checked
void PasswordCreator::uncheckAll(bool checked)
{
    checked = false;
    ui->AZ->setChecked(checked);
    ui->az->setChecked(checked);
    ui->zeronine->setChecked(checked);
    ui->brackets->setChecked(checked);
    ui->special->setChecked(checked);
    ui->union_->setChecked(checked);
    ui->space->setChecked(checked);
}

//Generate a random password
void PasswordCreator::generatePassword()
{
    QString possibleCharacters;

    if(ui->AZ->isChecked())
        possibleCharacters.append(QStringLiteral("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    if(ui->az->isChecked())
        possibleCharacters.append(QStringLiteral("abcdefghijklmnopqrstuvwxyz"));
    if(ui->zeronine->isChecked())
        possibleCharacters.append(QStringLiteral("0123456789"));
    if(ui->brackets->isChecked())
        possibleCharacters.append(QStringLiteral("<>{]()[]"));
    if(ui->special->isChecked())
        possibleCharacters.append(QStringLiteral("&\"~#'|`\\^@=$*%!:;,?./§"));
    if(ui->union_->isChecked())
        possibleCharacters.append(QStringLiteral("-_"));
    if(ui->space->isChecked())
        possibleCharacters.append(QStringLiteral(" "));

    if(ui->genCustom->isChecked())
        possibleCharacters = ui->genCustomChar->text();

    ui->password->setText(generateRandomString(possibleCharacters, ui->genLength->value()));
}

void PasswordCreator::generatePassphrase()
{
     diceWarePassword diceString =  GenPass(ui->wordCount->value(), false);
     ui->password->setText(QString::fromStdString(diceString));
}

//Return a random string of random and maximum length of 32
QString PasswordCreator::generateRandomString(const QString &chars, int length)
{
    if(chars.isEmpty())
        return QString();

    QString randomString;
    for(int i = 0; i < length; i++)
    {
        int index = qrand() % chars.length();
        QChar nextChar = chars.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

void PasswordCreator::clear()
{
    ui->password->clear();
    ui->wordCount->setValue(4);
    ui->genLength->setValue(32);
}

void PasswordCreator::setPassword(const QString &password)
{
    ui->password->setText(password);
}

QString PasswordCreator::returnPassword()
{
    return ui->password->text();
}
