/********************************************************************************
** Form generated from reading UI file 'bluedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUEDIALOG_H
#define UI_BLUEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlueDialog
{
public:
    QPushButton *ok;
    QPushButton *close;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;

    void setupUi(QWidget *BlueDialog)
    {
        if (BlueDialog->objectName().isEmpty())
            BlueDialog->setObjectName(QStringLiteral("BlueDialog"));
        BlueDialog->resize(600, 175);
        BlueDialog->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        ok = new QPushButton(BlueDialog);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(370, 10, 111, 25));
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
        close = new QPushButton(BlueDialog);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(490, 10, 101, 25));
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
        plainTextEdit = new QPlainTextEdit(BlueDialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 50, 571, 111));
        plainTextEdit->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"background-color: rgb(44, 44, 52);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setReadOnly(true);
        label = new QLabel(BlueDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 15, 351, 17));
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font-weight: bold"));

        retranslateUi(BlueDialog);

        QMetaObject::connectSlotsByName(BlueDialog);
    } // setupUi

    void retranslateUi(QWidget *BlueDialog)
    {
        BlueDialog->setWindowTitle(QApplication::translate("BlueDialog", "Notification", nullptr));
        ok->setText(QApplication::translate("BlueDialog", "OK", nullptr));
        close->setText(QApplication::translate("BlueDialog", "Close", nullptr));
        plainTextEdit->setPlainText(QApplication::translate("BlueDialog", "_DefaultText\n"
"", nullptr));
        label->setText(QApplication::translate("BlueDialog", "_DefaultText", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlueDialog: public Ui_BlueDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUEDIALOG_H
