#include "hibpchecker.h"
#include <QDebug>

    QNetworkAccessManager* HIBPChecker::manager = nullptr;

void HIBPChecker::makeRequest(const QString &value, CheckType type)
{
    QNetworkRequest request;
    if(type == Account)
        request.setUrl(QUrl("https://haveibeenpwned.com/api/v2/breachedaccount/" + value));
    if(type == Password)
        request.setUrl(QUrl("https://haveibeenpwned.com/api/v2/breachedaccount/" + value));
    request.setRawHeader("User-Agent", "Blue-Password-Manager");

    QNetworkReply *reply = manager->get(request);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(slotSslErrors(QList<QSslError>)));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Process the reply after a request
void HIBPChecker::replyFinished(QNetworkReply *reply)
{
    qWarning() << QString(reply->readAll());
    reply->deleteLater();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
