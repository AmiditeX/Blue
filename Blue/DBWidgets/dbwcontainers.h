#ifndef DBWCONTAINERS_H
#define DBWCONTAINERS_H

#include <QWidget>
#include <memory>
#include "abstractdbwidget.h"
#include "DBElements/dbcontainers.h"
#include "DBWidgets/dbwemailfield.h"
#include "DBWidgets/dbwnamefield.h"
#include "DBWidgets/dbwotpitem.h"
#include "DBWidgets/dbwpasswordfield.h"

namespace Ui {
class DBWContainers;
}

class DBWContainers : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWContainers(std::shared_ptr<DBContainers> containerPointer);
    ~DBWContainers();

protected:
    std::shared_ptr<AbstractDBWidget> createItem(const QString &ID, std::shared_ptr<AbstractDataBaseItem> item);

private:
    Ui::DBWContainers *ui;

    std::shared_ptr<DBContainers> _dbContainer;
    std::vector<std::shared_ptr<AbstractDBWidget>> _widgetList;

};

#endif // DBWCONTAINERS_H
