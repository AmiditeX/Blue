/********************************************************************************
** Form generated from reading UI file 'dbwotpitem.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWOTPITEM_H
#define UI_DBWOTPITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBWOtpItem
{
public:
    QPushButton *save;
    QLabel *expireLabel;
    QLineEdit *otpField;
    QPushButton *remove;
    QLineEdit *otpSeed;
    QPushButton *modify;
    QWidget *expiration;
    QProgressBar *progressBar;
    QLabel *downColor;
    QLabel *downColor_2;

    void setupUi(QWidget *DBWOtpItem)
    {
        if (DBWOtpItem->objectName().isEmpty())
            DBWOtpItem->setObjectName(QStringLiteral("DBWOtpItem"));
        DBWOtpItem->resize(830, 123);
        DBWOtpItem->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        save = new QPushButton(DBWOtpItem);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(430, 90, 391, 25));
        save->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(68, 158, 241);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(93, 127, 247);\n"
"}"));
        expireLabel = new QLabel(DBWOtpItem);
        expireLabel->setObjectName(QStringLiteral("expireLabel"));
        expireLabel->setGeometry(QRect(660, 10, 71, 25));
        expireLabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(239, 41, 41);\n"
"font-weight: bold"));
        otpField = new QLineEdit(DBWOtpItem);
        otpField->setObjectName(QStringLiteral("otpField"));
        otpField->setGeometry(QRect(10, 10, 261, 25));
        otpField->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        otpField->setMaxLength(10000);
        otpField->setEchoMode(QLineEdit::Normal);
        otpField->setAlignment(Qt::AlignCenter);
        otpField->setReadOnly(true);
        remove = new QPushButton(DBWOtpItem);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(10, 90, 411, 25));
        remove->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(239, 41, 41);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(164, 0, 0);\n"
"}"));
        otpSeed = new QLineEdit(DBWOtpItem);
        otpSeed->setObjectName(QStringLiteral("otpSeed"));
        otpSeed->setGeometry(QRect(10, 50, 261, 25));
        otpSeed->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        otpSeed->setMaxLength(10000);
        otpSeed->setEchoMode(QLineEdit::Normal);
        modify = new QPushButton(DBWOtpItem);
        modify->setObjectName(QStringLiteral("modify"));
        modify->setGeometry(QRect(743, 10, 81, 25));
        modify->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(93, 127, 247);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::checked {\n"
"background-color: rgb(68, 158, 241);\n"
"}"));
        modify->setCheckable(true);
        modify->setChecked(true);
        expiration = new QWidget(DBWOtpItem);
        expiration->setObjectName(QStringLiteral("expiration"));
        expiration->setGeometry(QRect(440, 40, 380, 46));
        progressBar = new QProgressBar(DBWOtpItem);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(280, 10, 451, 25));
        progressBar->setStyleSheet(QLatin1String("QProgressBar\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QProgressBar::chunk \n"
"{\n"
"	 \n"
"	background-color: rgb(170, 0, 255);\n"
"     width: 20px;\n"
"}"));
        progressBar->setMaximum(30);
        progressBar->setValue(30);
        progressBar->setAlignment(Qt::AlignCenter);
        downColor = new QLabel(DBWOtpItem);
        downColor->setObjectName(QStringLiteral("downColor"));
        downColor->setGeometry(QRect(0, 40, 830, 3));
        downColor->setStyleSheet(QStringLiteral("background-color: rgb(68, 158, 241);"));
        downColor_2 = new QLabel(DBWOtpItem);
        downColor_2->setObjectName(QStringLiteral("downColor_2"));
        downColor_2->setGeometry(QRect(0, 120, 830, 3));
        downColor_2->setStyleSheet(QStringLiteral("background-color: rgb(68, 158, 241);"));
        progressBar->raise();
        save->raise();
        expireLabel->raise();
        otpField->raise();
        remove->raise();
        otpSeed->raise();
        modify->raise();
        expiration->raise();
        downColor->raise();
        downColor_2->raise();

        retranslateUi(DBWOtpItem);

        QMetaObject::connectSlotsByName(DBWOtpItem);
    } // setupUi

    void retranslateUi(QWidget *DBWOtpItem)
    {
        DBWOtpItem->setWindowTitle(QApplication::translate("DBWOtpItem", "Form", nullptr));
        save->setText(QApplication::translate("DBWOtpItem", "Save", nullptr));
        expireLabel->setText(QApplication::translate("DBWOtpItem", "    EXPIRED", nullptr));
        otpField->setText(QString());
        otpField->setPlaceholderText(QApplication::translate("DBWOtpItem", "OTP Value..", nullptr));
        remove->setText(QApplication::translate("DBWOtpItem", "Remove", nullptr));
        otpSeed->setText(QString());
        otpSeed->setPlaceholderText(QApplication::translate("DBWOtpItem", "Modify seed..", nullptr));
        modify->setText(QApplication::translate("DBWOtpItem", "Modify", nullptr));
        progressBar->setFormat(QApplication::translate("DBWOtpItem", "Time left..", nullptr));
        downColor->setText(QString());
        downColor_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DBWOtpItem: public Ui_DBWOtpItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWOTPITEM_H
