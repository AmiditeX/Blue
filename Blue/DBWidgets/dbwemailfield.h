#ifndef DBWEMAILFIELD_H
#define DBWEMAILFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "DBElements/abstractdatabaseitem.h"

namespace Ui {
class DBWEmailField;
}

class DBWEmailField : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWEmailField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWEmailField();

private:
    Ui::DBWEmailField *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
};

#endif // DBWEMAILFIELD_H
