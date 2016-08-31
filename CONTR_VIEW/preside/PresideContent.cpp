#include"PresideContent.h"

PresideContent::PresideContent(lista<personale>* li, QWidget *parent, preside* model_) :
    QWidget(parent), pli(li), model(model_)
{
    std::cout<<"arrivati"<<std::endl;
    selected_user="";

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
    remove_user=new QPushButton("Rimuovi utente",this);
    remove_user->setMaximumWidth(350);
    show_info=new QPushButton("Dettagli utente",this);
    show_info->setMaximumWidth(350);

    connect(remove_user,SIGNAL(clicked()),this,SLOT(removeUser()));
    //connect(insert_User,SIGNAL(insertUserClicked(QString,QString,QString,int)),this,SIGNAL(insertUserClicked(QString,QString,QString,int)));
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
    layout_Buttons->addWidget(remove_user);
    layout_Buttons->addSpacing(15);
    /*layout_Buttons->addWidget(insert_User);
    layout_Buttons->addStretch(1);
    */
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
    delete table;
    delete selected_text_label;
    delete selected_user_label;
    delete remove_user;

    delete show_info;

    delete layout_Buttons;
    delete layout_Table;

    delete layout;
}
