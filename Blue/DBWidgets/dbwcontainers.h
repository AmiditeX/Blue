#ifndef DBWCONTAINERS_H
#define DBWCONTAINERS_H

#include <QWidget>
#include "abstractdbwidget.h"

namespace Ui {
class DBWContainers;
}

class DBWContainers : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWContainers(QWidget *parent = 0);
    ~DBWContainers();

private:
    Ui::DBWContainers *ui;

};

#endif // DBWCONTAINERS_H
