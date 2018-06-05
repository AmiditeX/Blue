/********************************************************************************
** Form generated from reading UI file 'dbwnamefield.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWNAMEFIELD_H
#define UI_DBWNAMEFIELD_H

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

class Ui_DBWNameField
{
public:
    QLineEdit *nameField;
    QPushButton *modify;
    QLineEdit *nameModify;
    QPushButton *save;
    QPushButton *remove;
    QWidget *expiration;
    QLabel *expireLabel;
    QLabel *downColor;
    QLabel *downColor_2;

    void setupUi(QWidget *DBWNameField)
    {
        if (DBWNameField->objectName().isEmpty())
            DBWNameField->setObjectName(QStringLiteral("DBWNameField"));
        DBWNameField->resize(830, 184);
        DBWNameField->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        nameField = new QLineEdit(DBWNameField);
        nameField->setObjectName(QStringLiteral("nameField"));
        nameField->setGeometry(QRect(10, 10, 721, 25));
        nameField->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        nameField->setMaxLength(10000);
        nameField->setEchoMode(QLineEdit::Normal);
        nameField->setReadOnly(true);
        modify = new QPushButton(DBWNameField);
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
        nameModify = new QLineEdit(DBWNameField);
        nameModify->setObjectName(QStringLiteral("nameModify"));
        nameModify->setGeometry(QRect(10, 50, 811, 25));
        nameModify->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        nameModify->setMaxLength(10000);
        nameModify->setEchoMode(QLineEdit::Normal);
        save = new QPushButton(DBWNameField);
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
        remove = new QPushButton(DBWNameField);
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
        expiration = new QWidget(DBWNameField);
        expiration->setObjectName(QStringLiteral("expiration"));
        expiration->setGeometry(QRect(250, 90, 380, 46));
        expireLabel = new QLabel(DBWNameField);
        expireLabel->setObjectName(QStringLiteral("expireLabel"));
        expireLabel->setGeometry(QRect(663, 10, 71, 25));
        expireLabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(239, 41, 41);\n"
"font-weight: bold"));
        downColor = new QLabel(DBWNameField);
        downColor->setObjectName(QStringLiteral("downColor"));
        downColor->setGeometry(QRect(0, 40, 830, 3));
        downColor->setStyleSheet(QStringLiteral("background-color: rgb(68, 158, 241);"));
        downColor_2 = new QLabel(DBWNameField);
        downColor_2->setObjectName(QStringLiteral("downColor_2"));
        downColor_2->setGeometry(QRect(0, 180, 830, 3));
        downColor_2->setStyleSheet(QStringLiteral("background-color: rgb(68, 158, 241);"));

        retranslateUi(DBWNameField);

        QMetaObject::connectSlotsByName(DBWNameField);
    } // setupUi

    void retranslateUi(QWidget *DBWNameField)
    {
        DBWNameField->setWindowTitle(QApplication::translate("DBWNameField", "Form", nullptr));
        nameField->setText(QString());
        nameField->setPlaceholderText(QApplication::translate("DBWNameField", "Name..", nullptr));
        modify->setText(QApplication::translate("DBWNameField", "Modify", nullptr));
        nameModify->setText(QString());
        nameModify->setPlaceholderText(QApplication::translate("DBWNameField", "Modify name..", nullptr));
        save->setText(QApplication::translate("DBWNameField", "Save", nullptr));
        remove->setText(QApplication::translate("DBWNameField", "Remove", nullptr));
        expireLabel->setText(QApplication::translate("DBWNameField", "    EXPIRED", nullptr));
        downColor->setText(QString());
        downColor_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DBWNameField: public Ui_DBWNameField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWNAMEFIELD_H
