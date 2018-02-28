#ifndef BLUEDATABASE_H
#define BLUEDATABASE_H

#include <QObject>
#include <QJsonDocument>

class BlueDatabase
{
public:
    BlueDatabase();

    struct Metadata
    {
        const QString compositeKey;
        const QString path;
        const int iterations = 0;
        const int stretchTime = 0;
    };

    Metadata mData;
    const QJsonDocument getJsonDocument() const;

};

#endif // BLUEDATABASE_H
