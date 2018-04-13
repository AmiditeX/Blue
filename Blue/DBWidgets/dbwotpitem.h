#ifndef DBWOTPITEM_H
#define DBWOTPITEM_H

#include <QWidget>
#include "abstractdbwidget.h"

namespace Ui {
class DBWOtpItem;
}

class DBWOtpItem : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWOtpItem(QWidget *parent = 0);
    ~DBWOtpItem();

private:
    Ui::DBWOtpItem *ui;

};

#endif // DBWOTPITEM_H
