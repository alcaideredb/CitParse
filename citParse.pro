#-------------------------------------------------
#
# Project created by QtCreator 2014-10-06T00:08:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = citParse
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classwizard.cpp \
    editparsedreferences.cpp \
    viewparsedreferences.cpp \
    deleteparsedreferences.cpp \
    editreference.cpp \
    editrefindb.cpp

HEADERS  += mainwindow.h \
    classwizard.h \
    editparsedreferences.h \
    viewparsedreferences.h \
    deleteparsedreferences.h \
    editreference.h \
    editrefindb.h

FORMS    += mainwindow.ui \
    editparsedreferences.ui \
    viewparsedreferences.ui \
    deleteparsedreferences.ui \
    editreference.ui \
    editrefindb.ui

RESOURCES += \
    MyResources.qrc
