#ifndef BLUEMANAGER_H
#define BLUEMANAGER_H

#include <QObject>
#include <QTimer>
#include <QCryptographicHash>
#include <algorithm>
#include <QCoreApplication>
#include "BlueCrypto/aesmodule.h"
#include "DBMainComponents/bluedbmanager.h"
#include "BlueCrypto/blueiointerface.h"
#include "mainwindow.h"

class BlueManager : public QWidget
{
    Q_OBJECT

public:
    explicit BlueManager();
    ~BlueManager();

signals:

public slots:
    void openDatabase(QString masterKey, QString filePath, QString keyPath);
    void createDatabase(DatabaseCreator::DatabaseParam parameters);
    void closeDatabase(BlueWidget *w);
    void settingsChanged(BlueWidget *w, DatabaseSettings::DatabaseParam param);
    void databaseError(const QString &err);
    void databaseDecryptionError(const QString &err);
    void terminateDatabase();
    void databaseModified(BlueWidget *w);
    void saveDatabases();
    void endProgram();

private:
    MainWindow *window = nullptr;
    std::vector<std::shared_ptr<BlueDBManager>> _dbManagerList;
    int dbNumber = 0;
    bool programClosing = false;

    QTimer *savingTimer;
    QTimer *progressTimer;
    unsigned short progress = 30;
};

#endif // BLUEMANAGER_H
