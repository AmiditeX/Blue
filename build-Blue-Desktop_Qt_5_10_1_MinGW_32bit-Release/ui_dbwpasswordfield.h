/********************************************************************************
** Form generated from reading UI file 'dbwpasswordfield.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWPASSWORDFIELD_H
#define UI_DBWPASSWORDFIELD_H

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

class Ui_DBWPasswordField
{
public:
    QPushButton *remove;
    QLineEdit *passwordField;
    QWidget *expiration;
    QLineEdit *passwordModify;
    QPushButton *modify;
    QPushButton *save;
    QLabel *expireLabel;
    QPushButton *see;

    void setupUi(QWidget *DBWPasswordField)
    {
        if (DBWPasswordField->objectName().isEmpty())
            DBWPasswordField->setObjectName(QStringLiteral("DBWPasswordField"));
        DBWPasswordField->resize(830, 223);
        DBWPasswordField->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        remove = new QPushButton(DBWPasswordField);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(7, 180, 431, 25));
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
        passwordField = new QLineEdit(DBWPasswordField);
        passwordField->setObjectName(QStringLiteral("passwordField"));
        passwordField->setGeometry(QRect(7, 10, 645, 25));
        passwordField->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        passwordField->setMaxLength(10000);
        passwordField->setEchoMode(QLineEdit::Password);
        passwordField->setReadOnly(true);
        expiration = new QWidget(DBWPasswordField);
        expiration->setObjectName(QStringLiteral("expiration"));
        expiration->setGeometry(QRect(-3, 100, 830, 46));
        passwordModify = new QLineEdit(DBWPasswordField);
        passwordModify->setObjectName(QStringLiteral("passwordModify"));
        passwordModify->setGeometry(QRect(7, 60, 811, 25));
        passwordModify->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        passwordModify->setMaxLength(10000);
        passwordModify->setEchoMode(QLineEdit::Normal);
        modify = new QPushButton(DBWPasswordField);
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
        save = new QPushButton(DBWPasswordField);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(447, 180, 371, 25));
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
        expireLabel = new QLabel(DBWPasswordField);
        expireLabel->setObjectName(QStringLiteral("expireLabel"));
        expireLabel->setGeometry(QRect(581, 10, 71, 25));
        expireLabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(239, 41, 41);\n"
"font-weight: bold"));
        see = new QPushButton(DBWPasswordField);
        see->setObjectName(QStringLiteral("see"));
        see->setGeometry(QRect(659, 10, 73, 25));
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

        retranslateUi(DBWPasswordField);

        QMetaObject::connectSlotsByName(DBWPasswordField);
    } // setupUi

    void retranslateUi(QWidget *DBWPasswordField)
    {
        DBWPasswordField->setWindowTitle(QApplication::translate("DBWPasswordField", "Form", nullptr));
        remove->setText(QApplication::translate("DBWPasswordField", "Remove", nullptr));
        passwordField->setText(QString());
        passwordField->setPlaceholderText(QApplication::translate("DBWPasswordField", "Password..", nullptr));
        passwordModify->setText(QString());
        passwordModify->setPlaceholderText(QApplication::translate("DBWPasswordField", "Modify password..", nullptr));
        modify->setText(QApplication::translate("DBWPasswordField", "Modify", nullptr));
        save->setText(QApplication::translate("DBWPasswordField", "Save", nullptr));
        expireLabel->setText(QApplication::translate("DBWPasswordField", " EXPIRED", nullptr));
        see->setText(QApplication::translate("DBWPasswordField", "See", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBWPasswordField: public Ui_DBWPasswordField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWPASSWORDFIELD_H
