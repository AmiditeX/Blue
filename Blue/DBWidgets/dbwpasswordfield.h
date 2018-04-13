#ifndef DBWPASSWORDFIELD_H
#define DBWPASSWORDFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"

namespace Ui {
class DBWPasswordField;
}

class DBWPasswordField : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWPasswordField(QWidget *parent = 0);
    ~DBWPasswordField();

private:
    Ui::DBWPasswordField *ui;

};

#endif // DBWPASSWORDFIELD_H
