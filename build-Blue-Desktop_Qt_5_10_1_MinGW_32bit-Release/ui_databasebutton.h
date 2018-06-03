/********************************************************************************
** Form generated from reading UI file 'databasebutton.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEBUTTON_H
#define UI_DATABASEBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseButton
{
public:
    QPushButton *databaseButton;
    QPushButton *settingsButton;
    QPushButton *deleteButton;
    QPushButton *dashBoard;
    QLabel *label;

    void setupUi(QWidget *DatabaseButton)
    {
        if (DatabaseButton->objectName().isEmpty())
            DatabaseButton->setObjectName(QStringLiteral("DatabaseButton"));
        DatabaseButton->resize(230, 205);
        DatabaseButton->setStyleSheet(QStringLiteral("background-color: rgb(39, 36, 45);"));
        databaseButton = new QPushButton(DatabaseButton);
        databaseButton->setObjectName(QStringLiteral("databaseButton"));
        databaseButton->setGeometry(QRect(0, 3, 231, 53));
        databaseButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;\n"
"border-top:5px;\n"
"}"));
        databaseButton->setCheckable(true);
        databaseButton->setChecked(true);
        settingsButton = new QPushButton(DatabaseButton);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        settingsButton->setGeometry(QRect(50, 155, 180, 50));
        settingsButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"border-right: 5px;\n"
"}"));
        deleteButton = new QPushButton(DatabaseButton);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(50, 55, 180, 50));
        deleteButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"border-right: 5px;\n"
"}"));
        dashBoard = new QPushButton(DatabaseButton);
        dashBoard->setObjectName(QStringLiteral("dashBoard"));
        dashBoard->setGeometry(QRect(50, 105, 180, 50));
        dashBoard->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"border-right: 5px;\n"
"}"));
        label = new QLabel(DatabaseButton);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 230, 3));
        label->setStyleSheet(QStringLiteral("background-color: rgb(68, 158, 241);"));

        retranslateUi(DatabaseButton);

        QMetaObject::connectSlotsByName(DatabaseButton);
    } // setupUi

    void retranslateUi(QWidget *DatabaseButton)
    {
        DatabaseButton->setWindowTitle(QApplication::translate("DatabaseButton", "Form", nullptr));
        databaseButton->setText(QApplication::translate("DatabaseButton", "_DatabaseNameHolder", nullptr));
        settingsButton->setText(QApplication::translate("DatabaseButton", "Settings", nullptr));
        deleteButton->setText(QApplication::translate("DatabaseButton", "Close", nullptr));
        dashBoard->setText(QApplication::translate("DatabaseButton", "Dashboard", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DatabaseButton: public Ui_DatabaseButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEBUTTON_H
