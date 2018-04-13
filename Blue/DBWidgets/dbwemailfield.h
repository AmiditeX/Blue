#ifndef DBWEMAILFIELD_H
#define DBWEMAILFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"

namespace Ui {
class DBWEmailField;
}

class DBWEmailField : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWEmailField(QWidget *parent = 0);
    ~DBWEmailField();

private:
    Ui::DBWEmailField *ui;

};

#endif // DBWEMAILFIELD_H
