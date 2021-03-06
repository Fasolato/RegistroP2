#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T11:39:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RegistroP2
TEMPLATE = app


SOURCES += main.cpp \
    CONTR_VIEW/ata/AtaView.cpp \
    CONTR_VIEW/docente/DocenteView.cpp \
    CONTR_VIEW/preside/c_PresideView.cpp \
    CONTR_VIEW/preside/PresideView.cpp \
    CONTR_VIEW/c_startview.cpp \
    CONTR_VIEW/loginView.cpp \
    CONTR_VIEW/startview.cpp \
    MODEL/ATA.cpp \
    MODEL/docente.cpp \
    MODEL/listaPlessi.cpp \
    MODEL/orarioSettimanale.cpp \
    MODEL/personale.cpp \
    MODEL/plesso.cpp \
    MODEL/preside.cpp \
    CONTR_VIEW/preside/c_PresideContent.cpp \
    CONTR_VIEW/preside/PresideContent.cpp \
    CONTR_VIEW/preside/inserisci_ata/insertAta.cpp \
    CONTR_VIEW/preside/inserisci_docente/insertDocente.cpp \
    CONTR_VIEW/preside/inserisci_preside/insertPreside.cpp \
    CONTR_VIEW/preside/inserisci_plesso/insertPlesso.cpp

HEADERS  += \
    CONTR_VIEW/ata/AtaView.h \
    CONTR_VIEW/docente/DocenteView.h \
    CONTR_VIEW/preside/c_PresideView.h \
    CONTR_VIEW/preside/PresideView.h \
    CONTR_VIEW/c_startview.h \
    CONTR_VIEW/loginView.h \
    CONTR_VIEW/startview.h \
    MODEL/ATA.h \
    MODEL/docente.h \
    MODEL/lista.h \
    MODEL/listaPlessi.h \
    MODEL/orarioSettimanale.h \
    MODEL/personale.h \
    MODEL/plesso.h \
    MODEL/preside.h \
    CONTR_VIEW/preside/c_PresideContent.h \
    CONTR_VIEW/preside/PresideContent.h \
    CONTR_VIEW/preside/inserisci_ata/insertAta.h \
    CONTR_VIEW/preside/inserisci_docente/insertDocente.h \
    CONTR_VIEW/preside/inserisci_preside/insertPreside.h \
    CONTR_VIEW/preside/inserisci_plesso/insertPlesso.h

DISTFILES += \
    DATABASE/DB.xml \
    DATABASE/plessoDB.xml
