#ifndef AES_H
#define AES_H

#include <QObject>

class AESModule
{

public:
    AESModule();

    //Cryptographic operations
    static QByteArray encryptBinary(const QByteArray &binaryToEncrypt, const QByteArray &additionalData,
                                    const QByteArray &privateKey, const QByteArray &initializationVector);
    
    static QByteArray decryptBinary(const QByteArray &binaryToDecrypt, const QByteArray &additionalData,
                                    const QByteArray &privateKey, const QByteArray &initializationVector);
    
    static QString encryptData(const QString &privateData, const QString &addData, const QString &privateKey, const QString &initializationVector);
    static QString decryptData(const QString &encryptedData, const QString &addData, const QString &privateKey, const QString &initializationVector);
    static QByteArray derivateKey(const QByteArray &password, const QByteArray &salt, const unsigned int iterations, const unsigned int time);
    static QByteArray generateIV();
    static QByteArray generateSalt();

    //Integrity check
    static bool integrityCheck();

    static QString fromHex(const QString &data);
    static QString toHex(const QString &data);

    //Hexadecimal encode/decode
    static QString toQStringBase64(const std::string &data);
    static std::string toStdBase64(const QString &data);
    static QString fromStdBase64(const std::string &data);
    static std::string fromQStringBase64(const QString &data);

protected:
    //Return result of encryption/decryption of a test vector
    static bool testVectorVerify(const QString &msg, const QString &key, const QString &nonce,
                                 const QString &header, const QString &cipher, QStringList &logs);
    static bool randomCheck();
    static QString generateRandomString();

private:
    const static int TAG_SIZE = 16;

};

#endif // AES_H
