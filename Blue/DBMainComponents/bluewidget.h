#ifndef BLUEWIDGET_H
#define BLUEWIDGET_H

#include <QWidget>
#include <QVector>
#include <vector>
#include <memory>
#include <algorithm>
#include <QColorDialog>
#include <QListWidgetItem>
#include <QPropertyAnimation>
#include "DBWidgets/dbwcontainers.h"
#include "DBMainComponents/bluedatabase.h"
#include "MainwindowWidgets/containercreator.h"

namespace Ui {
class BlueWidget;
}

class BlueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BlueWidget(std::shared_ptr<BlueDatabase> databasePointer = nullptr);
    ~BlueWidget();

    DBParameters returnParam();

public slots:
    void addContainer(std::shared_ptr<DBContainers> container = nullptr);
    void createNewContainer();
    void creatorReturned();

signals:
    void modified();

private:
    Ui::BlueWidget *ui;
    ContainerCreator *creator = nullptr;

    std::shared_ptr<BlueDatabase> _dataBase;
    std::vector<DBWContainers*> _containers;
};

#endif // BLUEWIDGET_H
