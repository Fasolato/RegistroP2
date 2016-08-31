#ifndef C_PRESIDECONTENT_H
#define C_PRESIDECONTENT_H

#include <QObject>

#include<iostream>

#include"PresideContent.h"

class C_PresideContent : public QObject
{
    Q_OBJECT
public:
    explicit C_PresideContent(preside* pres, lista<personale>* li, QObject *parent = 0, PresideContent* view_=0);
signals:

public slots:

    void insertPlesso(const QString& nome, const QString &sede, const QString &via, const QString &telefono, int p_ata, double m_q);
    void insertAta(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_mq);
    void insertDocente(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_ora);
    void insertPreside(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_ora, double p_stra, int ore_s, const QString& num);
    void removeUser(const QString& user);

private:
    preside* model;
    PresideContent* view;
    lista<personale>* list;
};

#endif // C_PRESIDECONTENT_H
