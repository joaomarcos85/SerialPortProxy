#-------------------------------------------------
#
# Project created by QtCreator 2021-02-26T09:11:15
#
#-------------------------------------------------

QT       += core gui serialport multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPortProxy
TEMPLATE = app


SOURCES += main.cpp\
    MainWindow/mainwindow.cpp \
    Serial/serialhandler.cpp \
    System/sysprop.cpp

HEADERS  += MainWindow/mainwindow.h \
    Error/debughandler.h \
    Serial/serialhandler.h \
    System/sysinfo.h \
    System/sysprop.h

FORMS    += MainWindow/mainwindow.ui \
    Serial/serialhandler.ui

RESOURCES += \
    resources/resource.qrc
