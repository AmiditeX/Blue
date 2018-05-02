#ifndef BLUEMANAGER_H
#define BLUEMANAGER_H

#include <QObject>
#include "DBMainComponents/bluedbmanager.h"
#include "BlueCrypto/blueiointerface.h"
#include "mainwindow.h"

class BlueManager : public QObject
{
    Q_OBJECT

public:
    explicit BlueManager();
    ~BlueManager();

signals:

public slots:
    void openDatabase(QString masterKey, QString filePath);

private:
    MainWindow *window = nullptr;
    std::vector<std::shared_ptr<BlueDBManager>> _dbManagerList;
};

#endif // BLUEMANAGER_H
