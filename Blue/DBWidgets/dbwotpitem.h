#ifndef DBWOTPITEM_H
#define DBWOTPITEM_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "MainwindowWidgets/expirationwidget.h"
#include "MainwindowWidgets/bluedialog.h"
#include "DBElements/abstractdatabaseitem.h"
#include "DBElements/dbotpitem.h"

namespace Ui {
class DBWOtpItem;
}

class DBWOtpItem : public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWOtpItem(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWOtpItem();

protected:
    //void resizeEvent(QResizeEvent *event);

public slots:
    /*void removeWidget();
    void expiredDate();
    void changeExpirationState();*/
    void calculateTotp();

private:
    Ui::DBWOtpItem *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
    QString _totpKey;
};

#endif // DBWOTPITEM_H
