#include"PresideContent.h"

PresideContent::PresideContent(lista<personale>* li, QWidget *parent, preside* model_) :
    QWidget(parent), pli(li), model(model_)
{
    selected_user="";
    selected_plesso="";

    insPlessoView=0;
    insAtaView=0;
    insDocenteView=0;
    insPresideView=0;
    tablePlessi=0;


    table=new QTableWidget(this);
    table->setColumnCount(4);
    table->setRowCount(0);

    QStringList tabHeader;
    tabHeader<<"Cognome"<<"Nome"<<"Username"<<"Tipologia";
    table->setHorizontalHeaderLabels(tabHeader);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int i=0; i<table->columnCount(); i++)
        table->horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);
    table->setMinimumWidth(419);


    selected_text_label=new QLabel("Utente selezionato:",this);
    selected_user_label=new QLabel("",this);
    selected_user_label->setStyleSheet("font-weight: bold; border: 1px solid grey");
    selected_user_label->setAlignment(Qt::AlignCenter);
    selected_user_label->setMaximumHeight(30);
    selected_user_label->setMinimumHeight(30);

    show_plessi= new QPushButton("Visualizza Plessi",this);
    show_plessi->setMaximumWidth(350);

    i_plesso= new QPushButton("Inserisci Plesso",this);
    i_plesso->setMaximumWidth(350);
    i_ata= new QPushButton("Inserisci Membro del Personale ATA ",this);
    i_ata->setMaximumWidth(350);
    i_docente= new QPushButton("Inserisci Docente",this);
    i_docente->setMaximumWidth(350);
    i_preside= new QPushButton("Inserisci Preside",this);
    i_preside->setMaximumWidth(350);
    remove_user=new QPushButton("Rimuovi Utente",this);
    remove_user->setMaximumWidth(350);
    show_info=new QPushButton("Dettagli Utente",this);
    show_info->setMaximumWidth(350);
    remove_plesso=new QPushButton("Rimuovi Plesso",this);
    remove_plesso->setMaximumWidth(350);

    connect(remove_user,SIGNAL(clicked()),this,SLOT(removeUser()));

    connect(remove_plesso,SIGNAL(clicked()),this,SLOT(removePlesso()));

    connect(show_plessi,SIGNAL(clicked()),this,SLOT(buildPlessoTable()));

    connect(i_plesso,SIGNAL(clicked()),this,SLOT(buildPlessoView()));
    connect(i_ata,SIGNAL(clicked()),this,SLOT(buildAtaView()));
    connect(i_docente,SIGNAL(clicked()),this,SLOT(buildDocenteView()));
    connect(i_preside,SIGNAL(clicked()),this,SLOT(buildPresideView()));

    connect(show_info,SIGNAL(clicked()),this,SLOT(showInfoSelection()));

    //table connect
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(setSelectedUser(int)));
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(enableButtons()));
    connect(table,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(showInfoSelection()));

    layout_Table=new QVBoxLayout();
    layout_Table->addWidget(table);

    layout_Buttons=new QVBoxLayout();
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(selected_text_label);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(selected_user_label);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(show_info);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(remove_user);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(remove_plesso);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(show_plessi);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(i_plesso);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(i_ata);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(i_docente);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(i_preside);
    layout_Buttons->addSpacing(15);

    layout=new QHBoxLayout(this);
    layout->addLayout(layout_Table);
    layout->addSpacing(10);
    layout->addLayout(layout_Buttons);

    buildTable();
    disableButtons();
    disableButtonP();

    setLayout(layout);
}

void PresideContent::disableButtons(){
    remove_user->setDisabled(true);
    show_info->setDisabled(true);
}

void PresideContent::enableButtons(){
    remove_user->setEnabled(true);
    show_info->setEnabled(true);
}

void PresideContent::enableButtonP(){
    remove_plesso->setEnabled(true);
}

void PresideContent::disableButtonP(){
    remove_plesso->setDisabled(true);
}


void PresideContent::removeUser(){
    QMessageBox warning;
    warning.setIcon(QMessageBox::Question);
    warning.setWindowTitle("Rimuovi utente");
    warning.setText("Hai selezionato l'utente: <b>"+selected_user+"</b>");
    warning.setInformativeText("Vuoi veramente eliminare questo utente?");
    warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    warning.setDefaultButton(QMessageBox::Cancel);
    int ret = warning.exec();
    if(ret==QMessageBox::Yes) {
        emit removeUserClicked(selected_user);
    }
    buildTable();
}

void PresideContent::removePlesso(){
    QMessageBox warning;
    warning.setIcon(QMessageBox::Question);
    warning.setWindowTitle("Rimuovi plesso");
    warning.setText("Hai selezionato il plesso: <b>"+selected_plesso+"</b>");
    warning.setInformativeText("Vuoi veramente eliminare questo plesso?");
    warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    warning.setDefaultButton(QMessageBox::Cancel);
    int ret = warning.exec();
    if(ret==QMessageBox::Yes) {
        emit removePlessoClicked(selected_plesso);
    }
    buildPlessoTable();
}

void PresideContent::buildPlessoTable(){
    removeInsWidget();
    tablePlessi=new QTableWidget(this);
    tablePlessi->setColumnCount(6);
    tablePlessi->setRowCount(0);
    QStringList headerPlessi;
    headerPlessi<<"Nome"<<"Sede"<<"Via"<<"Telefono"<<"Personale Ata"<<"Metri Quadri";
    tablePlessi->setHorizontalHeaderLabels(headerPlessi);
    tablePlessi->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tablePlessi->setSelectionMode(QAbstractItemView::SingleSelection);
    tablePlessi->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int i=0; i<table->columnCount(); i++)
        tablePlessi->horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);
    tablePlessi->setMinimumWidth(419);
    connect(tablePlessi,SIGNAL(cellClicked(int,int)),this,SLOT(setSelectedPlesso(int)));
    connect(tablePlessi,SIGNAL(cellClicked(int,int)),this,SLOT(enableButtonP()));
    ListaPlessi* lp=new ListaPlessi();
    if(!(lp->Vuota())){
        int row=0;
        for(ListaPlessi::iteratorePlessi it=lp->begin(); it!=lp->end(); ++it){
            tablePlessi->setRowCount(row+1);
            QTableWidgetItem *nome = new QTableWidgetItem(it->getNome());
            QTableWidgetItem *sede = new QTableWidgetItem(it->getSede());
            QTableWidgetItem *via = new QTableWidgetItem(it->getVia());
            QTableWidgetItem *tel = new QTableWidgetItem(it->getTelefono());
            QTableWidgetItem *pers = new QTableWidgetItem(QString::number(it->getAta()));
            QTableWidgetItem *mq = new QTableWidgetItem(QString::number(it->getMq()));
            tablePlessi->setItem(row,0,nome);
            tablePlessi->setItem(row,1,sede);
            tablePlessi->setItem(row,2,via);
            tablePlessi->setItem(row,3,tel);
            tablePlessi->setItem(row,4,pers);
            tablePlessi->setItem(row,5,mq);
            row++;
        }
    }
    else{
        std::cout<<"tabella vuota"<<std::endl;
    }
    layout_Table->addWidget(tablePlessi);
}

void PresideContent::buildPlessoView(){
    removeInsWidget();
    insPlessoView= new insertPlesso(this);
    connect(insPlessoView,SIGNAL(inserisciPlesso(QString,QString,QString,QString,int,double)),this,SIGNAL(inserisciPlesso(QString,QString,QString,QString,int,double)));
    std::cout<<"arrivatibuildPlesso"<<std::endl;
    layout_Table->addWidget(insPlessoView);
}

void PresideContent::buildAtaView(){
    removeInsWidget();
    insAtaView= new insertAta(this);
    connect(insAtaView,SIGNAL(inserisciAta(QString,QString,int,int,int,int,int,int,QString,QString,QString,double)),this,SIGNAL(inserisciAta(QString,QString,int,int,int,int,int,int,QString,QString,QString,double)));
    layout_Table->addWidget(insAtaView);
}

void PresideContent::buildDocenteView(){
    removeInsWidget();
    insDocenteView= new insertDocente(this);
    connect(insDocenteView,SIGNAL(inserisciDocente(QString,QString,int,int,int,int,int,int,QString,QString,QString,double)),this,SIGNAL(inserisciDocente(QString,QString,int,int,int,int,int,int,QString,QString,QString,double)));
    layout_Table->addWidget(insDocenteView);
}

void PresideContent::buildPresideView(){
    removeInsWidget();
    insPresideView= new insertPreside(this);
    connect(insPresideView,SIGNAL(inserisciPreside(QString,QString,int,int,int,int,int,int,QString,QString,QString,double,double,int,QString)),this,SIGNAL(inserisciPreside(QString,QString,int,int,int,int,int,int,QString,QString,QString,double, double,int,QString)));
    layout_Table->addWidget(insPresideView);
}

void PresideContent::removeInsWidget(){
    delete insPlessoView;
    delete insAtaView;
    delete insDocenteView;
    delete insPresideView;
    delete tablePlessi;
    insPlessoView=0;
    insAtaView=0;
    insDocenteView=0;
    insPresideView=0;
    tablePlessi=0;
    layout_Table->removeWidget(insPlessoView);
    layout_Table->removeWidget(insAtaView);
    layout_Table->removeWidget(insDocenteView);
    layout_Table->removeWidget(insPresideView);
    layout_Table->removeWidget(tablePlessi);
}

void PresideContent::setSelectedUser(int r){
    selected_user=table->item(r,2)->text();
    enableButtons();
    updateLabel();
}

void PresideContent::setSelectedPlesso(int r){
    selected_plesso=tablePlessi->item(r,0)->text();
    enableButtonP();
}

void PresideContent::updateLabel(){
    selected_user_label->setText(selected_user);
}

void PresideContent::refreshTable(){
    selected_user="";
    updateLabel();
    table->clearContents();
    table->setRowCount(0);
}

void PresideContent::buildTable(){
    refreshTable();
    if(!(pli->Vuota())){
        int row=0;
        for(lista<personale>::iteratore it=pli->begin(); it!=pli->end(); ++it){
            table->setRowCount(row+1);
            QTableWidgetItem *cognome = new QTableWidgetItem(it->getCognome());
            QTableWidgetItem *nome = new QTableWidgetItem(it->getNome());
            QTableWidgetItem *username = new QTableWidgetItem(it->getNomeutente());
            QTableWidgetItem *tipo = new QTableWidgetItem(it->openRightView());
            table->setItem(row,0,cognome);
            table->setItem(row,1,nome);
            table->setItem(row,2,username);
            table->setItem(row,3,tipo);
            row++;
        }
    }
    else{
        std::cout<<"tabella vuota"<<std::endl;
    }
}

void PresideContent::showInfoSelection(){
    QMessageBox info;
    info.setWindowTitle("Informazioni Riguardo l'utente");
    info.setText("Hai selezionato l'utente: <b>"+selected_user+"</b>");
    personale* utente=pli->trova(selected_user);
    if(utente->openRightView()=="ata"){
        QVector<QString> i= utente->ottieniInfo();
        QString informazioni=
                "Nome: "+i[0]+"\n\n"
                "Cognome: "+i[1]+"\n\n"
                "Orario Settimanale\n\n"
                "Lunedi: "+i[2]+"\n\n"
                "Martedi: "+i[3]+"\n\n"
                "Mercoledi: "+i[4]+"\n\n"
                "Giovedi: "+i[5]+"\n\n"
                "Venerdi: "+i[6]+"\n\n"
                "Sabato: "+i[7]+"\n\n"
                "Username: "+i[8]+"\n\n"
                "Password: "+i[9]+"\n\n"
                "Plesso di afferenza: "+i[10]+"\n\n"
                "Paga al m/q: "+i[11]+"\n\n"
                "Stipendio mensile: "+QString::number(utente->stipendio())+"\n\n";
        info.setDetailedText(informazioni);
    }
    else if(utente->openRightView()=="docente"){
        QVector<QString> i= utente->ottieniInfo();
        QString informazioni=
                "Nome: "+i[0]+"\n\n"
                "Cognome: "+i[1]+"\n\n"
                "Orario Settimanale\n\n"
                "Lunedi: "+i[2]+"\n\n"
                "Martedi: "+i[3]+"\n\n"
                "Mercoledi: "+i[4]+"\n\n"
                "Giovedi: "+i[5]+"\n\n"
                "Venerdi: "+i[6]+"\n\n"
                "Sabato: "+i[7]+"\n\n"
                "Username: "+i[8]+"\n\n"
                "Password: "+i[9]+"\n\n"
                "Plesso di afferenza: "+i[10]+"\n\n"
                "Paga all'ora: "+i[11]+"\n\n"
                "Stipendio mensile: "+QString::number(utente->stipendio())+"\n\n";
        info.setDetailedText(informazioni);
    }
    else{//preside
        QVector<QString> i= utente->ottieniInfo();
        QString informazioni=
                "Nome: "+i[0]+"\n\n"
                "Cognome: "+i[1]+"\n\n"
                "Orario Settimanale\n\n"
                "Lunedi: "+i[2]+"\n\n"
                "Martedi: "+i[3]+"\n\n"
                "Mercoledi: "+i[4]+"\n\n"
                "Giovedi: "+i[5]+"\n\n"
                "Venerdi: "+i[6]+"\n\n"
                "Sabato: "+i[7]+"\n\n"
                "Username: "+i[8]+"\n\n"
                "Password: "+i[9]+"\n\n"
                "Plesso di afferenza: "+i[10]+"\n\n"
                "Paga all'ora: "+i[11]+"\n\n"
                "Paga all'ora di straordinari: "+i[12]+"\n\n"
                "Ore di straordinari: "+i[13]+"\n\n"
                "Numero di Telefono: "+i[14]+"\n\n"
                "Stipendio mensile: "+QString::number(utente->stipendio())+"\n\n";
        info.setDetailedText(informazioni);
    }
    info.setStandardButtons(QMessageBox::Cancel);
    info.setDefaultButton(QMessageBox::Cancel);
    info.exec();
}

//FIGLI

PresideContent::~PresideContent(){

    removeInsWidget();
    model=0;

    delete i_plesso;
    delete i_ata;
    delete i_docente;
    delete i_preside;

    delete insPlessoView;
    delete insAtaView;
    delete insDocenteView;
    delete insPresideView;

    delete table;
    delete selected_text_label;
    delete selected_user_label;
    delete remove_user;

    delete show_info;
    delete show_plessi;

    delete layout_Buttons;
    delete layout_Table;

    delete layout;
}

