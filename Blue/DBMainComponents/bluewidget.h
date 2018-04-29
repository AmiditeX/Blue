#ifndef BLUEWIDGET_H
#define BLUEWIDGET_H

#include <QWidget>
#include <QVector>
#include <vector>
#include <memory>
#include "DBWidgets/dbwcontainers.h"
#include "DBMainComponents/bluedatabase.h"

namespace Ui {
class BlueWidget;
}

class BlueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BlueWidget(std::shared_ptr<BlueDatabase> databasePointer = nullptr);
    ~BlueWidget();

private:
    Ui::BlueWidget *ui;

    std::shared_ptr<BlueDatabase> _dataBase;
    std::vector<DBWContainers*> _containers;

};

#endif // BLUEWIDGET_H
