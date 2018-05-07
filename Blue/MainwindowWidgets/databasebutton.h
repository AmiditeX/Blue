#ifndef DATABASEBUTTON_H
#define DATABASEBUTTON_H

#include <QWidget>
#include <QListWidgetItem>
#include "DBMainComponents/bluewidget.h"

namespace Ui {
class DatabaseButton;
}

class DatabaseButton : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseButton(QWidget *parent = 0, BlueWidget *w = nullptr, QListWidgetItem* listItem = nullptr);
    void resizeEvent(QResizeEvent *event);
    BlueWidget* getWidget() const;
    QListWidgetItem* returnItem() const;
    ~DatabaseButton();

public slots:

signals:
    void dropMenu(bool drop);
    void sizeChanged();

    void databaseButtonClicked();
    void closeButtonClicked();
    void dashboardButtonClicked();
    void settingsButtonClicked();

private slots:


private:
    Ui::DatabaseButton *ui;
    BlueWidget* _widget;
    QListWidgetItem* _listItem;
};

#endif // DATABASEBUTTON_H
