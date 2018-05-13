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
    void setSavingStatus(const QString &text, int value);
    void setStatusHidden(bool hidden);
    void setDatabaseNumber(unsigned int number);

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
    void modified(BlueWidget *W);
    void closing();

protected:
       void mousePressEvent(QMouseEvent *evt)
       {
           oldPos = evt->globalPos();
       }

       void mouseMoveEvent(QMouseEvent *evt)
       {
           const QPoint delta = evt->globalPos() - oldPos;
           move(x()+delta.x(), y()+delta.y());
           oldPos = evt->globalPos();
       }

private:
    Ui::MainWindow *ui;
    DatabaseOpener *opener = nullptr;
    DatabaseCreator *creator = nullptr;
    DatabaseSettings *settings = nullptr;
    CustomShadowEffect *bodyShadow = nullptr;
    CustomShadowEffect *bodyShadow2 = nullptr;
    CustomShadowEffect *bodyShadow3 = nullptr;

    QPoint oldPos;
};

#endif // MAINWINDOW_H
