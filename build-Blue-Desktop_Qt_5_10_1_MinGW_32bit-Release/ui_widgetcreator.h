/********************************************************************************
** Form generated from reading UI file 'widgetcreator.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCREATOR_H
#define UI_WIDGETCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WidgetCreator
{
public:
    QPushButton *add;
    QPushButton *close;
    QListWidget *widgetList;
    QLabel *label;
    QLabel *currentSelection;

    void setupUi(QDialog *WidgetCreator)
    {
        if (WidgetCreator->objectName().isEmpty())
            WidgetCreator->setObjectName(QStringLiteral("WidgetCreator"));
        WidgetCreator->resize(360, 265);
        WidgetCreator->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        add = new QPushButton(WidgetCreator);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(10, 230, 131, 25));
        add->setStyleSheet(QLatin1String("QPushButton\n"
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
        close = new QPushButton(WidgetCreator);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(150, 230, 201, 25));
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
        widgetList = new QListWidget(WidgetCreator);
        widgetList->setObjectName(QStringLiteral("widgetList"));
        widgetList->setGeometry(QRect(90, 10, 261, 161));
        widgetList->setStyleSheet(QLatin1String("QListWidget::item:clicked\n"
"{\n"
"	 background-color: rgb(114, 159, 207);\n"
"}"));
        widgetList->setFrameShape(QFrame::NoFrame);
        widgetList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        widgetList->setViewMode(QListView::ListMode);
        label = new QLabel(WidgetCreator);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 180, 151, 17));
        label->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font-weight: bold"));
        currentSelection = new QLabel(WidgetCreator);
        currentSelection->setObjectName(QStringLiteral("currentSelection"));
        currentSelection->setGeometry(QRect(10, 200, 341, 20));
        currentSelection->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236);"));

        retranslateUi(WidgetCreator);

        QMetaObject::connectSlotsByName(WidgetCreator);
    } // setupUi

    void retranslateUi(QDialog *WidgetCreator)
    {
        WidgetCreator->setWindowTitle(QApplication::translate("WidgetCreator", "Dialog", nullptr));
        add->setText(QApplication::translate("WidgetCreator", "Add", nullptr));
        close->setText(QApplication::translate("WidgetCreator", "Close", nullptr));
        label->setText(QApplication::translate("WidgetCreator", "Currently selected:", nullptr));
        currentSelection->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetCreator: public Ui_WidgetCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCREATOR_H
