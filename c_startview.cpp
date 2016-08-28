#include<c_startview.h>

C_StartView::C_StartView(lista<personale>* pli, StartView* pview, QObject *parent) :
    li(pli), view(pview), QObject(parent)
{
    view->show();

    c_ata=0;
    c_docente=0;
    c_preside=0;

    connect(view,SIGNAL(createC_AtaView()),this, SLOT(createC_AtaView()));
    connect(view,SIGNAL(createC_DocenteView()),this, SLOT(createC_DocenteView()));
    connect(view,SIGNAL(createC_PresideView()),this, SLOT(createC_PresideView()));
    connect(view,SIGNAL(deleteControllers()),this,SLOT(deleteControllers()));
    connect(view,SIGNAL(deleteModel()),this,SLOT(deleteModel()));

    connect(view,SIGNAL(createClientModel(QString)),this,SLOT(createClientModel(QString)));
    connect(view,SIGNAL(createAdminModel()),this,SLOT(createAdminModel()));
}

void C_StartView::createC_AtaView(){
    c_ata=new C_AtaView(this,pers_ata,view->getAtaView());
}

void C_StartView::createC_DocenteView(){
    c_docente=new C_DocenteView(this,pers_docente,view->getDocenteView());
}

void C_StartView::createC_PresideView(){
    c_preside=new C_PresideView(this,pers_preside,view->getPresideView());
}

void C_StartView::createAtaModel(personale* pers){

        pers_ata=dynamic_cast<ata*>(pers);
        view->setAtaModel(pers_ata);
}

void C_StartView::createDocenteModel(personale* pers){

        pers_docente=dynamic_cast<docente*>(pers);
        view->setDocenteModel(pers_docente);
}

void C_StartView::createPresideModel(personale* pers){

        pers_ata=dynamic_cast<preside*>(pers);
        view->setPresideModel(pers_preside);
}


void C_StartView::deleteControllers(){
    delete c_ata;
    delete c_docente;
    delete c_preside;
    c_ata=0;
    c_docente=0;
    c_preside=0;
}

void C_StartView::deleteModel(){
    linQedinAdmin=0;
    linQedinClient=0;
    view->setAdminModel(0);
    view->setClientModel(0);
}