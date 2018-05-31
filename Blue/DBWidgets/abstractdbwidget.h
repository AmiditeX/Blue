#ifndef ABSTRACTDBWIDGET_H
#define ABSTRACTDBWIDGET_H

#include <QWidget>
#include <memory>
#include "DBElements/abstractdatabaseitem.h"

class AbstractDBWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractDBWidget(QWidget *parent);
    ~AbstractDBWidget();

    void setHeightParam(int min, int max);
    int getMin();
    int getMax();

signals:
    void sizeChanged();
    void expand(bool expand);
    void remove(std::shared_ptr<AbstractDataBaseItem> item);
    void modified();

private:
    int minHeight;
    int maxHeight;
};

#endif // ABSTRACTDBWIDGET_H
