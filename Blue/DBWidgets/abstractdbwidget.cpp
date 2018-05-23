#include "abstractdbwidget.h"
#include <QDebug>

AbstractDBWidget::AbstractDBWidget(QWidget *parent) : QWidget(parent)
{

}

AbstractDBWidget::~AbstractDBWidget()
{

}

void AbstractDBWidget::setHeightParam(int min, int max)
{
    minHeight = min;
    maxHeight = max;
}

int AbstractDBWidget::getMin()
{
    return minHeight;
}

int AbstractDBWidget::getMax()
{
    return maxHeight;
}
