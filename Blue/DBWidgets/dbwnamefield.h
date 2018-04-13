#ifndef DBWNAMEFIELD_H
#define DBWNAMEFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"

namespace Ui {
class DBWNameField;
}

class DBWNameField : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWNameField(QWidget *parent = 0);
    ~DBWNameField();

private:
    Ui::DBWNameField *ui;

};

#endif // DBWNAMEFIELD_H
