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
    c_startview.cpp \
    startview.cpp \
    loginView.cpp \
    AtaView.cpp \
    DocenteView.cpp \
    PresideView.cpp \
    c_AtaView.cpp \
    c_DocenteView.cpp \
    c_PresideView.cpp

HEADERS  += \
    ATA.h \
    docente.h \
    lista.h \
    listaPlessi.h \
    orarioSettimanale.h \
    personale.h \
    plesso.h \
    preside.h \
    c_startview.h \
    startview.h \
    loginView.h \
    AtaView.h \
    DocenteView.h \
    PresideView.h \
    c_AtaView.h \
    c_DocenteView.h \
    c_PresideView.h

DISTFILES += \
    DB.xml \
    plessoDB.xml
