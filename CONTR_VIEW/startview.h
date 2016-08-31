#ifndef STARTVIEW_H
#define STARTVIEW_H

#include<QMainWindow>
#include<iostream>

#include"loginView.h"

#include"ata/AtaView.h"
#include"docente/DocenteView.h"
#include"preside/PresideView.h"

class StartView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartView(lista<personale>* li, QGroupBox *parent = 0);

    AtaView* getAtaView();
    DocenteView* getDocenteView();
    PresideView* getPresideView();

    void setAtaModel(ata* p_ata);
    void setDocenteModel(docente* p_docente);
    void setPresideModel(preside* p_preside);

    void noMatchUser();

signals:
    void createAtaModel(personale*);
    void createDocenteModel(personale*);
    void createPresideModel(personale*);
    void createC_AtaView();
    void createC_DocenteView();
    void createC_PresideView();

    void deleteControllers();

    void deleteModel();

private slots:
    void createAta(personale* p);
    void createDocente(personale* p);
    void createPreside(personale* p);

    void backInTime();

public slots:
    void setPersonale(personale*);

private:
    void centerWidget();
    void createLogin();

    LoginView* login_view;
    AtaView* ata_view;
    DocenteView* docente_view;
    PresideView* preside_view;

    lista<personale>* pli;
    personale* pers;

    ata* ata_model;
    docente* docente_model;
    preside* preside_model;
};

#endif // STARTVIEW_H
