/********************************************************************************
** Form generated from reading UI file 'databaseopener.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEOPENER_H
#define UI_DATABASEOPENER_H

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

class Ui_DatabaseOpener
{
public:
    QPushButton *ok;
    QLabel *label;
    QPushButton *close;
    QLineEdit *database;
    QLineEdit *master;
    QPushButton *openDatabase;
    QLineEdit *key;
    QPushButton *openKey;
    QPushButton *see;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *DatabaseOpener)
    {
        if (DatabaseOpener->objectName().isEmpty())
            DatabaseOpener->setObjectName(QStringLiteral("DatabaseOpener"));
        DatabaseOpener->resize(1080, 750);
        DatabaseOpener->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        ok = new QPushButton(DatabaseOpener);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(580, 420, 111, 25));
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
        label = new QLabel(DatabaseOpener);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 270, 571, 191));
        label->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        label->setFrameShape(QFrame::NoFrame);
        label->setLineWidth(1);
        close = new QPushButton(DatabaseOpener);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(710, 420, 101, 25));
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
        database = new QLineEdit(DatabaseOpener);
        database->setObjectName(QStringLiteral("database"));
        database->setGeometry(QRect(260, 290, 471, 25));
        database->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        database->setMaxLength(10000);
        master = new QLineEdit(DatabaseOpener);
        master->setObjectName(QStringLiteral("master"));
        master->setGeometry(QRect(260, 330, 471, 25));
        master->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        master->setMaxLength(10000);
        master->setEchoMode(QLineEdit::Password);
        openDatabase = new QPushButton(DatabaseOpener);
        openDatabase->setObjectName(QStringLiteral("openDatabase"));
        openDatabase->setGeometry(QRect(740, 290, 71, 25));
        openDatabase->setStyleSheet(QLatin1String("QPushButton\n"
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
        key = new QLineEdit(DatabaseOpener);
        key->setObjectName(QStringLiteral("key"));
        key->setGeometry(QRect(260, 370, 471, 25));
        key->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        key->setMaxLength(10000);
        openKey = new QPushButton(DatabaseOpener);
        openKey->setObjectName(QStringLiteral("openKey"));
        openKey->setGeometry(QRect(740, 370, 71, 25));
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
        see = new QPushButton(DatabaseOpener);
        see->setObjectName(QStringLiteral("see"));
        see->setGeometry(QRect(740, 330, 71, 25));
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
        label_2 = new QLabel(DatabaseOpener);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 220, 141, 51));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(68, 158, 241);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 22pt \"DejaVu Sans\";\n"
"font-weight: bold"));
        label_3 = new QLabel(DatabaseOpener);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(390, 220, 431, 51));
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 16pt \"DejaVu Sans\";\n"
"background-color: rgb(20, 20, 20);"));
        label->raise();
        ok->raise();
        close->raise();
        database->raise();
        master->raise();
        openDatabase->raise();
        key->raise();
        openKey->raise();
        see->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(DatabaseOpener);

        QMetaObject::connectSlotsByName(DatabaseOpener);
    } // setupUi

    void retranslateUi(QWidget *DatabaseOpener)
    {
        DatabaseOpener->setWindowTitle(QApplication::translate("DatabaseOpener", "Form", nullptr));
        ok->setText(QApplication::translate("DatabaseOpener", "Open", nullptr));
        label->setText(QString());
        close->setText(QApplication::translate("DatabaseOpener", "Close", nullptr));
        database->setText(QApplication::translate("DatabaseOpener", "/root/Blue/build-Blue-Desktop_Qt_5_10_0_GCC_64bit-Debug/Passwordispassword.blue", nullptr));
        database->setPlaceholderText(QApplication::translate("DatabaseOpener", "Path of the database..", nullptr));
        master->setText(QApplication::translate("DatabaseOpener", "password", nullptr));
        master->setPlaceholderText(QApplication::translate("DatabaseOpener", "Master password..", nullptr));
        openDatabase->setText(QApplication::translate("DatabaseOpener", "Open", nullptr));
        key->setText(QString());
        key->setPlaceholderText(QApplication::translate("DatabaseOpener", "Path to the key file..", nullptr));
        openKey->setText(QApplication::translate("DatabaseOpener", "Open", nullptr));
        see->setText(QApplication::translate("DatabaseOpener", "See", nullptr));
        label_2->setText(QApplication::translate("DatabaseOpener", "   Blue", nullptr));
        label_3->setText(QApplication::translate("DatabaseOpener", "                     Open database", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseOpener: public Ui_DatabaseOpener {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEOPENER_H
