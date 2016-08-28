#ifndef C_STARTVIEW_H
#define C_STARTVIEW_H

#include <QObject>

#include<startView.h>
#include<lista.h>
#include<ATA.h>
#include<docente.h>
#include<preside.h>
#include<c_ataView.h>
#include<c_docenteView.h>
#include<c_presideView.h>

//class StartView;

class C_StartView : public QObject
{
    Q_OBJECT
public:
    explicit C_StartView(lista<personale>* pli, StartView* pview =0, QObject *parent =0);

signals:
    void createC_ClientView();

public slots:
    void createC_ClientView();
    void createC_AdminView();
    void createClientModel(const QString &user);
    void createAdminModel();

    void deleteControllers();
    void deleteModel();

private:
    ata* pers_ata;
    docente* pers_docente;
    preside* pers_preside;

    lista<personale>* li;

    StartView* view;

    C_AtaView* c_ata;
    C_DocenteView* c_docente;
    C_PresideView* c_preside;

};

#endif // C_STARTVIEW_H
