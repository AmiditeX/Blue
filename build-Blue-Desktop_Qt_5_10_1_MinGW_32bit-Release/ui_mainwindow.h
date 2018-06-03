/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *databaseTab;
    QPushButton *buttonOpen;
    QPushButton *buttonCreate;
    QListWidget *listDatabase;
    QLabel *downColor;
    QLabel *downBar;
    QLabel *textOpenDatabase;
    QProgressBar *progressBar;
    QLabel *textStatus;
    QLabel *blueVersion;
    QLabel *shadow;
    QLabel *blueLabel;
    QLabel *shadow2;
    QPushButton *close;
    QPushButton *minimize;
    QFrame *moveWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1350, 800);
        MainWindow->setMinimumSize(QSize(560, 0));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        databaseTab = new QTabWidget(centralWidget);
        databaseTab->setObjectName(QStringLiteral("databaseTab"));
        databaseTab->setGeometry(QRect(280, 50, 1040, 700));
        databaseTab->setStyleSheet(QLatin1String("border:0px;\n"
"QTabWidget::pane { border: 0px; }"));
        databaseTab->setTabPosition(QTabWidget::West);
        databaseTab->setTabShape(QTabWidget::Triangular);
        databaseTab->setDocumentMode(true);
        databaseTab->setTabBarAutoHide(true);
        buttonOpen = new QPushButton(centralWidget);
        buttonOpen->setObjectName(QStringLiteral("buttonOpen"));
        buttonOpen->setGeometry(QRect(0, 50, 230, 50));
        buttonOpen->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}\n"
""));
        buttonOpen->setCheckable(true);
        buttonCreate = new QPushButton(centralWidget);
        buttonCreate->setObjectName(QStringLiteral("buttonCreate"));
        buttonCreate->setGeometry(QRect(0, 100, 230, 50));
        buttonCreate->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border:0px;\n"
"background-color: rgb(34, 35, 40);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold\n"
"}"));
        buttonCreate->setCheckable(true);
        listDatabase = new QListWidget(centralWidget);
        listDatabase->setObjectName(QStringLiteral("listDatabase"));
        listDatabase->setGeometry(QRect(0, 150, 230, 625));
        listDatabase->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"	background-color: rgb(39, 36, 45);\n"
"}\n"
"\n"
"QListWidget::item\n"
"{\n"
"    background-color: rgb(39, 36, 45);\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    background-color: rgb(44, 44, 52);\n"
"}"));
        listDatabase->setFrameShape(QFrame::NoFrame);
        listDatabase->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listDatabase->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listDatabase->setAutoScrollMargin(16);
        listDatabase->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listDatabase->setProperty("showDropIndicator", QVariant(false));
        listDatabase->setDragDropMode(QAbstractItemView::NoDragDrop);
        listDatabase->setDefaultDropAction(Qt::IgnoreAction);
        listDatabase->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listDatabase->setMovement(QListView::Static);
        listDatabase->setResizeMode(QListView::Adjust);
        downColor = new QLabel(centralWidget);
        downColor->setObjectName(QStringLiteral("downColor"));
        downColor->setGeometry(QRect(0, 775, 1350, 3));
        downColor->setStyleSheet(QStringLiteral("background-color: rgb(68, 158, 241);"));
        downBar = new QLabel(centralWidget);
        downBar->setObjectName(QStringLiteral("downBar"));
        downBar->setGeometry(QRect(0, 775, 1350, 25));
        downBar->setStyleSheet(QStringLiteral("background-color: rgb(34, 35, 40);"));
        textOpenDatabase = new QLabel(centralWidget);
        textOpenDatabase->setObjectName(QStringLiteral("textOpenDatabase"));
        textOpenDatabase->setGeometry(QRect(10, 781, 221, 17));
        textOpenDatabase->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 8pt \"DejaVu Sans\";\n"
"background-color: rgb(34, 35, 40);"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(1040, 785, 210, 10));
        progressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:0px;\n"
"font: 8pt \"DejaVu Sans\";\n"
"}\n"
"QProgressBar::chunk \n"
"{\n"
"	background-color:  rgb(68, 158, 241);\n"
"	width: 20px; \n"
"}"));
        progressBar->setMaximum(30);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        textStatus = new QLabel(centralWidget);
        textStatus->setObjectName(QStringLiteral("textStatus"));
        textStatus->setGeometry(QRect(930, 782, 100, 15));
        textStatus->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 8pt \"DejaVu Sans\";\n"
"background-color: rgb(34, 35, 40);"));
        blueVersion = new QLabel(centralWidget);
        blueVersion->setObjectName(QStringLiteral("blueVersion"));
        blueVersion->setGeometry(QRect(1290, 781, 60, 17));
        blueVersion->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 8pt \"DejaVu Sans\";\n"
"background-color: rgb(34, 35, 40);"));
        shadow = new QLabel(centralWidget);
        shadow->setObjectName(QStringLiteral("shadow"));
        shadow->setGeometry(QRect(280, 50, 1040, 700));
        shadow->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 52);"));
        blueLabel = new QLabel(centralWidget);
        blueLabel->setObjectName(QStringLiteral("blueLabel"));
        blueLabel->setGeometry(QRect(0, 0, 230, 51));
        blueLabel->setStyleSheet(QLatin1String("background-color: rgb(68, 158, 241);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 22pt \"DejaVu Sans\";\n"
"font-weight: bold"));
        shadow2 = new QLabel(centralWidget);
        shadow2->setObjectName(QStringLiteral("shadow2"));
        shadow2->setGeometry(QRect(0, 0, 230, 800));
        shadow2->setStyleSheet(QStringLiteral(""));
        close = new QPushButton(centralWidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(1290, 0, 60, 25));
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
        minimize = new QPushButton(centralWidget);
        minimize->setObjectName(QStringLiteral("minimize"));
        minimize->setGeometry(QRect(1230, 0, 60, 25));
        minimize->setStyleSheet(QLatin1String("QPushButton\n"
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
        moveWindow = new QFrame(centralWidget);
        moveWindow->setObjectName(QStringLiteral("moveWindow"));
        moveWindow->setGeometry(QRect(0, 0, 1231, 51));
        moveWindow->setStyleSheet(QStringLiteral("background-color: transparent;"));
        moveWindow->setFrameShape(QFrame::NoFrame);
        moveWindow->setFrameShadow(QFrame::Plain);
        MainWindow->setCentralWidget(centralWidget);
        moveWindow->raise();
        shadow2->raise();
        listDatabase->raise();
        shadow->raise();
        buttonCreate->raise();
        buttonOpen->raise();
        databaseTab->raise();
        downBar->raise();
        close->raise();
        minimize->raise();
        downColor->raise();
        textOpenDatabase->raise();
        progressBar->raise();
        textStatus->raise();
        blueVersion->raise();
        blueLabel->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Blue", nullptr));
        buttonOpen->setText(QApplication::translate("MainWindow", "Open database", nullptr));
        buttonCreate->setText(QApplication::translate("MainWindow", "Create database", nullptr));
        downColor->setText(QString());
        downBar->setText(QString());
        textOpenDatabase->setText(QApplication::translate("MainWindow", "Open database : 0", nullptr));
        progressBar->setFormat(QApplication::translate("MainWindow", "0s", nullptr));
        textStatus->setText(QApplication::translate("MainWindow", "_Holder_", nullptr));
        blueVersion->setText(QApplication::translate("MainWindow", "Blue v1.0", nullptr));
        shadow->setText(QString());
        blueLabel->setText(QApplication::translate("MainWindow", "        Blue", nullptr));
        shadow2->setText(QString());
        close->setText(QApplication::translate("MainWindow", "X", nullptr));
        minimize->setText(QApplication::translate("MainWindow", "\342\224\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
