#include "passwordcreator.h"
#include "ui_passwordcreator.h"

#include <iostream>
#include <sstream>

PasswordCreator::PasswordCreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordCreator)
{
    ui->setupUi(this);

    QObject::connect(ui->password, SIGNAL(textChanged(QString)), this, SLOT(evaluateSubject(QString)));
    QObject::connect(ui->see, SIGNAL(toggled(bool)), this, SLOT(switchEcho(bool)));
}

//Evaluate the entropy of the password
void PasswordCreator::evaluateSubject(QString subject)
{
    zxcppvbn::result result = passwordChecker(subject.toStdString());

    ui->progressBar->setFormat(tr("Entropy : %1 bits").arg(result.entropy));
    ui->progressBar->setValue(result.entropy);

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

PasswordCreator::~PasswordCreator()
{
    delete ui;
}
