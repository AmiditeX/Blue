/********************************************************************************
** Form generated from reading UI file 'bluewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUEWIDGET_H
#define UI_BLUEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlueWidget
{
public:
    QPushButton *addContainer;
    QListWidget *containerList;

    void setupUi(QWidget *BlueWidget)
    {
        if (BlueWidget->objectName().isEmpty())
            BlueWidget->setObjectName(QStringLiteral("BlueWidget"));
        BlueWidget->resize(1040, 700);
        BlueWidget->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        addContainer = new QPushButton(BlueWidget);
        addContainer->setObjectName(QStringLiteral("addContainer"));
        addContainer->setEnabled(true);
        addContainer->setGeometry(QRect(840, 10, 191, 25));
        addContainer->setStyleSheet(QLatin1String("QPushButton\n"
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
        containerList = new QListWidget(BlueWidget);
        containerList->setObjectName(QStringLiteral("containerList"));
        containerList->setGeometry(QRect(0, 0, 830, 700));
        containerList->setStyleSheet(QLatin1String("QListWidget::item\n"
"{\n"
"    background-color: rgb(44, 44, 52); \n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    background-color: rgb(44, 44, 52);\n"
"}"));
        containerList->setFrameShape(QFrame::NoFrame);
        containerList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        containerList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        containerList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        containerList->setProperty("showDropIndicator", QVariant(false));
        containerList->setDragDropMode(QAbstractItemView::NoDragDrop);
        containerList->setDefaultDropAction(Qt::IgnoreAction);
        containerList->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        containerList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        containerList->setMovement(QListView::Static);
        containerList->setResizeMode(QListView::Adjust);

        retranslateUi(BlueWidget);

        QMetaObject::connectSlotsByName(BlueWidget);
    } // setupUi

    void retranslateUi(QWidget *BlueWidget)
    {
        BlueWidget->setWindowTitle(QApplication::translate("BlueWidget", "Form", nullptr));
        addContainer->setText(QApplication::translate("BlueWidget", "Add container", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlueWidget: public Ui_BlueWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUEWIDGET_H
