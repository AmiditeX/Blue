#ifndef DBWCONTAINERS_H
#define DBWCONTAINERS_H

#include <QWidget>
#include <memory>
#include <QListWidgetItem>
#include <QPropertyAnimation>
#include "abstractdbwidget.h"
#include "MainwindowWidgets/bluedialog.h"
#include "DBElements/dbcontainers.h"
#include "DBWidgets/dbwemailfield.h"
#include "DBWidgets/dbwnamefield.h"
#include "DBWidgets/dbwotpitem.h"
#include "DBWidgets/dbwpasswordfield.h"
#include "MainwindowWidgets/containercreator.h"
#include "MainwindowWidgets/widgetcreator.h"

namespace Ui {
class DBWContainers;
}

class DBWContainers : public AbstractDBWidget
{
    Q_OBJECT

public:
    explicit DBWContainers(QWidget *parent, std::shared_ptr<DBContainers> containerPointer, QListWidgetItem *item);
    ~DBWContainers();

    int getCurrentSize();
    QListWidgetItem* returnItem();
    unsigned int getTotalItemSize();

    std::shared_ptr<AbstractDataBaseItem> getAbstractItem() override;

protected:
    QWidget* createItem(const QString &ID, std::shared_ptr<AbstractDataBaseItem> item);
    void resizeEvent(QResizeEvent *event);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

public slots:
    void removeContainer();
    void editContainer();

    void addWidget(const QString &widgetName);
    void retract();
    std::shared_ptr<DBContainers> getContainer();

    void handleRow(bool up, QListWidgetItem* listItem);

signals:
    void widgetClicked(bool drop);
    void pendingDelete(std::shared_ptr<DBContainers> container);
    void sizedChanged();
    void up();
    void down();

private:
    Ui::DBWContainers *ui;
    ContainerCreator *creator = nullptr;
    WidgetCreator *widgetCreator = nullptr;

    std::shared_ptr<DBContainers> _dbContainer;
    std::vector<QWidget*> _widgetList;

    QListWidgetItem *_item = nullptr;

};

#endif // DBWCONTAINERS_H
