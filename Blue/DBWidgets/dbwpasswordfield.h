#ifndef DBWPASSWORDFIELD_H
#define DBWPASSWORDFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "DBElements/abstractdatabaseitem.h"

namespace Ui {
class DBWPasswordField;
}

class DBWPasswordField : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWPasswordField(std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWPasswordField();

private:
    Ui::DBWPasswordField *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
};

#endif // DBWPASSWORDFIELD_H
