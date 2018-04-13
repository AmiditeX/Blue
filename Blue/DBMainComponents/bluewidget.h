#ifndef BLUEWIDGET_H
#define BLUEWIDGET_H

#include <QWidget>

namespace Ui {
class BlueWidget;
}

class BlueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BlueWidget(QWidget *parent = 0);
    ~BlueWidget();

private:
    Ui::BlueWidget *ui;
};

#endif // BLUEWIDGET_H
