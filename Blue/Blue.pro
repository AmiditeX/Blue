#-------------------------------------------------
#
# Project created by QtCreator 2017-10-31T14:31:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
TARGET = Blue
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    BlueCrypto/aesmodule.cpp \
    BlueCrypto/blueiointerface.cpp \
    BlueCrypto/qiodevicesink.cpp \
    BlueCrypto/qiodevicesource.cpp \
    DBMainComponents/bluedatabase.cpp \
    DBMainComponents/bluedbmanager.cpp \
    DBElements/abstractdatabaseitem.cpp \
    DBElements/dbpasswordfield.cpp \
    DBElements/dbnamefield.cpp \
    DBElements/dbemailfield.cpp \
    DBElements/dbotpitem.cpp \
    DBElements/dbcontainers.cpp \
    DBWidgets/abstractdbwidget.cpp \
    DBWidgets/dbwcontainers.cpp \
    DBWidgets/dbwemailfield.cpp \
    DBWidgets/dbwnamefield.cpp \
    DBWidgets/dbwotpitem.cpp \
    DBWidgets/dbwpasswordfield.cpp \
    DBMainComponents/bluewidget.cpp

HEADERS  += mainwindow.h \
    BlueCrypto/aesmodule.h \
    BlueCrypto/blueiointerface.h \
    BlueCrypto/qiodevicesink.h \
    BlueCrypto/qiodevicesource.h \
    DBMainComponents/bluedatabase.h \
    DBMainComponents/bluedbmanager.h \
    DBElements/abstractdatabaseitem.h \
    DBElements/dbpasswordfield.h \
    DBElements/dbnamefield.h \
    DBElements/dbemailfield.h \
    DBElements/dbotpitem.h \
    DBElements/dbcontainers.h \
    DBWidgets/abstractdbwidget.h \
    DBWidgets/dbwcontainers.h \
    DBWidgets/dbwemailfield.h \
    DBWidgets/dbwnamefield.h \
    DBWidgets/dbwotpitem.h \
    DBWidgets/dbwpasswordfield.h \
    DBMainComponents/bluewidget.h

FORMS    += mainwindow.ui \
    DBWidgets/dbwcontainers.ui \
    DBWidgets/dbwemailfield.ui \
    DBWidgets/dbwnamefield.ui \
    DBWidgets/dbwotpitem.ui \
    DBWidgets/dbwpasswordfield.ui \
    DBMainComponents/bluewidget.ui

TRANSLATIONS += blue_fr.ts

#SPDLOG LINKAGE
INCLUDEPATH += $$PWD/../spdlog-master/include

#CRYPTOPP INCLUDE
win32:INCLUDEPATH += $$PWD/../libcrypto/include/w32
win32:DEPENDPATH += $$PWD/../libcrypto/include/w32
unix:!macx:INCLUDEPATH += $$PWD/../libcrypto/include/lnx
unix:!macx:DEPENDPATH += $$PWD/../libcrypto/include/lnx

#LINUX CRYPTOPP LINKAGE
unix:!macx: LIBS += -L$$PWD/../libcrypto/lib/lnx/ -lcryptopp
unix:!macx: PRE_TARGETDEPS += $$PWD/../libcrypto/lib/lnx/libcryptopp.a

#WINDOWS CRYPTOPP LINKAGE
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libcrypto/lib/w32/ -lcryptopp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libcrypto/lib/w32/ -lcryptopp
