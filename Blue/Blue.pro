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
    BlueCrypto/aesmodule.cpp \
    BlueCrypto/blueiointerface.cpp \
    BlueCrypto/qiodevicesink.cpp \
    BlueCrypto/qiodevicesource.cpp \
    bluedatabase.cpp \
    bluedbmanager.cpp \
    DBElements/abstractdatabaseitem.cpp \
    DBElements/dbpasswordfield.cpp \
    DBElements/dbnamefield.cpp \
    DBElements/dbemailfield.cpp \
    DBElements/dbotpitem.cpp

HEADERS  += mainwindow.h \
    BlueCrypto/aesmodule.h \
    BlueCrypto/blueiointerface.h \
    BlueCrypto/qiodevicesink.h \
    BlueCrypto/qiodevicesource.h \
    bluedatabase.h \
    bluedbmanager.h \
    DBElements/abstractdatabaseitem.h \
    DBElements/dbpasswordfield.h \
    DBElements/dbnamefield.h \
    DBElements/dbemailfield.h \
    DBElements/dbotpitem.h

FORMS    += mainwindow.ui

#SPDLOG LINKAGE
INCLUDEPATH += $$PWD/../spdlog-master/include

#LINUX CRYPTOPP LINKAGE
unix:!macx: LIBS += -L$$PWD/../libcrypto/lib/ -lcryptopplnx

INCLUDEPATH += $$PWD/../libcrypto/include
DEPENDPATH += $$PWD/../libcrypto/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../libcrypto/lib/libcryptopplnx.a

#WINDOWS CRYPTOPP LINKAGE
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libcrypto/lib/release/ -lcryptopp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libcrypto/lib/debug/ -lcryptopp

INCLUDEPATH += $$PWD/../libcrypto/include
DEPENDPATH += $$PWD/../libcrypto/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libcrypto/lib/release/libcryptopp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libcrypto/lib/debug/libcryptopp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libcrypto/lib/release/cryptopp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libcrypto/lib/debug/cryptopp.lib
