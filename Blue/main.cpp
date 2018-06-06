#include <QApplication>
#include <cryptlib.h>
#include <iostream>
#include "spdlog/spdlog.h"
#include "bluemanager.h"

#include "Tools/HIBPChecker/hibpchecker.h"
#include <QSslSocket>
#include <QLibrary>
#include <opensslv.h>

using namespace std;
using namespace CryptoPP;

int main(int argc, char *argv[])
{
    try //Create rotated logger (1 mb max)
    {
        spdlog::rotating_logger_mt("LOGGER", "logs.txt", 1048576, 1);
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

    QLibrary libcrypto, libssl; //Load OpenSSL for Linux or Windows
#ifdef __linux__
    libcrypto.setFileNameAndVersion(QLatin1String("libcrypto"), QLatin1String(SHLIB_VERSION_NUMBER));
    libssl.setFileNameAndVersion(QLatin1String("libssl"), QLatin1String(SHLIB_VERSION_NUMBER));
#endif
#ifdef __MINGW32__
    libcrypto.setFileNameAndVersion(QLatin1String("ssleay32"), QLatin1String(SHLIB_VERSION_NUMBER));
    libssl.setFileNameAndVersion(QLatin1String("libeay32"), QLatin1String(SHLIB_VERSION_NUMBER));
#endif
    libcrypto.load(); libssl.load();

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
        std::cerr << OPENSSL_VERSION_NUMBER << " " << OPENSSL_VERSION_TEXT;
    }

    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Blue");
    QCoreApplication::setApplicationVersion("1.0");
    QCoreApplication::setOrganizationDomain("https://github.com/AmiditeX/Blue");

    qsrand(time(NULL));
    qRegisterMetaType<DBParameters>("DBParameters");

    //Manager handles connection between UI and rest of the code
    BlueManager manager;

    return a.exec();
}
