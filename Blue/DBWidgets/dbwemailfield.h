#ifndef DBWEMAILFIELD_H
#define DBWEMAILFIELD_H

#include <QWidget>
#include "abstractdbwidget.h"
#include "MainwindowWidgets/expirationwidget.h"
#include "MainwindowWidgets/bluedialog.h"
#include "DBElements/abstractdatabaseitem.h"
#include "DBElements/dbemailfield.h"
#include "Tools/HIBPChecker/hibpchecker.h"

namespace Ui {
class DBWEmailField;
}

class DBWEmailField : public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWEmailField(QWidget *parent, std::shared_ptr<AbstractDataBaseItem> item);
    ~DBWEmailField();

protected:
    void resizeEvent(QResizeEvent *event);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

public slots:
    void removeWidget();
    void expiredDate();
    void changeExpirationState();
    void checkEmail();
    void checkerReturned(std::pair<QString, HIBPChecker::CheckType> metadata, QString returnedData);

private:
    Ui::DBWEmailField *ui;
    std::shared_ptr<AbstractDataBaseItem> _item;
    ExpirationWidget *expiration = nullptr;
    std::pair<QString, HIBPChecker::CheckType> currentRequest;
    bool _checkEmail = false;
};

#endif // DBWEMAILFIELD_H
