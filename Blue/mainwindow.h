#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMouseEvent>
#include "BlueCrypto/aesmodule.h"
#include "MainwindowWidgets/bluedialog.h"
#include "DBMainComponents/bluedbmanager.h"
#include "BlueCrypto/blueiointerface.h"
#include "MainwindowWidgets/databaseopener.h"
#include "MainwindowWidgets/customshadoweffect.h"
#include "MainwindowWidgets/databasecreator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //BlueManager connects
    void displayGeneralError(const QString &err);

public slots:
    //Database related SLOTS
    void openDatabase();
    void openerReturn();
    void openerClose();

    void createDatabase();


signals:
    void openingRequest(QString masterKey, QString filePath);


private slots:
    //Beautifulness UI related SLOTS
    void switchButtonStatus();

    //Database related SLOTS
    void loadDatabase(const QUrl &url);



    void displayWidget(BlueWidget *w);
    void error(QString err);
    void write();
    void read(DBParameters param);

protected:


private:
    Ui::MainWindow *ui;
    BlueDBManager *manager = nullptr;
    DatabaseOpener *opener = nullptr;
    DatabaseCreator *creator = nullptr;
};

#endif // MAINWINDOW_H
