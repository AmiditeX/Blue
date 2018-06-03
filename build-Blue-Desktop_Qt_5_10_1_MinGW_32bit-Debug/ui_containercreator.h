/********************************************************************************
** Form generated from reading UI file 'containercreator.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTAINERCREATOR_H
#define UI_CONTAINERCREATOR_H

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

class Ui_ContainerCreator
{
public:
    QLabel *colorLabel;
    QPushButton *colorSelector;
    QLineEdit *containerTitle;
    QPushButton *colorSelectorText;
    QLabel *colorLabel2;
    QPushButton *close;
    QPushButton *ok;

    void setupUi(QWidget *ContainerCreator)
    {
        if (ContainerCreator->objectName().isEmpty())
            ContainerCreator->setObjectName(QStringLiteral("ContainerCreator"));
        ContainerCreator->resize(352, 177);
        ContainerCreator->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        colorLabel = new QLabel(ContainerCreator);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));
        colorLabel->setGeometry(QRect(10, 50, 121, 25));
        colorLabel->setStyleSheet(QStringLiteral("background-color: rgb(59, 118, 239);"));
        colorSelector = new QPushButton(ContainerCreator);
        colorSelector->setObjectName(QStringLiteral("colorSelector"));
        colorSelector->setGeometry(QRect(140, 50, 201, 25));
        colorSelector->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(117, 80, 123);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(92, 53, 102);\n"
"}"));
        containerTitle = new QLineEdit(ContainerCreator);
        containerTitle->setObjectName(QStringLiteral("containerTitle"));
        containerTitle->setGeometry(QRect(10, 10, 331, 25));
        containerTitle->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:0px"));
        containerTitle->setMaxLength(200);
        colorSelectorText = new QPushButton(ContainerCreator);
        colorSelectorText->setObjectName(QStringLiteral("colorSelectorText"));
        colorSelectorText->setGeometry(QRect(140, 90, 201, 25));
        colorSelectorText->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(117, 80, 123);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(92, 53, 102);\n"
"}"));
        colorLabel2 = new QLabel(ContainerCreator);
        colorLabel2->setObjectName(QStringLiteral("colorLabel2"));
        colorLabel2->setGeometry(QRect(10, 90, 121, 25));
        colorLabel2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        close = new QPushButton(ContainerCreator);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(140, 140, 201, 25));
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
        ok = new QPushButton(ContainerCreator);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(10, 140, 121, 25));
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

        retranslateUi(ContainerCreator);

        QMetaObject::connectSlotsByName(ContainerCreator);
    } // setupUi

    void retranslateUi(QWidget *ContainerCreator)
    {
        ContainerCreator->setWindowTitle(QApplication::translate("ContainerCreator", "Form", nullptr));
        colorLabel->setText(QString());
        colorSelector->setText(QApplication::translate("ContainerCreator", "Background color", nullptr));
        containerTitle->setText(QString());
        containerTitle->setPlaceholderText(QApplication::translate("ContainerCreator", "Title..", nullptr));
        colorSelectorText->setText(QApplication::translate("ContainerCreator", "Text color", nullptr));
        colorLabel2->setText(QString());
        close->setText(QApplication::translate("ContainerCreator", "Close", nullptr));
        ok->setText(QApplication::translate("ContainerCreator", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContainerCreator: public Ui_ContainerCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTAINERCREATOR_H
