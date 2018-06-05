/********************************************************************************
** Form generated from reading UI file 'dbwemailfield.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWEMAILFIELD_H
#define UI_DBWEMAILFIELD_H

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

class Ui_DBWEmailField
{
public:
    QPushButton *remove;
    QLineEdit *emailField;
    QWidget *expiration;
    QLineEdit *emailModify;
    QPushButton *modify;
    QPushButton *save;
    QLabel *expireLabel;
    QLabel *downColor;

    void setupUi(QWidget *DBWEmailField)
    {
        if (DBWEmailField->objectName().isEmpty())
            DBWEmailField->setObjectName(QStringLiteral("DBWEmailField"));
        DBWEmailField->resize(830, 190);
        DBWEmailField->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        remove = new QPushButton(DBWEmailField);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(10, 150, 411, 25));
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
        emailField = new QLineEdit(DBWEmailField);
        emailField->setObjectName(QStringLiteral("emailField"));
        emailField->setGeometry(QRect(10, 10, 721, 25));
        emailField->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        emailField->setMaxLength(10000);
        emailField->setEchoMode(QLineEdit::Normal);
        emailField->setReadOnly(true);
        expiration = new QWidget(DBWEmailField);
        expiration->setObjectName(QStringLiteral("expiration"));
        expiration->setGeometry(QRect(240, 90, 380, 46));
        emailModify = new QLineEdit(DBWEmailField);
        emailModify->setObjectName(QStringLiteral("emailModify"));
        emailModify->setGeometry(QRect(10, 50, 811, 25));
        emailModify->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        emailModify->setMaxLength(10000);
        emailModify->setEchoMode(QLineEdit::Normal);
        modify = new QPushButton(DBWEmailField);
        modify->setObjectName(QStringLiteral("modify"));
        modify->setGeometry(QRect(740, 10, 81, 25));
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
        save = new QPushButton(DBWEmailField);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(430, 150, 391, 25));
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
        expireLabel = new QLabel(DBWEmailField);
        expireLabel->setObjectName(QStringLiteral("expireLabel"));
        expireLabel->setGeometry(QRect(663, 10, 71, 25));
        expireLabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(239, 41, 41);\n"
"font-weight: bold"));
        downColor = new QLabel(DBWEmailField);
        downColor->setObjectName(QStringLiteral("downColor"));
        downColor->setGeometry(QRect(0, 40, 830, 3));
        downColor->setStyleSheet(QStringLiteral("background-color: rgb(68, 158, 241);"));

        retranslateUi(DBWEmailField);

        QMetaObject::connectSlotsByName(DBWEmailField);
    } // setupUi

    void retranslateUi(QWidget *DBWEmailField)
    {
        DBWEmailField->setWindowTitle(QApplication::translate("DBWEmailField", "Form", nullptr));
        remove->setText(QApplication::translate("DBWEmailField", "Remove", nullptr));
        emailField->setText(QString());
        emailField->setPlaceholderText(QApplication::translate("DBWEmailField", "Email..", nullptr));
        emailModify->setText(QString());
        emailModify->setPlaceholderText(QApplication::translate("DBWEmailField", "Modify email..", nullptr));
        modify->setText(QApplication::translate("DBWEmailField", "Modify", nullptr));
        save->setText(QApplication::translate("DBWEmailField", "Save", nullptr));
        expireLabel->setText(QApplication::translate("DBWEmailField", "    EXPIRED", nullptr));
        downColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DBWEmailField: public Ui_DBWEmailField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWEMAILFIELD_H
