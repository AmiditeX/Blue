#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BlueCrypto/aesmodule.h"
#include "DBMainComponents/bluedbmanager.h"
#include "BlueCrypto/blueiointerface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void displayWidget(BlueWidget *w);

    void error(QString err);
    void write();
    void read(DBParameters param);

private slots:
    //Beautifulness UI related SLOTS
    void switchButtonStatus();

private:
    Ui::MainWindow *ui;
    BlueDBManager *manager;
};

#endif // MAINWINDOW_H
