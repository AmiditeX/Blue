#ifndef AES_H
#define AES_H

#include <QObject>

class AESModule
{

public:
    AESModule();

    struct DerivedObject
    {
        QByteArray derivedKey;
        int iterations;
    };

    //Cryptographic operations
    static QByteArray encryptBinary(const QByteArray &binaryToEncrypt, const QByteArray &additionalData,
                                    const QByteArray &privateKey, const QByteArray &initializationVector);
    
    static QByteArray decryptBinary(const QByteArray &binaryToDecrypt, const QByteArray &additionalData,
                                    const QByteArray &privateKey, const QByteArray &initializationVector);
    

    //Key stretching and generation
    static DerivedObject derivateKey(const QByteArray &password, const QByteArray &salt, const unsigned int iterations, const unsigned int time);
    static QByteArray generateIV();
    static QByteArray generateSalt();

    //Integrity check
    static bool integrityCheck();

protected: 
    //Vector verification, ensuring good implementation
    static bool testVectorVerify(const QString &msg, const QString &key, const QString &nonce,
                                 const QString &header, const QString &cipher, QStringList &logs);
    static bool randomCheck(QStringList &logs);
    static QString generateRandomString();

private:
    const int static TAG_SIZE = 16;

};

#endif // AES_H
