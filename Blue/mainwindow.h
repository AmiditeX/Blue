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
    void displayWidget(std::shared_ptr<BlueWidget>);

    void error(QString err);
    void write();
    void read(DBParameters param);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
