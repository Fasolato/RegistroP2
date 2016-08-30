#include "startview.h"

StartView::StartView(QGroupBox *parent)
    : QMainWindow(parent), login_view(0), ata_view(0), docente_view(0), preside_view(0), ata_model(0), docente_model(0), preside_model(0)
{
    createLogin(); //schermata iniziale

    setWhatsThis("StartView");
    setWindowTitle("StartView");
    showMaximized();
}

void StartView::createAta(personale* p){
    emit createAtaModel(p); //setta il model
    if(ata_model){ //se il model è stato creato il login ha avuto successo
        ata_view=new AtaView(ata_model, this); //creo view ata
        connect(ata_view,SIGNAL(disconnectUserView()),this,SLOT(backInTime()));

        emit createC_AtaView(); //creo controller ata
        setCentralWidget(ata_view);
    }
}

void StartView::createDocente(personale* p){
    emit createDocenteModel(p); //setta il model
    if(docente_model){ //se il model è stato creato il login ha avuto successo
        docente_view=new DocenteView(docente_model, this); //creo view docente
        connect(docente_view,SIGNAL(disconnectUserView()),this,SLOT(backInTime()));

        emit createC_DocenteView(); //creo controller docente
        setCentralWidget(docente_view);
    }
}

void StartView::createPreside(personale* p){
    emit createPresideModel(p); //setta il model
    if(preside_model){ //se il model è stato creato il login ha avuto successo
        preside_view=new PresideView(preside_model, this); //creo view preside
        connect(preside_view,SIGNAL(disconnectUserView()),this,SLOT(backInTime()));

        emit createC_PresideView(); //creo controller preside
        setCentralWidget(preside_view);
    }
}

void StartView::createLogin(){
    login_view=new LoginView(this);
    connect(login_view,SIGNAL(setPersonale(personale*)),this,SLOT(setPersonale(personale*)));
    connect(login_view,SIGNAL(openAtaView()),this,SLOT(createAta(pers)));
    connect(login_view,SIGNAL(openDocenteView()),this,SLOT(createDocente(pers)));
    connect(login_view,SIGNAL(openPresideView()),this,SLOT(createPreside(pers)));
    setCentralWidget(login_view);
}

void StartView::backInTime(){
    createLogin();
    emit deleteControllers(); //distrugge i controller delle view
    delete ata_view;
    delete docente_view;
    delete preside_view;
    ata_view=0;
    docente_view=0;
    preside_view=0;

    emit deleteModel(); //distrugge i model
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


