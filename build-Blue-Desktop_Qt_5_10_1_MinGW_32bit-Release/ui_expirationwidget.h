/********************************************************************************
** Form generated from reading UI file 'expirationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPIRATIONWIDGET_H
#define UI_EXPIRATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpirationWidget
{
public:
    QDateTimeEdit *dateTime;
    QCheckBox *expirationToggle;
    QLabel *label_5;

    void setupUi(QWidget *ExpirationWidget)
    {
        if (ExpirationWidget->objectName().isEmpty())
            ExpirationWidget->setObjectName(QStringLiteral("ExpirationWidget"));
        ExpirationWidget->resize(830, 46);
        ExpirationWidget->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        dateTime = new QDateTimeEdit(ExpirationWidget);
        dateTime->setObjectName(QStringLiteral("dateTime"));
        dateTime->setGeometry(QRect(10, 10, 231, 26));
        dateTime->setStyleSheet(QLatin1String("QDateTimeEdit {\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:0px\n"
"}\n"
"QDateTimeEdit::up-button {\n"
"background-color: rgb(115, 210, 22);\n"
"}\n"
"\n"
"QDateTimeEdit::down-button {\n"
"background-color: rgb(239, 41, 41);\n"
"}"));
        dateTime->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        dateTime->setMaximumDateTime(QDateTime(QDate(7999, 1, 28), QTime(23, 59, 59)));
        dateTime->setMinimumDateTime(QDateTime(QDate(1752, 9, 14), QTime(0, 0, 0)));
        dateTime->setCalendarPopup(true);
        dateTime->setTimeSpec(Qt::LocalTime);
        expirationToggle = new QCheckBox(ExpirationWidget);
        expirationToggle->setObjectName(QStringLiteral("expirationToggle"));
        expirationToggle->setGeometry(QRect(250, 12, 161, 23));
        expirationToggle->setStyleSheet(QLatin1String("QCheckBox {\n"
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
        label_5 = new QLabel(ExpirationWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(420, 10, 391, 31));
        label_5->setStyleSheet(QLatin1String("background-color: rgb(44, 44, 52); \n"
"color: rgb(255, 255, 255);\n"
"font: 8pt \"DejaVu Sans\";"));

        retranslateUi(ExpirationWidget);

        QMetaObject::connectSlotsByName(ExpirationWidget);
    } // setupUi

    void retranslateUi(QWidget *ExpirationWidget)
    {
        ExpirationWidget->setWindowTitle(QApplication::translate("ExpirationWidget", "Form", nullptr));
        dateTime->setDisplayFormat(QApplication::translate("ExpirationWidget", "dd/MM/yyyy hh:mm", nullptr));
        expirationToggle->setText(QApplication::translate("ExpirationWidget", "Enable expiration", nullptr));
        label_5->setText(QApplication::translate("ExpirationWidget", "Set an expiration date to be reminded to change a password or any\n"
" expirable information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpirationWidget: public Ui_ExpirationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPIRATIONWIDGET_H
