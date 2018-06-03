/********************************************************************************
** Form generated from reading UI file 'dbwcontainers.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWCONTAINERS_H
#define UI_DBWCONTAINERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBWContainers
{
public:
    QPushButton *containerButton;
    QPushButton *close;
    QPushButton *edit;
    QPushButton *add;
    QListWidget *widgetList;

    void setupUi(QWidget *DBWContainers)
    {
        if (DBWContainers->objectName().isEmpty())
            DBWContainers->setObjectName(QStringLiteral("DBWContainers"));
        DBWContainers->resize(830, 190);
        DBWContainers->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        containerButton = new QPushButton(DBWContainers);
        containerButton->setObjectName(QStringLiteral("containerButton"));
        containerButton->setGeometry(QRect(0, 0, 831, 50));
        containerButton->setStyleSheet(QLatin1String("QPushButton\n"
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
        containerButton->setCheckable(true);
        containerButton->setChecked(false);
        close = new QPushButton(DBWContainers);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(740, 10, 81, 31));
        close->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(46, 52, 54);\n"
"}"));
        edit = new QPushButton(DBWContainers);
        edit->setObjectName(QStringLiteral("edit"));
        edit->setGeometry(QRect(650, 10, 81, 31));
        edit->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(46, 52, 54);\n"
"}"));
        add = new QPushButton(DBWContainers);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(10, 10, 141, 31));
        add->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(46, 52, 54);\n"
"}"));
        widgetList = new QListWidget(DBWContainers);
        widgetList->setObjectName(QStringLiteral("widgetList"));
        widgetList->setGeometry(QRect(0, 50, 830, 190));
        widgetList->setStyleSheet(QLatin1String("QListWidget::item\n"
"{\n"
"    background-color: rgb(44, 44, 52); \n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    background-color: rgb(44, 44, 52);\n"
"}"));
        widgetList->setFrameShape(QFrame::NoFrame);
        widgetList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        widgetList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        widgetList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        widgetList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        widgetList->setProperty("showDropIndicator", QVariant(false));
        widgetList->setDragDropMode(QAbstractItemView::NoDragDrop);
        widgetList->setDefaultDropAction(Qt::IgnoreAction);
        widgetList->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        widgetList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        widgetList->setMovement(QListView::Static);
        widgetList->setResizeMode(QListView::Adjust);

        retranslateUi(DBWContainers);

        QMetaObject::connectSlotsByName(DBWContainers);
    } // setupUi

    void retranslateUi(QWidget *DBWContainers)
    {
        DBWContainers->setWindowTitle(QApplication::translate("DBWContainers", "Form", nullptr));
        containerButton->setText(QApplication::translate("DBWContainers", "__ContainerNameHolder", nullptr));
        close->setText(QApplication::translate("DBWContainers", "Delete", nullptr));
        edit->setText(QApplication::translate("DBWContainers", "Edit", nullptr));
        add->setText(QApplication::translate("DBWContainers", "Add widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBWContainers: public Ui_DBWContainers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWCONTAINERS_H
