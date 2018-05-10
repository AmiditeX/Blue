#ifndef DBWCONTAINERS_H
#define DBWCONTAINERS_H

#include <QWidget>
#include <memory>
#include <QListWidgetItem>
#include "abstractdbwidget.h"
#include "MainwindowWidgets/bluedialog.h"
#include "DBElements/dbcontainers.h"
#include "DBWidgets/dbwemailfield.h"
#include "DBWidgets/dbwnamefield.h"
#include "DBWidgets/dbwotpitem.h"
#include "DBWidgets/dbwpasswordfield.h"
#include "MainwindowWidgets/containercreator.h"

namespace Ui {
class DBWContainers;
}

class DBWContainers : public QWidget, public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWContainers(QWidget *parent, std::shared_ptr<DBContainers> containerPointer, QListWidgetItem *item);
    ~DBWContainers();

    int getMaxValue();
    QListWidgetItem* returnItem();

protected:
    QWidget* createItem(const QString &ID, std::shared_ptr<AbstractDataBaseItem> item);
    void resizeEvent(QResizeEvent *event);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

public slots:
    void removeContainer();
    void editContainer();

signals:
    void widgetClicked(bool drop);
    void sizedChanged();
    void pendingDelete(std::shared_ptr<DBContainers> container);
    void modified();

private:
    Ui::DBWContainers *ui;
    ContainerCreator *creator = nullptr;

    std::shared_ptr<DBContainers> _dbContainer;
    std::vector<QWidget*> _widgetList;

    QListWidgetItem *_item = nullptr;
    int _maxValue = 200;

};

#endif // DBWCONTAINERS_H
