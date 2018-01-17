#include "aesmodule.h"

#include <QVector>
#include <spdlog/spdlog.h>
#include <cryptlib.h>
#include <pwdbased.h>
#include <eax.h>
#include <aes.h>
#include <hex.h>
#include <osrng.h>
#include <string>
#include <iostream>

using namespace CryptoPP;


AESModule::AESModule()
{

}

//Encrypt data with given parameters, all paramaters must be hexadecimal encoded
QString AESModule::encryptData(const QString &privateData, const QString &addData, const QString &privateKey, const QString &initializationVector)
{
    std::string pdata, adata, ciphertext; //Private Data, AAD, Encrypted Data
    pdata = fromQStringHex(privateData); //Private data incoming is Hex
    adata = fromQStringHex(addData); //Additional data incoming is Hex

    SecByteBlock key(AES::DEFAULT_KEYLENGTH); //QString (hex) to byte (unsigned char)
    StringSource(privateKey.toStdString(), true, new HexDecoder(new ArraySink(key, key.size())));

    SecByteBlock iv(AES::BLOCKSIZE); //QString (hex) to byte (unsigned char)
    StringSource(initializationVector.toStdString(), true, new HexDecoder(new ArraySink(iv, iv.size())));

    EAX<AES>::Encryption encryptObject;
    encryptObject.SetKeyWithIV(key, key.size(), iv, iv.size());

    AuthenticatedEncryptionFilter encryptFilter(encryptObject, new StringSink(ciphertext), false, TAG_SIZE);
    encryptFilter.ChannelPut(AAD_CHANNEL, (const byte*)adata.data(), adata.size()); //Pass the AAD inside the filter
    encryptFilter.ChannelMessageEnd(AAD_CHANNEL);

    encryptFilter.ChannelPut(DEFAULT_CHANNEL, (const byte*)pdata.data(), pdata.size()); //Pass the Private Data inside the filter
    encryptFilter.ChannelMessageEnd(DEFAULT_CHANNEL);

    return toQStringHex(ciphertext);
}

//Decrypt data with given parameters, all paramaters must be hexadecimal encoded
QString AESModule::decryptData(const QString &encryptedData, const QString &addData, const QString &privateKey, const QString &initializationVector)
{
    std::string ciphertext, adata, decipheredText; //Encrypted Data, AAD, Decrypted Data
    ciphertext = fromQStringHex(encryptedData); //Encrypted data incoming is Hex
    adata = fromQStringHex(addData); //Additional data incoming is Hex

    SecByteBlock key(AES::DEFAULT_KEYLENGTH); //QString (hex) to byte (unsigned char)
    StringSource(privateKey.toStdString(), true, new HexDecoder(new ArraySink(key, key.size())));

    SecByteBlock iv(AES::BLOCKSIZE); //QString (hex) to byte (unsigned char)
    StringSource(initializationVector.toStdString(), true, new HexDecoder(new ArraySink(iv, sizeof(iv))));

    std::string data = ciphertext.substr(0, ciphertext.length() - TAG_SIZE); //Split encrypted data into real data + tag
    std::string tag = ciphertext.substr(ciphertext.length() - TAG_SIZE);

    EAX<AES>::Decryption decryptionObject;
    decryptionObject.SetKeyWithIV(key, key.size(), iv, sizeof(iv));

    AuthenticatedDecryptionFilter decryptionFilter(decryptionObject, new StringSink(decipheredText), AuthenticatedDecryptionFilter::DEFAULT_FLAGS, TAG_SIZE);
    decryptionFilter.ChannelPut(AAD_CHANNEL, (const byte*)adata.data(), adata.size()); //Pass AAD into filter
    decryptionFilter.ChannelPut(DEFAULT_CHANNEL, (const byte*)data.data(), data.size()); //Pass data into filter
    decryptionFilter.ChannelPut(DEFAULT_CHANNEL, (const byte*)tag.data(), tag.size()); //Pass tag into filter
    decryptionFilter.MessageEnd();

    return QString::fromStdString(decipheredText);
}

//Derivates a key from a password given a number of iterations to process
QString AESModule::generateKey(const QString &password, const unsigned int iterations)
{
    SecByteBlock derived(16);
    PKCS5_PBKDF2_HMAC<SHA256> kdf;
    kdf.DeriveKey(derived.data(), derived.size(), 0, (byte*)password.data(), password.size(), nullptr, 0, iterations);
    std::string keyhex;
    StringSource(derived, sizeof(derived), true, new HexEncoder(new StringSink(keyhex)));
    return QString::fromStdString(keyhex);
}

//Generate a random hexadecimal encoded IV
QString AESModule::generateIV()
{
    AutoSeededRandomPool rng;
    SecByteBlock iv(AES::BLOCKSIZE);
    rng.GenerateBlock(iv, sizeof(iv));
    std::string ivhex;
    StringSource(iv, sizeof(iv), true, new HexEncoder(new StringSink(ivhex)));
    return QString::fromStdString(ivhex);
}

//String to Hex QString
QString AESModule::toQStringHex(const std::string &data)
{
    std::string hex;
    StringSource(data, true, new HexEncoder(new StringSink(hex)));
    return QString::fromStdString(hex);
}

//QString to Hex String
std::string AESModule::toStdHex(const QString &data)
{
    std::string hex;
    StringSource(data.toStdString(), true, new HexEncoder(new StringSink(hex)));
    return hex;
}

//Hex String to QString
QString AESModule::fromStdHex(const std::string &data)
{
    std::string ascii;
    StringSource (data, true, new HexDecoder(new StringSink(ascii)));
    return QString::fromStdString(ascii);
}

//Hex QString to String
std::string AESModule::fromQStringHex(const QString &data)
{
    std::string ascii;
    StringSource (data.toStdString(), true, new HexDecoder(new StringSink(ascii)));
    return ascii;
}

//Check test vectors and good implementation of AES
bool AESModule::integrityCheck()
{
    QStringList loggingList;
    QVector<bool> results;

    //"Test vectors from http://web.cs.ucdavis.edu/~rogaway/papers/eax.pdf"
    //"The following EAX-AES128 test vectors were graciously provided by Jack Lloyd. They were later verified by Brian Gladman."
    results.append(testVectorVerify(QStringLiteral(""),
                                    QStringLiteral("233952DEE4D5ED5F9B9C6D6FF80FF478"),
                                    QStringLiteral("62EC67F9C3A4A407FCB2A8C49031A8B3"),
                                    QStringLiteral("6BFB914FD07EAE6B"),
                                    QStringLiteral("E037830E8389F27B025A2D6527E79D01"),
                                    loggingList)); //1

    results.append(testVectorVerify(QStringLiteral("F7FB"),
                                    QStringLiteral("91945D3F4DCBEE0BF45EF52255F095A4"),
                                    QStringLiteral("BECAF043B0A23D843194BA972C66DEBD"),
                                    QStringLiteral("FA3BFD4806EB53FA"),
                                    QStringLiteral("19DD5C4C9331049D0BDAB0277408F67967E5"),
                                    loggingList)); //2

    results.append(testVectorVerify(QStringLiteral("1A47CB4933"),
                                    QStringLiteral("01F74AD64077F2E704C0F60ADA3DD523"),
                                    QStringLiteral("70C3DB4F0D26368400A10ED05D2BFF5E"),
                                    QStringLiteral("234A3463C1264AC6"),
                                    QStringLiteral("D851D5BAE03A59F238A23E39199DC9266626C40F80"),
                                    loggingList)); //3

    results.append(testVectorVerify(QStringLiteral("481C9E39B1"),
                                    QStringLiteral("D07CF6CBB7F313BDDE66B727AFD3C5E8"),
                                    QStringLiteral("8408DFFF3C1A2B1292DC199E46B7D617"),
                                    QStringLiteral("33CCE2EABFF5A79D"),
                                    QStringLiteral("632A9D131AD4C168A4225D8E1FF755939974A7BEDE"),
                                    loggingList)); //4

    results.append(testVectorVerify(QStringLiteral("40D0C07DA5E4"),
                                    QStringLiteral("35B6D0580005BBC12B0587124557D2C2"),
                                    QStringLiteral("FDB6B06676EEDC5C61D74276E1F8E816"),
                                    QStringLiteral("AEB96EAEBE2970E9"),
                                    QStringLiteral("071DFE16C675CB0677E536F73AFE6A14B74EE49844DD"),
                                    loggingList)); //5

    results.append(testVectorVerify(QStringLiteral("4DE3B35C3FC039245BD1FB7D"),
                                    QStringLiteral("BD8E6E11475E60B268784C38C62FEB22"),
                                    QStringLiteral("6EAC5C93072D8E8513F750935E46DA1B"),
                                    QStringLiteral("D4482D1CA78DCE0F"),
                                    QStringLiteral("835BB4F15D743E350E728414ABB8644FD6CCB86947C5E10590210A4F"),
                                    loggingList)); //6

    results.append(testVectorVerify(QStringLiteral("8B0A79306C9CE7ED99DAE4F87F8DD61636"),
                                    QStringLiteral("7C77D6E813BED5AC98BAA417477A2E7D"),
                                    QStringLiteral("1A8C98DCD73D38393B2BF1569DEEFC19"),
                                    QStringLiteral("65D2017990D62528"),
                                    QStringLiteral("02083E3979DA014812F59F11D52630DA30137327D10649B0AA6E1C181DB617D7F2"),
                                    loggingList)); //7

    results.append(testVectorVerify(QStringLiteral("1BDA122BCE8A8DBAF1877D962B8592DD2D56"),
                                    QStringLiteral("5FFF20CAFAB119CA2FC73549E20F5B0D"),
                                    QStringLiteral("DDE59B97D722156D4D9AFF2BC7559826"),
                                    QStringLiteral("54B9F04E6A09189A"),
                                    QStringLiteral("2EC47B2C4954A489AFC7BA4897EDCDAE8CC33B60450599BD02C96382902AEF7F832A"),
                                    loggingList)); //8

    results.append(testVectorVerify(QStringLiteral("6CF36720872B8513F6EAB1A8A44438D5EF11"),
                                    QStringLiteral("A4A4782BCFFD3EC5E7EF6D8C34A56123"),
                                    QStringLiteral("B781FCF2F75FA5A8DE97A9CA48E522EC"),
                                    QStringLiteral("899A175897561D7E"),
                                    QStringLiteral("0DE18FD0FDD91E7AF19F1D8EE8733938B1E8E7F6D2231618102FDB7FE55FF1991700"),
                                    loggingList)); //9

    results.append(testVectorVerify(QStringLiteral("CA40D7446E545FFAED3BD12A740A659FFBBB3CEAB7"),
                                    QStringLiteral("8395FCF1E95BEBD697BD010BC766AAC3"),
                                    QStringLiteral("22E7ADD93CFC6393C57EC0B3C17D6B44"),
                                    QStringLiteral("126735FCC320D25A"),
                                    QStringLiteral("CB8920F87A6C75CFF39627B56E3ED197C552D295A7CFC46AFC253B4652B1AF3795B124AB6E"),
                                    loggingList)); //10

    //If a test vector failed, send error to logger
    if(results.contains(false))
    {
        spdlog::get("LOGGER")->error("Integrity check has failed");
        spdlog::get("LOGGER")->error("[K = Key] [N = Nonce] [H = Header, Additional Data(ADATA)] "
                                     "[M = Message, encrypted data] [C = Cipher, Expected encrypted result]");
        for(int i = 0; i < loggingList.size(); i++)
        {
            spdlog::get("LOGGER")->error(loggingList.at(i).toStdString());
        }
        spdlog::get("LOGGER")->flush();
        return false;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PROTECTED                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Return result of the encryption of a test vector
bool AESModule::testVectorVerify(const QString &msg, const QString &key, const QString &nonce,
                                 const QString &header, const QString &cipher, QStringList &logs)
{
    QString logstr = QString(" Test Vector : K(%1) N(%2) H(%3) M(%4) C(%5) ").arg(key, nonce, header, msg, cipher); //Test vector logging

    //Three outcome possible : No error, Error, Exception
    try
    {
        //Test encryption of the test vector
        QString encryptResult = encryptData(msg, header, key, nonce);
        if(encryptResult == cipher)
        {
            logstr.prepend(QStringLiteral("Result(SUCCESS)"));
            logstr.append(QStringLiteral("Error()"));
            logs.append(logstr);
            return true;
        }
        else
        {
            logstr.prepend(QStringLiteral("Result(FAILURE)"));
            logstr.append(QStringLiteral("Error(VECTOR MISMATCH)"));
            logs.append(logstr);
            return false;
        }
    }
    catch(CryptoPP::Exception &e)
    {
        logstr.prepend(QStringLiteral("Result(FAILURE)"));
        logstr.append("Error(" + QString::fromStdString(e.what()) + ")");
        logs.append(logstr);
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PROTECTED                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
