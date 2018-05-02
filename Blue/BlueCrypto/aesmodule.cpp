#include "aesmodule.h"

#include <QVector>
#include <spdlog/spdlog.h>
#include <cryptlib.h>
#include <pwdbased.h>
#include <eax.h>
#include <aes.h>
#include <base64.h>
#include <hex.h>
#include <osrng.h>
#include "BlueCrypto/qiodevicesink.h"
#include "BlueCrypto/qiodevicesource.h"

#include <QDebug>

using namespace CryptoPP;

AESModule::AESModule()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Encrypt binary data with given parameters, returns encrypted binary
QByteArray AESModule::encryptBinary(const QByteArray &binaryToEncrypt, const QByteArray &additionalData,
                                    const QByteArray &privateKey, const QByteArray &initializationVector)
{
    //Pipe the private key to a secure container
    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    QByteArraySource(privateKey, true, new ArraySink(key, key.size()));

    //Pipe the initialization vector to a secure container
    SecByteBlock iv(AES::BLOCKSIZE);
    QByteArraySource(initializationVector, true, new ArraySink(iv, iv.size()));

    //Create the encryption object and set the parameters
    EAX<AES>::Encryption encryptObject;
    encryptObject.SetKeyWithIV(key, key.size(), iv, iv.size());

    //Create a filter that returns the result as a string
    QByteArray encryptedData;
    AuthenticatedEncryptionFilter encryptFilter(encryptObject, new QByteArraySink(encryptedData), false, TAG_SIZE);

    //Pass the Authenticated Additional Data inside the filter
    encryptFilter.ChannelPut(AAD_CHANNEL, (const byte*)additionalData.toStdString().data(), additionalData.toStdString().size());
    encryptFilter.ChannelMessageEnd(AAD_CHANNEL);

    //Pass the Private Data inside the filter
    encryptFilter.ChannelPut(DEFAULT_CHANNEL, (const byte*)binaryToEncrypt.toStdString().data(), binaryToEncrypt.toStdString().size());
    encryptFilter.ChannelMessageEnd(DEFAULT_CHANNEL);

    return encryptedData;
}

//Decrypt binary data with given parameters, returns decrypted binary
QByteArray AESModule::decryptBinary(const QByteArray &binaryToDecrypt, const QByteArray &additionalData,
                                    const QByteArray &privateKey, const QByteArray &initializationVector)
{
    //Pipe the private key to a secure container
    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    QByteArraySource(privateKey, true, new ArraySink(key, key.size()));

    //Pipe the initialization vector to a secure container
    SecByteBlock iv(AES::BLOCKSIZE);
    QByteArraySource(initializationVector, true, new ArraySink(iv, sizeof(iv)));

    //Split encrypted data into real data + tag
    std::string encryptedData;
    QByteArraySource(binaryToDecrypt, true, new StringSink(encryptedData));
    std::string data = encryptedData.substr(0, encryptedData.length() - TAG_SIZE);
    std::string tag = encryptedData.substr(encryptedData.length() - TAG_SIZE);

    //Create the decryption object and set parameters
    EAX<AES>::Decryption decryptionObject;
    decryptionObject.SetKeyWithIV(key, key.size(), iv, iv.size());

    //Create a filter that returns the result as a string
    QByteArray decryptedData;
    AuthenticatedDecryptionFilter decryptionFilter(decryptionObject, new QByteArraySink(decryptedData), AuthenticatedDecryptionFilter::DEFAULT_FLAGS, TAG_SIZE);

    //Pass the Authenticated Additional Data inside the filter
    std::string addDataStr;
    QByteArraySource(additionalData, true, new StringSink(addDataStr));
    decryptionFilter.ChannelPut(AAD_CHANNEL, (const byte*)addDataStr.data(), addDataStr.size());
    decryptionFilter.ChannelMessageEnd(AAD_CHANNEL);

    //Pass the Private Data and the Tag inside the filter
    decryptionFilter.ChannelPut(DEFAULT_CHANNEL, (const byte*)data.data(), data.size());
    decryptionFilter.ChannelPut(DEFAULT_CHANNEL, (const byte*)tag.data(), tag.size());
    decryptionFilter.ChannelMessageEnd(DEFAULT_CHANNEL);

    return decryptedData;
}

//Derivates a key from a password given a number of iterations to process or a length of time to process
AESModule::DerivedObject AESModule::derivateKey(const QByteArray &password, const QByteArray &salt, const unsigned int iterations, const unsigned int time)
{
    SecByteBlock derivatedBlock(32);
    PKCS5_PBKDF2_HMAC<SHA256> keyDerivator;
    int it = keyDerivator.DeriveKey(derivatedBlock.data(), derivatedBlock.size(), 0, (const byte*)password.data(), password.size(),
                                    (const byte*)salt.data(), salt.size(), iterations, time);

    QByteArray key;
    ArraySource(derivatedBlock, sizeof(derivatedBlock), true, new QByteArraySink(key));
    return DerivedObject{key, it};
}

//Generate a random initialization vector
QByteArray AESModule::generateIV()
{
    SecByteBlock initializationVector(AES::BLOCKSIZE);
    AutoSeededRandomPool randomGenerator;
    randomGenerator.GenerateBlock(initializationVector, sizeof(initializationVector));

    QByteArray iv;
    ArraySource(initializationVector, sizeof(initializationVector), true, new QByteArraySink(iv));
    return iv;
}

//Generate a random 64 bytes salt
QByteArray AESModule::generateSalt()
{
    SecByteBlock salt(64);
    AutoSeededRandomPool randomGenerator;
    randomGenerator.GenerateBlock(salt, sizeof(salt));

    QByteArray s;
    ArraySource(salt, sizeof(salt), true, new QByteArraySink(s));
    return s;
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
        spdlog::get("LOGGER")->error("Integrity check has failed : test vector failed");
        spdlog::get("LOGGER")->error("[K = Key] [N = Nonce] [H = Header, Additional Data(ADATA)] "
                                     "[M = Message, encrypted data] [C = Cipher, Expected encrypted result]");
        for(int i = 0; i < loggingList.size(); i++)
        {
            spdlog::get("LOGGER")->error(loggingList.at(i).toStdString());
        }
        spdlog::get("LOGGER")->flush();
        return false;
    }

    loggingList.clear();

    //Test 50 random vectors
    for(int i = 0; i < 50; i++)
    {
        if(AESModule::randomCheck(loggingList) == false)
        {
            spdlog::get("LOGGER")->error("Random test #" + QString::number(i).toStdString());
            for(int i = 0; i < loggingList.size(); i++)
            {
                spdlog::get("LOGGER")->error(loggingList.at(i).toStdString());
            }
            spdlog::get("LOGGER")->flush();
            return false;
        }
    }

    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                           PUBLIC                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PROTECTED                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Return result of the encryption of a test vector
bool AESModule::testVectorVerify(const QString &msg, const QString &key, const QString &nonce,
                                 const QString &header, const QString &cipher, QStringList &logs)
{
    QString logstr = QString("Test Vector checked : K(%1) N(%2) H(%3) M(%4) C(%5)").arg(key, nonce, header, msg, cipher); //Test vector logging
    logs.append(logstr);

    //Three outcome possible : No error, Error, Exception
    try
    {
        //Test encryption of the test vector
        QByteArray encryptedBinary = encryptBinary(QByteArray::fromHex(msg.toUtf8()),
                                                   QByteArray::fromHex(header.toUtf8()),
                                                   QByteArray::fromHex(key.toUtf8()),
                                                   QByteArray::fromHex(nonce.toUtf8()));

        //Convert encryption result to hexadecimal
        QString encryptResult = encryptedBinary.toHex();
        encryptResult = encryptResult.toUpper();

        bool encryptTestPassed;
        if(encryptResult == cipher)
        {
            encryptTestPassed = true;
        }
        else
        {
            logs.append(QString("      ENCRYPTION RESULT(FAILURE) : Error(VECTOR ENCRYPTION MISMATCH : Expected \"%1\", got \"%2\")").arg(cipher, encryptResult));
            encryptTestPassed = false;
        }


        //Test decryption of the encrypted test vector
        QByteArray decryptedBinary = decryptBinary(QByteArray::fromHex(encryptResult.toUtf8()),
                                                   QByteArray::fromHex(header.toUtf8()),
                                                   QByteArray::fromHex(key.toUtf8()),
                                                   QByteArray::fromHex(nonce.toUtf8()));

        //Convert decryption result to hexadecimal
        QString decryptResult = decryptedBinary.toHex();
        decryptResult = decryptResult.toUpper();

        bool decryptTestPassed;
        if(decryptResult == msg)
        {
            decryptTestPassed = true;
        }
        else
        {
            logs.append(QString("      DECRYPTION RESULT(FAILURE) : Error(VECTOR DECRYPTION MISMATCH : Expected \"%1\", got \"%2\")").arg(msg, decryptResult));
            decryptTestPassed = false;
        }


        //Send result of the test vector testing
        if(encryptTestPassed && decryptTestPassed)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    catch(CryptoPP::Exception &e)
    {
        logs.append("      RESULT(FAILURE) : Error(EXCEPTION THROWN : " + QString::fromStdString(e.what()) + ")");
        return false;
    }

    return false;
}

//Execute 5 vector test based on random parameters
bool AESModule::randomCheck(QStringList &logs)
{
    //Generate random parameters and key
    QString randomString = generateRandomString();
    QString randomPassword = generateRandomString();
    QString authenticatedData = generateRandomString();
    QByteArray initializationVector = generateIV();
    QByteArray salt = generateSalt();
    QByteArray privateKey = derivateKey(randomPassword.toUtf8(), salt, (qrand() % 1000) + 1, 0).derivedKey;
    QByteArray encrypted, decrypted;
    bool first = false , second = false, third = false, fourth = false, fifth = false;

    try //Encrypt data to pass all the following tests
    {
        encrypted = encryptBinary(randomString.toUtf8(), authenticatedData.toUtf8(), privateKey, initializationVector);
    }
    catch(std::exception &e) //Fatal exception, can't continue to the following tests, integrity check has failed
    {
        logs.append("Encryption of random data has failed, integrity check failed");
        logs.append(QString("Test failed with RDATA(%1) RPASSWORD(%2), RADATA(%3)").arg(randomString, randomPassword, authenticatedData));
        logs.append(QString("Error returned : %1").arg(QString::fromStdString(e.what())));
        return false;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                    FIRST TEST                                                   //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    try //First test : has to succeed, decrypt data and match it with plaintext
    {
        decrypted = decryptBinary(encrypted, authenticatedData.toUtf8(), privateKey, initializationVector);

        if(randomString == QString(decrypted)) //Test that decrypted data matches the plaintext data that was encrypted
        {
            first = true;
        }
        else
        {
            logs.append("1ST Sub-Test has failed : decrypted != data when decryption successful");
            first = false;
        }
    }
    catch(CryptoPP::HashVerificationFilter::HashVerificationFailed &e) //Decryption failed in an abnormal way, test failed
    {
        logs.append(QString("1ST Sub-Test has failed : failed to decrypt : %1").arg(e.what()));
        first = false;
    }
    catch(std::exception &e) //Decryption failed in an abnormal way, test failed
    {
        logs.append(QString("1ST Sub-Test has failed : fatal exception : %1").arg(e.what()));
        first = false;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                   SECOND TEST                                                   //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Second test : has to fail, key was tampered
    try
    {
        QByteArray tamper("a");
        QByteArray tamperedKey = privateKey;
        if(tamperedKey.at(1) == 'a') //Don't replace if it won't tamper the data
        {
            tamper = "b"; //Replace with data that does tamper the data
        }
        tamperedKey.replace(1, 1, tamper);

        decrypted = decryptBinary(encrypted, authenticatedData.toUtf8(), tamperedKey, initializationVector);
        second = false; //If decryptBinary didn't throw, decryption worked, test failed
        logs.append(QString("2ND Sub-Test has failed : decryptBinary failed to throw"));
        logs.append(QString("Found : %1").arg(QString(decrypted)));
    }
    catch(CryptoPP::HashVerificationFilter::HashVerificationFailed &e) //Decryption failed in a normal way, test passed
    {
        second = true;
    }
    catch(std::exception &e) //Decryption failed in an abnormal way, test failed
    {
        logs.append(QString("2ND Sub-Test has failed : fatal exception : %1").arg(e.what()));
        second = false;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                    THIRD TEST                                                   //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Third test : has to fail, AAD was tampered
    try
    {
        QString tamperedAAD = authenticatedData;
        tamperedAAD.remove(0, 1);

        decrypted = decryptBinary(encrypted, tamperedAAD.toUtf8(), privateKey, initializationVector);
        third = false; //If decryptBinary didn't throw, decryption worked, test failed
        logs.append(QString("3RD Sub-Test has failed : decryptBinary failed to throw"));
        logs.append(QString("Found : %1").arg(QString(decrypted)));
    }
    catch(CryptoPP::HashVerificationFilter::HashVerificationFailed &e) //Decryption failed in a normal way, test passed
    {
        third = true;
    }
    catch(std::exception &e) //Decryption failed in an abnormal way, test has failed
    {
        third = false;
        logs.append(QString("3RD Sub-Test has failed : fatal exception : %1").arg(e.what()));
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                   FOURTH TEST                                                   //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Fourth test : has to fail, IV was tampered
    try
    {
        QByteArray tamper("a");
        QByteArray tamperedIV = initializationVector;
        if(tamperedIV.at(1) == 'a') //Don't replace if it won't tamper the data
        {
            tamper = "b"; //Replace with data that does tamper the data
        }
        tamperedIV.replace(1, 1, tamper);

        decrypted = decryptBinary(encrypted, authenticatedData.toUtf8(), privateKey, tamperedIV);
        fourth = false; //If decryptBinary didn't throw, decryption worked, test failed
        logs.append(QString("4TH Sub-Test has failed : decryptBinary failed to throw"));
        logs.append(QString("Found : %1").arg(QString(decrypted)));
    }
    catch(CryptoPP::HashVerificationFilter::HashVerificationFailed &e) //Decryption failed in a normal way, test passed
    {
        fourth = true;
    }
    catch(std::exception &e) //Decryption failed in an abnormal way, test failed
    {
        logs.append(QString("4TH Sub-Test has failed : fatal exception : %1").arg(e.what()));
        fourth = false;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                    FIFTH TEST                                                   //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Fifth test : has to fail, data was tampered
    try
    {
        QByteArray tamper("a");
        QByteArray tamperedData = encrypted;
        if(tamperedData.at(1) == 'a') //Don't replace if it won't tamper the data
        {
            tamper = "b"; //Replace with data that does tamper the data
        }
        tamperedData.replace(1, 1, tamper);

        decrypted = decryptBinary(tamperedData, authenticatedData.toUtf8(), privateKey, initializationVector);
        fifth = false; //If decryptBinary didn't throw, decryption worked, test failed
        logs.append(QString("5TH Sub-Test has failed : decryptBinary failed to throw"));
        logs.append(QString("Found : %1").arg(QString(decrypted)));
    }
    catch(CryptoPP::HashVerificationFilter::HashVerificationFailed &e) //Decryption failed in a normal way, test passed
    {
        fifth = true;
    }
    catch(std::exception &e) //Decryption failed in an abnormal way, test failed
    {
        logs.append(QString("5TH Sub-Test has failed : fatal exception : %1").arg(e.what()));
        fifth = false;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                      RETURN                                                     //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Random test passes if each individual test passed
    if(first && second && third && fourth && fifth)
    {
        return true;
    }

    logs.append("Integrity check has failed, one or more test failed");
    logs.append(QString("Test failed with RDATA(%1) RPASSWORD(%2), RADATA(%3)").arg(randomString, randomPassword, authenticatedData));
    return false;
}

//Return a random string of random and maximum length of 32
QString AESModule::generateRandomString()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = (qrand() % 31) + 1;

    QString randomString;
    for(int i = 0; i < randomStringLength; i++)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PROTECTED                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
