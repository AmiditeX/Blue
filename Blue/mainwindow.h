#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMouseEvent>
#include <QListWidget>
#include <QPropertyAnimation>
#include "DBMainComponents/bluedbmanager.h"
#include "MainwindowWidgets/bluedialog.h"
#include "MainwindowWidgets/databaseopener.h"
#include "MainwindowWidgets/customshadoweffect.h"
#include "MainwindowWidgets/databasecreator.h"
#include "MainwindowWidgets/databasebutton.h"
#include "MainwindowWidgets/databasesettings.h"

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
    void creatorReturn();
    void creatorClose();
    void settingsReturn();
    void settingsClose();

    //Beautifulness UI related SLOTS
    void switchButtonStatus();

    //Database related SLOTS
    void displayWidget(BlueWidget *w, const QString &path);
    void error(QString err);
    void write();
    void read(DBParameters param);

signals:
    void openingRequest(QString masterKey, QString filePath, QString keyPath);
    void createRequest(DatabaseCreator::DatabaseParam parameters);
    void closeRequest(BlueWidget *w);
    void settingsChanged(BlueWidget *w, DatabaseSettings::DatabaseParam param);

protected:


private:
    Ui::MainWindow *ui;
    DatabaseOpener *opener = nullptr;
    DatabaseCreator *creator = nullptr;
    DatabaseSettings *settings = nullptr;
};

#endif // MAINWINDOW_H
