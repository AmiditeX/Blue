#ifndef AES_H
#define AES_H

#include <QObject>

class AESModule
{

public:
    AESModule();

    //Cryptographic operations
    static QString encryptData(const QString &privateData, const QString &addData, const QString &privateKey, const QString &initializationVector);
    static QString decryptData(const QString &encryptedData, const QString &addData, const QString &privateKey, const QString &initializationVector);
    static QString generateKey(const QString &password, const unsigned int iterations = 15000);
    static QString generateIV();

    //Integrity check
    static bool integrityCheck();

    //Hexadecimal encode/decode
    static QString toQStringHex(const std::string &data);
    static std::string toStdHex(const QString &data);
    static QString fromStdHex(const std::string &data);
    static std::string fromQStringHex(const QString &data);

protected:
    //Return result of encryption/decryption of a test vector
    static bool testVectorVerify(const QString &msg, const QString &key, const QString &nonce,
                                 const QString &header, const QString &cipher, QStringList &logs);

private:
    const static int TAG_SIZE = 16;

};

#endif // AES_H
