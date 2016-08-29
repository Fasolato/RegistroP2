#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T12:19:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProvaErrori
TEMPLATE = app


SOURCES += main.cpp\
    ATA.cpp \
    docente.cpp \
    listaPlessi.cpp \
    orarioSettimanale.cpp \
    personale.cpp \
    plesso.cpp \
    preside.cpp \
    AtaWindow.cpp \
    DocWindow.cpp \
    PresideWindow.cpp \
    c_startview.cpp \
    startview.cpp \
    clientlogin.cpp

HEADERS  += \
    ATA.h \
    docente.h \
    lista.h \
    listaPlessi.h \
    orarioSettimanale.h \
    personale.h \
    plesso.h \
    preside.h \
    AtaWindow.h \
    DocWindow.h \
    PresideWindow.h \
    c_startview.h \
    startview.h \
    clientLogin.h

DISTFILES += \
    DB.xml \
    plessoDB.xml
