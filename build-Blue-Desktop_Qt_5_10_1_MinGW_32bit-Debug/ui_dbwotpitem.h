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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBWOtpItem
{
public:
    QPushButton *save;
    QPushButton *see;
    QLabel *expireLabel;
    QLineEdit *passwordField;
    QPushButton *remove;
    QLineEdit *passwordModify;
    QPushButton *modify;
    QWidget *expiration;

    void setupUi(QWidget *DBWOtpItem)
    {
        if (DBWOtpItem->objectName().isEmpty())
            DBWOtpItem->setObjectName(QStringLiteral("DBWOtpItem"));
        DBWOtpItem->resize(830, 223);
        DBWOtpItem->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        save = new QPushButton(DBWOtpItem);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(450, 180, 371, 25));
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
        see = new QPushButton(DBWOtpItem);
        see->setObjectName(QStringLiteral("see"));
        see->setGeometry(QRect(662, 10, 73, 25));
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
        expireLabel = new QLabel(DBWOtpItem);
        expireLabel->setObjectName(QStringLiteral("expireLabel"));
        expireLabel->setGeometry(QRect(584, 10, 71, 25));
        expireLabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(239, 41, 41);\n"
"font-weight: bold"));
        passwordField = new QLineEdit(DBWOtpItem);
        passwordField->setObjectName(QStringLiteral("passwordField"));
        passwordField->setGeometry(QRect(10, 10, 645, 25));
        passwordField->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        passwordField->setMaxLength(10000);
        passwordField->setEchoMode(QLineEdit::Password);
        passwordField->setReadOnly(true);
        remove = new QPushButton(DBWOtpItem);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(10, 180, 431, 25));
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
        passwordModify = new QLineEdit(DBWOtpItem);
        passwordModify->setObjectName(QStringLiteral("passwordModify"));
        passwordModify->setGeometry(QRect(10, 60, 811, 25));
        passwordModify->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        passwordModify->setMaxLength(10000);
        passwordModify->setEchoMode(QLineEdit::Normal);
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
        expiration->setGeometry(QRect(0, 100, 830, 46));

        retranslateUi(DBWOtpItem);

        QMetaObject::connectSlotsByName(DBWOtpItem);
    } // setupUi

    void retranslateUi(QWidget *DBWOtpItem)
    {
        DBWOtpItem->setWindowTitle(QApplication::translate("DBWOtpItem", "Form", nullptr));
        save->setText(QApplication::translate("DBWOtpItem", "Save", nullptr));
        see->setText(QApplication::translate("DBWOtpItem", "See", nullptr));
        expireLabel->setText(QApplication::translate("DBWOtpItem", " EXPIRED", nullptr));
        passwordField->setText(QString());
        passwordField->setPlaceholderText(QApplication::translate("DBWOtpItem", "Password..", nullptr));
        remove->setText(QApplication::translate("DBWOtpItem", "Remove", nullptr));
        passwordModify->setText(QString());
        passwordModify->setPlaceholderText(QApplication::translate("DBWOtpItem", "Modify password..", nullptr));
        modify->setText(QApplication::translate("DBWOtpItem", "Modify", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBWOtpItem: public Ui_DBWOtpItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWOTPITEM_H
