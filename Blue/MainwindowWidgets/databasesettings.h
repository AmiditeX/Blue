#ifndef DATABASESETTINGS_H
#define DATABASESETTINGS_H

#include <QWidget>
#include <QFileDialog>
#include "DBMainComponents/bluewidget.h"
#include "MainwindowWidgets/passwordcreator.h"
#include "MainwindowWidgets/customshadoweffect.h"

namespace Ui {
class DatabaseSettings;
}

class DatabaseSettings : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseSettings(QWidget *parent = 0);
    ~DatabaseSettings();

    struct DatabaseParam
    {
        QString dbPath;
        QString keyPath;
        QString password;
        int iterations;
        int stretchTime;
    };

    DatabaseParam returnParams();
    void setParams(DatabaseParam param);
    void clear();

    void setCurrentDatabase(BlueWidget *ptr);
    BlueWidget* getCurrentDatabase();

public slots:
    void openDbSelector();
    void openKeySelector();
    void changeSize(bool expanded);

signals:
    void okPressed();
    void closePressed();

private:
    Ui::DatabaseSettings *ui;
    PasswordCreator *creator = nullptr;
    CustomShadowEffect *bodyShadow = nullptr;
    BlueWidget *_currentDatabase = nullptr;
};

#endif // DATABASESETTINGS_H
