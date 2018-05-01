#ifndef DATABASEBUTTON_H
#define DATABASEBUTTON_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class DatabaseButton;
}

class DatabaseButton : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseButton(QWidget *parent = 0);
    ~DatabaseButton();

public slots:
    void dropMenu();

private slots:
    void buttonStatus();

private:
    Ui::DatabaseButton *ui;
};

#endif // DATABASEBUTTON_H
