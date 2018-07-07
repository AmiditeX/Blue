#ifndef DBWPASSWORDFIELD_H
#define DBWPASSWORDFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "DBElements/abstractdatabaseitem.h"
#include "DBElements/dbpasswordfield.h"
#include "MainwindowWidgets/expirationwidget.h"
#include "MainwindowWidgets/bluedialog.h"
#include "MainwindowWidgets/passwordcreator.h"

namespace Ui {
class DBWPasswordField;
}

class DBWPasswordField : public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWPasswordField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWPasswordField();

    std::shared_ptr<AbstractDataBaseItem> getAbstractItem() override;

protected:
    void resizeEvent(QResizeEvent *event);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

public slots:
    void removeWidget();
    void expiredDate();
    void changeExpirationState();

private:
    Ui::DBWPasswordField *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
    ExpirationWidget *expiration = nullptr;
    PasswordCreator *creator = nullptr;
};

#endif // DBWPASSWORDFIELD_H
