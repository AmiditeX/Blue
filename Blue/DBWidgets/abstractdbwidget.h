#ifndef ABSTRACTDBWIDGET_H
#define ABSTRACTDBWIDGET_H

#include <QWidget>

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

private:
    int minHeight;
    int maxHeight;
};

#endif // ABSTRACTDBWIDGET_H
