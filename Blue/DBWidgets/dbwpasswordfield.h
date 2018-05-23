#ifndef DBWPASSWORDFIELD_H
#define DBWPASSWORDFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "DBElements/abstractdatabaseitem.h"

namespace Ui {
class DBWPasswordField;
}

class DBWPasswordField : public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWPasswordField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWPasswordField();

private:
    Ui::DBWPasswordField *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
};

#endif // DBWPASSWORDFIELD_H
