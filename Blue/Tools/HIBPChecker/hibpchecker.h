#ifndef HIBPCHECKER_H
#define HIBPCHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <utility>
#include <vector>
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
            _fetchTimer = new QTimer(&instance);
            connect(manager, SIGNAL(finished(QNetworkReply*)), &instance , SLOT(replyFinished(QNetworkReply*)));
            connect(_fetchTimer, SIGNAL(timeout()), &instance, SLOT(processBuffer()));
            _fetchTimer->start(1900); // 1.7s between each request to avoid rate limiting
        }

        return instance;
    }

    HIBPChecker(HIBPChecker const&) = delete;
    void operator=(HIBPChecker const&) = delete;

    void makeRequest(QString value, CheckType type);

signals:
    void requestProcessed(std::pair<QString, CheckType> metadata, QString returnedData);

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

    void processBuffer();

private:
    static QNetworkAccessManager* manager;
    static std::vector<std::pair<QString, CheckType>> _buffer;
    static std::pair<QString, CheckType> _currentPair;
    static QTimer* _fetchTimer;
    static bool _lastResponded;

};

#endif // HIBPCHECKER_H
