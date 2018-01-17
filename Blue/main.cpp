#include "mainwindow.h"
#include "spdlog/spdlog.h"
#include <QApplication>

#include <iostream>
#include <cryptlib.h>

using namespace std;
using namespace CryptoPP;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    try
    {
        // Create basic file logger (not rotated)
        spdlog::basic_logger_mt("LOGGER", "logs.txt");
        spdlog::set_pattern("[%d/%m/%Y %H:%M:%S.%e] [T:%t P:%P] [%l] %v");
        spdlog::get("LOGGER")->info("");
        spdlog::get("LOGGER")->info("  - - - - - - - - - - - - - - - - - - - - - - - - - -");
        spdlog::get("LOGGER")->info("  - - - Program started - log recording started - - -");
        spdlog::get("LOGGER")->info("  - - - - - - - - - - - - - - - - - - - - - - - - - -");
        spdlog::get("LOGGER")->info("");
        spdlog::set_pattern("[%d/%m/%Y %H:%M:%S.%e] [%l] %v");
        spdlog::get("LOGGER")->flush();
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cerr << "Log initialization failed: " << ex.what() << std::endl;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
