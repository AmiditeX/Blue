#include <QApplication>
#include <cryptlib.h>
#include <iostream>
#include "spdlog/spdlog.h"
#include "bluemanager.h"

#include "Tools/HIBPChecker/hibpchecker.h"
#include <QSslSocket>
#include <QDebug>
#include <QLibrary>
#include <opensslv.h>

#include "Tools/libcppotp/otp.h"
#include "Tools/oath.h"

using namespace std;
using namespace CryptoPP;
using namespace CppTotp;

int main(int argc, char *argv[])
{
    try //Create basic file logger (not rotated)
    {
        spdlog::basic_logger_mt("LOGGER", "logs.txt");
        spdlog::set_pattern("[%d/%m/%Y %H:%M:%S.%e] [T:%t P:%P] [%l] %v");
        spdlog::get("LOGGER")->info("-- Started");
        spdlog::set_pattern("[%d/%m/%Y %H:%M:%S.%e] [%l] %v");
        spdlog::get("LOGGER")->flush();
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cerr << "Logger initialization failed, cannot load Blue: " << ex.what() << std::endl;
        return -1;
    }

    QLibrary libcrypto, libssl; //Load OpenSSL
    libcrypto.setFileNameAndVersion(QLatin1String("crypto"), QLatin1String(SHLIB_VERSION_NUMBER));
    libssl.setFileNameAndVersion(QLatin1String("ssl"), QLatin1String(SHLIB_VERSION_NUMBER));

    if(!QSslSocket::supportsSsl()) //Test SSL Support
    {
        spdlog::get("LOGGER")->error("OpenSSL not supported on this system !");
        spdlog::get("LOGGER")->error("Library needed : " + QSslSocket::sslLibraryBuildVersionString().toStdString());
        spdlog::get("LOGGER")->error("Got : " + QSslSocket::sslLibraryVersionString().toStdString());
        spdlog::get("LOGGER")->error("Currently used library paths : ");
        foreach (const QString &str, QCoreApplication::libraryPaths())
        {
            spdlog::get("LOGGER")->error(str.toStdString());
        }
        std::cerr << "SSL Error written to logs" << std::endl;
    }

    QApplication a(argc, argv);

    qsrand(time(NULL));
    qRegisterMetaType<DBParameters>("DBParameters");

    //HIBPChecker::getInstance().makeRequest("arthur.vache@live.fr", HIBPChecker::Account);

    const CppTotp::Bytes::ByteString key = reinterpret_cast<const uint8_t *>("JBSWY3DPEHPK3PXP");
    qWarning() << CppTotp::totp(key, time(NULL), 0, 30, 6);
    std::int32_t v = truncate(binary(totp("JBSWY3DPEHPK3PXP", std::time( nullptr ), 30, 31, 160)), 6);
    qWarning() << v;

    //Manager handles connection between UI and rest of the code
    BlueManager manager;

    return a.exec();
}
