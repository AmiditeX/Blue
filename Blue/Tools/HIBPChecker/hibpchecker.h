#ifndef HIBPCHECKER_H
#define HIBPCHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "spdlog/spdlog.h"

//Checks for leaaked emails and passwords (singleton)
class HIBPChecker : public QObject
{
    Q_OBJECT

public:

    enum CheckType
    {
        Account,
        Password
    };

    HIBPChecker(){}

    static HIBPChecker& getInstance()
    {
        static HIBPChecker instance;

        if(manager == nullptr)
        {
            manager = new QNetworkAccessManager();
            connect(manager, SIGNAL(finished(QNetworkReply*)), &instance , SLOT(replyFinished(QNetworkReply*)));
        }

        return instance;
    }

    HIBPChecker(HIBPChecker const&) = delete;
    void operator=(HIBPChecker const&) = delete;

    void makeRequest(const QString &value, CheckType type);

signals:

public slots:
    void replyFinished(QNetworkReply* reply);

    void slotError(QNetworkReply::NetworkError err)
    {
        (void)err; QNetworkReply *r = qobject_cast<QNetworkReply*>(sender()); if(r == nullptr) {return;}
        spdlog::get("LOGGER")->error("NETWORK ERROR on API call : " + r->errorString().toStdString());
    }

    void slotSslErrors(QList<QSslError> err)
    {
        (void)err; QNetworkReply *r = qobject_cast<QNetworkReply*>(sender()); if(r == nullptr) {return;}
        for(int i = 0; i < err.size(); i++)
            spdlog::get("LOGGER")->error("SSL ERROR on API call : " + r->errorString().toStdString());
    }

private:
    static QNetworkAccessManager *manager;

};

#endif // HIBPCHECKER_H
