#include "startview.h"

StartView::StartView(lista<personale> *li, QGroupBox *parent)
    : QMainWindow(parent), pli(li), login_view(0), ata_view(0), docente_view(0), preside_view(0), ata_model(0), docente_model(0), preside_model(0)
{
    createLogin(); //schermata iniziale
    setFixedHeight(600);
    setFixedWidth(900);

    setStyleSheet("StartWindow{ background-color: red; border: 1px solid #FFF;}");
    setWhatsThis("StartView");
    setWindowTitle("Project Registro");

}

void StartView::createAta(personale* p){
    emit createAtaModel(p); //setta il model
    if(ata_model){ //se il model è stato creato il login ha avuto successo
        ata_view=new AtaView(ata_model, this); //creo view ata
        connect(ata_view,SIGNAL(disconnectUserView()),this,SLOT(backInTime()));
        setCentralWidget(ata_view);
    }
}

void StartView::createDocente(personale* p){
    emit createDocenteModel(p); //setta il model
    if(docente_model){ //se il model è stato creato il login ha avuto successo
        docente_view=new DocenteView(docente_model, this); //creo view docente
        connect(docente_view,SIGNAL(disconnectUserView()),this,SLOT(backInTime()));
        setCentralWidget(docente_view);
    }
}

void StartView::createPreside(personale* p){
    emit createPresideModel(p); //setta il model
    if(preside_model){ //se il model è stato creato il login ha avuto successo
        preside_view=new PresideView(pli, preside_model, this); //creo view preside
        connect(preside_view,SIGNAL(disconnectUserView()),this,SLOT(backInTime()));

        emit createC_PresideView(); //creo controller preside
        setCentralWidget(preside_view);
    }
}

void StartView::createLogin(){
    lista<personale>*p2=pli;
    login_view=new LoginView(p2, this);
    std::cout<<"arrivaticreatelogin"<<std::endl;
    connect(login_view,SIGNAL(setPersonale(personale*)),this,SLOT(setPersonale(personale*)));
    connect(login_view,SIGNAL(createAta(personale*)),this,SLOT(createAta(personale*)));
    connect(login_view,SIGNAL(createDocente(personale*)),this,SLOT(createDocente(personale*)));
    connect(login_view,SIGNAL(createPreside(personale*)),this,SLOT(createPreside(personale*)));
    setCentralWidget(login_view);
}

void StartView::backInTime(){
    emit deleteControllers(); //distrugge i controller delle view
    emit deleteModel(); //distrugge i model
    ata_view=0;
    docente_view=0;
    preside_view=0;
    //delete login_view;
    login_view=0;
    std::cout<<"arrivatiback"<<std::endl;
    createLogin();
}

void StartView::setPersonale(personale* p){
    pers=p;
}

void StartView::setAtaModel(ata * p_ata){
    ata_model=p_ata;
}

void StartView::setDocenteModel(docente * p_docente){
    docente_model=p_docente;
}

void StartView::setPresideModel(preside * p_preside){
    preside_model=p_preside;
}

void StartView::noMatchUser(){
    QMessageBox warning;
    warning.setIcon(QMessageBox::Information);
    warning.setText("UserName non valido");
    warning.exec();
}

AtaView* StartView::getAtaView(){
    return ata_view;
}

DocenteView* StartView::getDocenteView(){
    return docente_view;
}

PresideView* StartView::getPresideView(){
    return preside_view;
}

void StartView::centerWidget(){
    int width = frameGeometry().width();
    int height = frameGeometry().height();

    QDesktopWidget wid;

    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();

    setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);
}


