#ifndef DATABASEBUTTON_H
#define DATABASEBUTTON_H

#include <QWidget>

namespace Ui {
class DatabaseButton;
}

class DatabaseButton : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseButton(QWidget *parent = 0);
    void resizeEvent(QResizeEvent *event);
    ~DatabaseButton();

public slots:

signals:
    void dropMenu(bool drop);
    void sizeChanged();

private slots:


private:
    Ui::DatabaseButton *ui;
};

#endif // DATABASEBUTTON_H
