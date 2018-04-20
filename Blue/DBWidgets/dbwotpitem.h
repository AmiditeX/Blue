#ifndef DBWOTPITEM_H
#define DBWOTPITEM_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "DBElements/abstractdatabaseitem.h"

namespace Ui {
class DBWOtpItem;
}

class DBWOtpItem : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWOtpItem(std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWOtpItem();

private:
    Ui::DBWOtpItem *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
};

#endif // DBWOTPITEM_H
