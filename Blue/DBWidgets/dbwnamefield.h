#ifndef DBWNAMEFIELD_H
#define DBWNAMEFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "DBElements/abstractdatabaseitem.h"

namespace Ui {
class DBWNameField;
}

class DBWNameField : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWNameField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWNameField();

private:
    Ui::DBWNameField *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
};

#endif // DBWNAMEFIELD_H
