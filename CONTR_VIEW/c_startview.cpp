#include"c_startview.h"

C_StartView::C_StartView(ListaPlessi* lp, lista<personale>* pli, StartView* pview, QObject *parent) :
    QObject(parent), li(pli), p(lp), view(pview)
{
    view->show();

    c_preside=0;

    connect(view,SIGNAL(createC_PresideView()),this, SLOT(createC_PresideView()));
    connect(view,SIGNAL(deleteControllers()),this,SLOT(deleteControllers()));
    connect(view,SIGNAL(deleteModel()),this,SLOT(deleteModel()));

    connect(view,SIGNAL(createAtaModel(personale*)),this,SLOT(createAtaModel(personale*)));
    connect(view,SIGNAL(createDocenteModel(personale*)),this,SLOT(createDocenteModel(personale*)));
    connect(view,SIGNAL(createPresideModel(personale*)),this,SLOT(createPresideModel(personale*)));
}

void C_StartView::createC_PresideView(){
    c_preside=new C_PresideView(p,li, pers_preside, this, view->getPresideView());
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

        pers_preside=dynamic_cast<preside*>(pers);
        view->setPresideModel(pers_preside);
}


void C_StartView::deleteControllers(){
    c_preside=0;
}

void C_StartView::deleteModel(){
    pers_ata=0;
    pers_docente=0;
    pers_preside=0;
    view->setAtaModel(0);
    view->setDocenteModel(0);
    view->setPresideModel(0);
}
