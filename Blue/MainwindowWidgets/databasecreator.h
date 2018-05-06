#ifndef DATABASECREATOR_H
#define DATABASECREATOR_H

#include <QWidget>
#include <QFileDialog>
#include "MainwindowWidgets/passwordcreator.h"
#include "MainwindowWidgets/customshadoweffect.h"

namespace Ui {
class DatabaseCreator;
}

class DatabaseCreator : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseCreator(QWidget *parent = 0);
    ~DatabaseCreator();

    struct DatabaseParam
    {
        QString dbPath;
        QString keyPath;
        QString password;
        int iterations;
        int stretchTime;
    };

    DatabaseParam returnParams();
    void clear();

public slots:
    void openDbSelector();
    void openKeySelector();
    void changeSize(bool expanded);

signals:
    void okPressed();
    void closePressed();

private:
    Ui::DatabaseCreator *ui;
    PasswordCreator *creator = nullptr;
    CustomShadowEffect *bodyShadow = nullptr;
};

#endif // DATABASECREATOR_H
