#include "abstractdbwidget.h"
#include <QDebug>

AbstractDBWidget::AbstractDBWidget()
{

}

AbstractDBWidget::~AbstractDBWidget()
{
    qWarning() << "AbstractDBWidget destructor called";
}
