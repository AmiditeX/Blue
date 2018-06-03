/********************************************************************************
** Form generated from reading UI file 'databasecreator.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASECREATOR_H
#define UI_DATABASECREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseCreator
{
public:
    QPushButton *openKey;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QWidget *widget;
    QPushButton *close;
    QPushButton *ok;
    QPushButton *open;
    QLineEdit *database;
    QLineEdit *key;
    QLabel *label_4;
    QSpinBox *stretchTime;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *iterationTime;
    QLabel *label_7;

    void setupUi(QWidget *DatabaseCreator)
    {
        if (DatabaseCreator->objectName().isEmpty())
            DatabaseCreator->setObjectName(QStringLiteral("DatabaseCreator"));
        DatabaseCreator->resize(1080, 750);
        DatabaseCreator->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        openKey = new QPushButton(DatabaseCreator);
        openKey->setObjectName(QStringLiteral("openKey"));
        openKey->setGeometry(QRect(730, 210, 71, 25));
        openKey->setStyleSheet(QLatin1String("QPushButton\n"
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
        label_2 = new QLabel(DatabaseCreator);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 70, 141, 51));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(68, 158, 241);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 22pt \"DejaVu Sans\";\n"
"font-weight: bold"));
        label_3 = new QLabel(DatabaseCreator);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(380, 70, 431, 51));
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 16pt \"DejaVu Sans\";\n"
"background-color: rgb(20, 20, 20);"));
        label = new QLabel(DatabaseCreator);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 70, 571, 611));
        label->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        label->setFrameShape(QFrame::NoFrame);
        label->setLineWidth(1);
        widget = new QWidget(DatabaseCreator);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(240, 360, 571, 281));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        close = new QPushButton(widget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(300, 120, 101, 25));
        close->setStyleSheet(QLatin1String("QPushButton\n"
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
        ok = new QPushButton(widget);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(180, 120, 111, 25));
        ok->setStyleSheet(QLatin1String("QPushButton\n"
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
        open = new QPushButton(DatabaseCreator);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(730, 140, 71, 25));
        open->setStyleSheet(QLatin1String("QPushButton\n"
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
        database = new QLineEdit(DatabaseCreator);
        database->setObjectName(QStringLiteral("database"));
        database->setGeometry(QRect(250, 140, 471, 25));
        database->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        database->setMaxLength(10000);
        key = new QLineEdit(DatabaseCreator);
        key->setObjectName(QStringLiteral("key"));
        key->setGeometry(QRect(250, 210, 471, 25));
        key->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        key->setMaxLength(10000);
        label_4 = new QLabel(DatabaseCreator);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 170, 431, 31));
        label_4->setStyleSheet(QLatin1String("background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font: 8pt \"DejaVu Sans\";"));
        stretchTime = new QSpinBox(DatabaseCreator);
        stretchTime->setObjectName(QStringLiteral("stretchTime"));
        stretchTime->setGeometry(QRect(620, 250, 101, 26));
        stretchTime->setStyleSheet(QLatin1String("QSpinBox {\n"
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
        stretchTime->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        stretchTime->setMinimum(1);
        stretchTime->setMaximum(999999999);
        stretchTime->setValue(2);
        label_5 = new QLabel(DatabaseCreator);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 250, 331, 31));
        label_5->setStyleSheet(QLatin1String("background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font: 8pt \"DejaVu Sans\";"));
        label_6 = new QLabel(DatabaseCreator);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(250, 290, 331, 41));
        label_6->setStyleSheet(QLatin1String("background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font: 8pt \"DejaVu Sans\";"));
        iterationTime = new QSpinBox(DatabaseCreator);
        iterationTime->setObjectName(QStringLiteral("iterationTime"));
        iterationTime->setGeometry(QRect(620, 300, 101, 26));
        iterationTime->setStyleSheet(QLatin1String("QSpinBox {\n"
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
        iterationTime->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        iterationTime->setMinimum(0);
        iterationTime->setMaximum(999999999);
        iterationTime->setValue(0);
        label_7 = new QLabel(DatabaseCreator);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(660, 276, 21, 21));
        label_7->setStyleSheet(QLatin1String("background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font: 8pt \"DejaVu Sans\";"));
        label->raise();
        openKey->raise();
        label_2->raise();
        label_3->raise();
        widget->raise();
        open->raise();
        database->raise();
        key->raise();
        label_4->raise();
        stretchTime->raise();
        label_5->raise();
        label_6->raise();
        iterationTime->raise();
        label_7->raise();

        retranslateUi(DatabaseCreator);

        QMetaObject::connectSlotsByName(DatabaseCreator);
    } // setupUi

    void retranslateUi(QWidget *DatabaseCreator)
    {
        DatabaseCreator->setWindowTitle(QApplication::translate("DatabaseCreator", "Form", nullptr));
        openKey->setText(QApplication::translate("DatabaseCreator", "Open", nullptr));
        label_2->setText(QApplication::translate("DatabaseCreator", "   Blue", nullptr));
        label_3->setText(QApplication::translate("DatabaseCreator", "                    Create database", nullptr));
        label->setText(QString());
        close->setText(QApplication::translate("DatabaseCreator", "Close", nullptr));
        ok->setText(QApplication::translate("DatabaseCreator", "Create", nullptr));
        open->setText(QApplication::translate("DatabaseCreator", "Open", nullptr));
        database->setText(QString());
        database->setPlaceholderText(QApplication::translate("DatabaseCreator", "Path of the database..", nullptr));
        key->setText(QString());
        key->setPlaceholderText(QApplication::translate("DatabaseCreator", "Path to key..", nullptr));
        label_4->setText(QApplication::translate("DatabaseCreator", "You can add any file as a key, as long as it is never modified and not empty\n"
"It is needed for decryption and has to be provided to open the database.", nullptr));
        stretchTime->setSuffix(QApplication::translate("DatabaseCreator", " sec", nullptr));
        label_5->setText(QApplication::translate("DatabaseCreator", "Stretch time (time taken to open the database)\n"
"Prevents effectiveness of bruteforce attacks ", nullptr));
        label_6->setText(QApplication::translate("DatabaseCreator", "Number of iterations made to open the database\n"
"Prevents effectiveness of bruteforce attacks\n"
"Don't use this parameter if you're not familiar with it", nullptr));
        iterationTime->setSuffix(QString());
        label_7->setText(QApplication::translate("DatabaseCreator", "or", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseCreator: public Ui_DatabaseCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASECREATOR_H
