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

    std::shared_ptr<AbstractDataBaseItem> getAbstractItem() override;

protected:
    void resizeEvent(QResizeEvent *event);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

public slots:
    void removeWidget();
    void expiredDate();
    void changeExpirationState();
    void calculateTotp();
    void setProgressStatus();

private:
    Ui::DBWOtpItem *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
    ExpirationWidget *expiration = nullptr;
    QString _totpKey;
    QTimer* _progressTimer = nullptr;
};

#endif // DBWOTPITEM_H
