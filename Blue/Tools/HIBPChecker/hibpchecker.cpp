#include "hibpchecker.h"

QNetworkAccessManager* HIBPChecker::manager = nullptr;
QTimer* HIBPChecker::_fetchTimer = nullptr;
std::vector<std::pair<QString, HIBPChecker::CheckType>>HIBPChecker::_buffer;
std::pair<QString, HIBPChecker::CheckType> HIBPChecker::_currentPair;
bool HIBPChecker::_lastResponded = true;

void HIBPChecker::makeRequest(QString value, CheckType type)
{
    std::pair<QString, CheckType> data = std::make_pair(value, type);
    _buffer.insert(_buffer.begin(), data); //Add to buffer
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Process the last request in the buffer
void HIBPChecker::processBuffer()
{
    if(_buffer.size() <= 0 || !_lastResponded)
        return;
    _lastResponded = false;

    std::pair<QString, CheckType> currentPair = _buffer.back(); //Last element
    _buffer.pop_back();
    _currentPair = currentPair;

    QNetworkRequest request;
    if(currentPair.second == Account)
        request.setUrl(QUrl("https://haveibeenpwned.com/api/v2/breachedaccount/" + currentPair.first));
    if(currentPair.second == Password)
        request.setUrl(QUrl("https://haveibeenpwned.com/api/v2/breachedaccount/" + currentPair.first));
    request.setRawHeader("User-Agent", "Blue-Password-Manager");

    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(slotSslErrors(QList<QSslError>)));
}

//Process the reply after a request
void HIBPChecker::replyFinished(QNetworkReply *reply)
{
    QString replyStr = reply->readAll();
    if(replyStr == "Rate limit exceeded, refer to acceptable use of API: https://haveibeenpwned.com/API/v2#AcceptableUse")
    {
        spdlog::get("LOGGER")->error("API THRESHOLD COMPLIANCE FAILURE : ");
    }

    _lastResponded = true;
    emit requestProcessed(_currentPair, replyStr);
    reply->deleteLater();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                       PUBLIC SLOTS                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
