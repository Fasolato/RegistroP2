#include"PresideContent.h"

PresideContent::PresideContent(lista<personale>* li, QWidget *parent, preside* model_) :
    QWidget(parent), pli(li), model(model_)
{
    selected_user="";

    insPlessoView=0;
    insAtaView=0;
    insDocenteView=0;
    insPresideView=0;

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
    selected_user_label->setMinimumHeight(30);

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

    connect(remove_user,SIGNAL(clicked()),this,SLOT(removeUser()));

    connect(i_plesso,SIGNAL(clicked()),this,SLOT(buildPlessoView()));
    connect(i_ata,SIGNAL(clicked()),this,SLOT(buildAtaView()));
    connect(i_docente,SIGNAL(clicked()),this,SLOT(buildDocenteView()));
    connect(i_preside,SIGNAL(clicked()),this,SLOT(buildPresideView()));

    connect(insPlessoView,SIGNAL(inserisciPlesso(QString,QString,QString,QString,int,double)),this,SIGNAL(inserisciPlesso(QString,QString,QString,QString,int,double)));
    connect(insAtaView,SIGNAL(inserisciAta(QString,QString,int,int,int,int,int,int,QString,QString,QString,double)),this,SIGNAL(inserisciAta(QString,QString,int,int,int,int,int,int,QString,QString,QString,double)));
    connect(insDocenteView,SIGNAL(inserisciDocente(QString,QString,int,int,int,int,int,int,QString,QString,QString,double)),this,SIGNAL(inserisciDocente(QString,QString,int,int,int,int,int,int,QString,QString,QString,double)));
    connect(insPresideView,SIGNAL(inserisciPreside(QString,QString,int,int,int,int,int,int,QString,QString,QString,double,double,int,QString)),this,SIGNAL(inserisciPreside(QString,QString,int,int,int,int,int,int,QString,QString,QString,double,int,QString)));
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
    layout_Buttons->addWidget(insPlessoView);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(insAtaView);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(insDocenteView);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(insPresideView);
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

void PresideContent::buildPlessoView(){
    insPlessoView= new insertPlesso(this);
}

void PresideContent::buildAtaView(){
    insAtaView= new insertAta(this);
}

void PresideContent::buildDocenteView(){
    insDocenteView= new insertDocente(this);
}

void PresideContent::buildPresideView(){
    insPresideView= new insertPreside(this);
}

void PresideContent::setSelectedUser(int r){
    selected_user=table->item(r,2)->text();
    enableButtons();
    updateLabel();
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

//FIGLI

PresideContent::~PresideContent(){

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

    delete layout_Buttons;
    delete layout_Table;

    delete layout;
}
