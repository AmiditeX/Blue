#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BlueCrypto/aesmodule.h"
#include "bluedbmanager.h"
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

    void error(QString err);
    void write();
    void read(DBParameters param);

private:
    BlueIOInterface i;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
