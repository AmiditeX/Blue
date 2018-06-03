/********************************************************************************
** Form generated from reading UI file 'passwordcreator.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDCREATOR_H
#define UI_PASSWORDCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordCreator
{
public:
    QLineEdit *password;
    QPushButton *see;
    QProgressBar *progressBar;
    QLineEdit *crack;
    QLabel *label_2;
    QPushButton *genPassword;
    QPushButton *genPassphrase;
    QSpinBox *wordCount;
    QLabel *label_3;
    QCheckBox *AZ;
    QCheckBox *az;
    QCheckBox *zeronine;
    QCheckBox *brackets;
    QCheckBox *special;
    QCheckBox *union_;
    QCheckBox *space;
    QLabel *label_4;
    QLineEdit *genCustomChar;
    QCheckBox *genCustom;
    QSpinBox *genLength;
    QPushButton *generate;

    void setupUi(QWidget *PasswordCreator)
    {
        if (PasswordCreator->objectName().isEmpty())
            PasswordCreator->setObjectName(QStringLiteral("PasswordCreator"));
        PasswordCreator->resize(569, 282);
        PasswordCreator->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        password = new QLineEdit(PasswordCreator);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(10, 10, 471, 25));
        password->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        password->setMaxLength(10000);
        password->setEchoMode(QLineEdit::Password);
        see = new QPushButton(PasswordCreator);
        see->setObjectName(QStringLiteral("see"));
        see->setGeometry(QRect(490, 10, 71, 25));
        see->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(173, 127, 168);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::checked {\n"
"background-color: rgb(92, 53, 102);\n"
"}"));
        see->setCheckable(true);
        progressBar = new QProgressBar(PasswordCreator);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 40, 471, 21));
        progressBar->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:0px"));
        progressBar->setMaximum(130);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        crack = new QLineEdit(PasswordCreator);
        crack->setObjectName(QStringLiteral("crack"));
        crack->setGeometry(QRect(130, 70, 351, 25));
        crack->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        crack->setMaxLength(10000);
        crack->setReadOnly(true);
        label_2 = new QLabel(PasswordCreator);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 111, 25));
        label_2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font-weight: bold"));
        genPassword = new QPushButton(PasswordCreator);
        genPassword->setObjectName(QStringLiteral("genPassword"));
        genPassword->setGeometry(QRect(10, 160, 171, 25));
        genPassword->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"	background-color: rgb(115, 210, 22);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(78, 154, 6);\n"
"}"));
        genPassphrase = new QPushButton(PasswordCreator);
        genPassphrase->setObjectName(QStringLiteral("genPassphrase"));
        genPassphrase->setGeometry(QRect(10, 110, 171, 25));
        genPassphrase->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"	background-color: rgb(245, 121, 0);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(193, 125, 17);\n"
"}"));
        wordCount = new QSpinBox(PasswordCreator);
        wordCount->setObjectName(QStringLiteral("wordCount"));
        wordCount->setGeometry(QRect(310, 110, 141, 25));
        wordCount->setStyleSheet(QLatin1String("QSpinBox {\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:0px\n"
"}\n"
"QSpinBox::up-button {\n"
"background-color: rgb(115, 210, 22);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"background-color: rgb(239, 41, 41);\n"
"}"));
        wordCount->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        wordCount->setMinimum(1);
        wordCount->setValue(4);
        label_3 = new QLabel(PasswordCreator);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 110, 111, 25));
        label_3->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font-weight: bold"));
        AZ = new QCheckBox(PasswordCreator);
        AZ->setObjectName(QStringLiteral("AZ"));
        AZ->setGeometry(QRect(190, 160, 121, 23));
        AZ->setStyleSheet(QLatin1String("QCheckBox {\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"border-color: rgb(255,255,255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        AZ->setChecked(true);
        az = new QCheckBox(PasswordCreator);
        az->setObjectName(QStringLiteral("az"));
        az->setGeometry(QRect(190, 190, 121, 23));
        az->setStyleSheet(QLatin1String("QCheckBox {\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"border-color: rgb(255,255,255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        az->setChecked(true);
        zeronine = new QCheckBox(PasswordCreator);
        zeronine->setObjectName(QStringLiteral("zeronine"));
        zeronine->setGeometry(QRect(190, 220, 121, 23));
        zeronine->setStyleSheet(QLatin1String("QCheckBox {\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"border-color: rgb(255,255,255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        zeronine->setChecked(true);
        brackets = new QCheckBox(PasswordCreator);
        brackets->setObjectName(QStringLiteral("brackets"));
        brackets->setGeometry(QRect(280, 160, 161, 23));
        brackets->setStyleSheet(QLatin1String("QCheckBox {\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"border-color: rgb(255,255,255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        special = new QCheckBox(PasswordCreator);
        special->setObjectName(QStringLiteral("special"));
        special->setGeometry(QRect(280, 190, 161, 23));
        special->setStyleSheet(QLatin1String("QCheckBox {\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"border-color: rgb(255,255,255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        union_ = new QCheckBox(PasswordCreator);
        union_->setObjectName(QStringLiteral("union_"));
        union_->setGeometry(QRect(280, 220, 161, 23));
        union_->setStyleSheet(QLatin1String("QCheckBox {\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"border-color: rgb(255,255,255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        space = new QCheckBox(PasswordCreator);
        space->setObjectName(QStringLiteral("space"));
        space->setGeometry(QRect(450, 160, 161, 23));
        space->setStyleSheet(QLatin1String("QCheckBox {\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"border-color: rgb(255,255,255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        label_4 = new QLabel(PasswordCreator);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 190, 71, 25));
        label_4->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font-weight: bold"));
        genCustomChar = new QLineEdit(PasswordCreator);
        genCustomChar->setObjectName(QStringLiteral("genCustomChar"));
        genCustomChar->setGeometry(QRect(190, 250, 251, 25));
        genCustomChar->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        genCustomChar->setMaxLength(100);
        genCustomChar->setEchoMode(QLineEdit::Normal);
        genCustom = new QCheckBox(PasswordCreator);
        genCustom->setObjectName(QStringLiteral("genCustom"));
        genCustom->setGeometry(QRect(450, 250, 161, 23));
        genCustom->setStyleSheet(QLatin1String("QCheckBox {\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"border-color: rgb(255,255,255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        genLength = new QSpinBox(PasswordCreator);
        genLength->setObjectName(QStringLiteral("genLength"));
        genLength->setGeometry(QRect(80, 190, 101, 26));
        genLength->setStyleSheet(QLatin1String("QSpinBox {\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:0px\n"
"}\n"
"QSpinBox::up-button {\n"
"background-color: rgb(115, 210, 22);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"background-color: rgb(239, 41, 41);\n"
"}"));
        genLength->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        genLength->setMinimum(1);
        genLength->setMaximum(300);
        genLength->setValue(32);
        generate = new QPushButton(PasswordCreator);
        generate->setObjectName(QStringLiteral("generate"));
        generate->setGeometry(QRect(490, 40, 71, 55));
        generate->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(68, 158, 241);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"font: 9pt \"DejaVu Sans\";\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(93, 127, 247);\n"
"}"));
        generate->setCheckable(true);

        retranslateUi(PasswordCreator);

        QMetaObject::connectSlotsByName(PasswordCreator);
    } // setupUi

    void retranslateUi(QWidget *PasswordCreator)
    {
        PasswordCreator->setWindowTitle(QApplication::translate("PasswordCreator", "Form", nullptr));
        password->setText(QString());
        password->setPlaceholderText(QApplication::translate("PasswordCreator", "Password..", nullptr));
        see->setText(QApplication::translate("PasswordCreator", "See", nullptr));
        progressBar->setFormat(QString());
        crack->setText(QString());
        crack->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("PasswordCreator", " Time to crack :", nullptr));
        genPassword->setText(QApplication::translate("PasswordCreator", "Generate password", nullptr));
        genPassphrase->setText(QApplication::translate("PasswordCreator", "Generate Passphrase", nullptr));
        wordCount->setSuffix(QApplication::translate("PasswordCreator", " Word(s)", nullptr));
        wordCount->setPrefix(QString());
        label_3->setText(QApplication::translate("PasswordCreator", "   Word count :", nullptr));
        AZ->setText(QApplication::translate("PasswordCreator", "A-Z", nullptr));
        az->setText(QApplication::translate("PasswordCreator", "a-z", nullptr));
        zeronine->setText(QApplication::translate("PasswordCreator", "0-9", nullptr));
        brackets->setText(QApplication::translate("PasswordCreator", "Brackets, (), <>, ..", nullptr));
        special->setText(QApplication::translate("PasswordCreator", "Special, $, *, ..", nullptr));
        union_->setText(QApplication::translate("PasswordCreator", "Union, -, _", nullptr));
        space->setText(QApplication::translate("PasswordCreator", "Space", nullptr));
        label_4->setText(QApplication::translate("PasswordCreator", " Length :", nullptr));
        genCustomChar->setText(QString());
        genCustomChar->setPlaceholderText(QApplication::translate("PasswordCreator", "Custom characters", nullptr));
        genCustom->setText(QApplication::translate("PasswordCreator", "Custom", nullptr));
        generate->setText(QApplication::translate("PasswordCreator", "Generate\n"
"Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordCreator: public Ui_PasswordCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDCREATOR_H
