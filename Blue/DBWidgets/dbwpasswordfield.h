#ifndef DBWPASSWORDFIELD_H
#define DBWPASSWORDFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "DBElements/abstractdatabaseitem.h"
#include "DBElements/dbpasswordfield.h"
#include "MainwindowWidgets/expirationwidget.h"
#include "MainwindowWidgets/bluedialog.h"

namespace Ui {
class DBWPasswordField;
}

class DBWPasswordField : public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWPasswordField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWPasswordField();

protected:
    void resizeEvent(QResizeEvent *event);

public slots:
    void removeWidget();
    void expiredDate();
    void changeExpirationState();

private:
    Ui::DBWPasswordField *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
    ExpirationWidget *expiration = nullptr;
};

#endif // DBWPASSWORDFIELD_H
