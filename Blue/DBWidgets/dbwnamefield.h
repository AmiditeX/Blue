#ifndef DBWNAMEFIELD_H
#define DBWNAMEFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "MainwindowWidgets/expirationwidget.h"
#include "MainwindowWidgets/bluedialog.h"
#include "DBElements/abstractdatabaseitem.h"
#include "DBElements/dbnamefield.h"

namespace Ui {
class DBWNameField;
}

class DBWNameField : public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWNameField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWNameField();

protected:
    void resizeEvent(QResizeEvent *event);

public slots:
    void removeWidget();
    void expiredDate();
    void changeExpirationState();

private:
    Ui::DBWNameField *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
    ExpirationWidget *expiration = nullptr;
};

#endif // DBWNAMEFIELD_H
