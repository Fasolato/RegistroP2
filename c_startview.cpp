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
    c_ata=new C_AtaView(this,linQedinClient,view->getClientView());
}

void C_StartView::createC_DocenteView(){
    c_docente=new C_DocenteView(this,linQedinAdmin,view->getAdminView());
}

void C_StartView::createC_PresideView(){
    c_preside=new C_PresideView(this,linQedinAdmin,view->getAdminView());
}

void C_StartView::createAdminModel(){
    linQedinAdmin=new Admin(database);
    view->setAdminModel(linQedinAdmin);
}

void C_StartView::createClientModel(const QString &user){
    if(database->matchUtente(user)){
        linQedinClient=new Client(user,database);
        view->setClientModel(linQedinClient);
        }
    else
        view->noMatchUser();
}


void C_StartView::deleteControllers(){
    delete c_admin;
    delete c_client;
    c_client=0;
    c_admin=0;
}

void C_StartView::deleteModel(){
    delete linQedinAdmin;
    delete linQedinClient;
    linQedinAdmin=0;
    linQedinClient=0;
    view->setAdminModel(0);
    view->setClientModel(0);
}
