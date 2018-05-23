#ifndef WIDGETCREATOR_H
#define WIDGETCREATOR_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class WidgetCreator;
}

class WidgetCreator : public QDialog
{
    Q_OBJECT

public:
    explicit WidgetCreator(QWidget *parent = 0);
    ~WidgetCreator();

signals:
    void okClicked(const QString &widgetSelected);

private:
    Ui::WidgetCreator *ui;

    QString currentItem;
};

#endif // WIDGETCREATOR_H
