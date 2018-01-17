#-------------------------------------------------
#
# Project created by QtCreator 2017-10-31T14:31:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Blue
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aesmodule.cpp \
    bluedbmanager.cpp \
    blueiointerface.cpp

HEADERS  += mainwindow.h \
    aesmodule.h \
    bluedbmanager.h \
    blueiointerface.h

FORMS    += mainwindow.ui


unix|win32: LIBS += -L$$PWD/../libcrypto/lib/ -lcryptopp

INCLUDEPATH += $$PWD/../libcrypto/include
INCLUDEPATH += $$PWD/../spdlog-master/include
DEPENDPATH += $$PWD/../libcrypto/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../libcrypto/lib/cryptopp.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../libcrypto/lib/libcryptopp.a
