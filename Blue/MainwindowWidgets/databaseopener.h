#ifndef DATABASEOPENER_H
#define DATABASEOPENER_H

#include <QWidget>
#include <QFileDialog>
#include "MainwindowWidgets/customshadoweffect.h"

namespace Ui {
class DatabaseOpener;
}

class DatabaseOpener : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseOpener(QWidget *parent = 0);
    ~DatabaseOpener();

public slots:
    void switchEcho(bool isChecked);
    QString getFilePath();
    QString getMaster();
    QString getKey();

    void openDbSelector();
    void retrieveDbUrl(const QUrl &url);

    void openKeySelector();
    void retrieveKeyUrl(const QUrl &url);

    void clear();

signals:
    void openPressed();
    void closePressed();

private:
    Ui::DatabaseOpener *ui;
    CustomShadowEffect *bodyShadow = nullptr;
};

#endif // DATABASEOPENER_H
