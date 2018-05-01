#ifndef DATABASEOPENER_H
#define DATABASEOPENER_H

#include <QWidget>

namespace Ui {
class DatabaseOpener;
}

class DatabaseOpener : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseOpener(QWidget *parent = 0);
    ~DatabaseOpener();

private:
    Ui::DatabaseOpener *ui;
};

#endif // DATABASEOPENER_H
