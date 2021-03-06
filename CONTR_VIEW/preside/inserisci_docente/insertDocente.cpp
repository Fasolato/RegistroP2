#include"insertDocente.h"

insertDocente::insertDocente(QWidget *parent) : QFrame(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    QSize sizeLine(150,18);
    showMaximized();

    title=new QLabel("Inserisci nuovo membro del corpo Docenti",this);
    title->setFont(QFont("Helvetica [Cronyx]", 14, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps;");
    Orario=new QLabel("Orario Settimanale",this);
    Orario->setFont(QFont("Helvetica [Cronyx]", 14, QFont::Bold));
    Orario->setStyleSheet("font-variant: small-caps;");

    nome=new QLabel("Nome",this);
    text_Nome=new QLineEdit(this);
    text_Nome->setFixedSize(sizeLine);
    cognome=new QLabel("Cognome",this);
    text_Cognome=new QLineEdit(this);
    text_Cognome->setFixedSize(sizeLine);
    lunedi=new QLabel("lunedi",this);
    text_Lun=new QLineEdit(this);
    text_Lun->setFixedSize(sizeLine);
    martedi=new QLabel("martedi",this);
    text_Mar=new QLineEdit(this);
    text_Mar->setFixedSize(sizeLine);
    mercoledi=new QLabel("mercoledi",this);
    text_Mer=new QLineEdit(this);
    text_Mer->setFixedSize(sizeLine);
    giovedi=new QLabel("giovedi",this);
    text_Gio=new QLineEdit(this);
    text_Gio->setFixedSize(sizeLine);
    venerdi=new QLabel("venerdi",this);
    text_Ven=new QLineEdit(this);
    text_Ven->setFixedSize(sizeLine);
    sabato=new QLabel("sabato",this);
    text_Sab=new QLineEdit(this);
    text_Sab->setFixedSize(sizeLine);
    username=new QLabel("Username",this);
    text_User=new QLineEdit(this);
    text_User->setFixedSize(sizeLine);
    password=new QLabel("Password",this);
    text_Pass=new QLineEdit(this);
    text_Pass->setFixedSize(sizeLine);
    scuola=new QLabel("Scuola di appartenenza",this);
    text_Scuola=new QLineEdit(this);
    text_Scuola->setFixedSize(sizeLine);
    p_oraria=new QLabel("Paga all'ora",this);
    text_P_oraria=new QLineEdit(this);
    text_P_oraria->setFixedSize(sizeLine);

    insert=new QPushButton("Aggiungi",this);
    insert->setToolTip("Inserisci il nuovo utente \n N.B. Tutti i campi devono essere riempiti");
    insert->setToolTipDuration(3000);

    connect(insert,SIGNAL(clicked()),this,SLOT(insertUser()));

    layout=new QGridLayout();

        layout->addWidget(title,0,0,1,2);
        layout->setRowMinimumHeight(1,10);
        layout->addWidget(nome,2,0);
        layout->addWidget(text_Nome,2,1);
        layout->addWidget(cognome,3,0);
        layout->addWidget(text_Cognome,3,1);
        layout->addWidget(Orario,4,0,1,2);
        layout->setRowMinimumHeight(1,10);
        layout->addWidget(lunedi,5,0);
        layout->addWidget(text_Lun,5,1);
        layout->addWidget(martedi,6,0);
        layout->addWidget(text_Mar,6,1);
        layout->addWidget(mercoledi,7,0);
        layout->addWidget(text_Mer,7,1);
        layout->addWidget(giovedi,8,0);
        layout->addWidget(text_Gio,8,1);
        layout->addWidget(venerdi,9,0);
        layout->addWidget(text_Ven,9,1);
        layout->addWidget(sabato,10,0);
        layout->addWidget(text_Sab,10,1);
        layout->addWidget(username,2,2);
        layout->addWidget(text_User,2,3);
        layout->addWidget(password,3,2);
        layout->addWidget(text_Pass,3,3);
        layout->addWidget(scuola,4,2);
        layout->addWidget(text_Scuola,4,3);
        layout->addWidget(p_oraria,5,2);
        layout->addWidget(text_P_oraria,5,3);
        layout->setRowMinimumHeight(6,10);
        layout->addWidget(insert,10,3);

    setLayout(layout);
    setMaximumWidth(800);
}

void insertDocente::insertUser(){

    if(text_Nome->text().isEmpty() || text_Nome->text().isNull() ||
       text_Cognome->text().isEmpty() || text_Cognome->text().isNull() ||
       text_Lun->text().isEmpty() || text_Lun->text().isNull() ||
       text_Mar->text().isEmpty() || text_Mar->text().isNull() ||
       text_Mer->text().isEmpty() || text_Mer->text().isNull() ||
       text_Gio->text().isEmpty() || text_Gio->text().isNull() ||
       text_Ven->text().isEmpty() || text_Ven->text().isNull() ||
       text_Sab->text().isEmpty() || text_Sab->text().isNull() ||
       text_User->text().isEmpty() || text_User->text().isNull() ||
       text_Pass->text().isEmpty() || text_Pass->text().isNull() ||
       text_Scuola->text().isEmpty() || text_Scuola->text().isNull() ||
       text_P_oraria->text().isEmpty() || text_P_oraria->text().isNull()){
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Inserisci nuovo utente");
        warning.setText("E' necessario compilare tutti i campi.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
    else{
        QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Inserisci nuovo utente");
        warning.setText("Sei sicuro di voler inserire l'utente: <b>"+text_User->text()+"</b>?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit inserisciDocente(text_Nome->text(), text_Cognome->text(), text_Lun->text().toInt(), text_Mar->text().toInt(), text_Mer->text().toInt(), text_Gio->text().toInt(), text_Ven->text().toInt(), text_Sab->text().toInt(), text_User->text(), text_Pass->text(), text_Scuola->text(), text_P_oraria->text().toDouble());
            clearTextEdit();
        }
    }
}

void insertDocente::clearTextEdit(){
    text_Nome->clear();
    text_Cognome->clear();
    text_Lun->clear();
    text_Mar->clear();
    text_Mer->clear();
    text_Gio->clear();
    text_Ven->clear();
    text_Sab->clear();
    text_User->clear();
    text_Pass->clear();
    text_Scuola->clear();
    text_P_oraria->clear();
}

insertDocente::~insertDocente(){
    delete title;
    delete Orario;
    delete nome;
    delete text_Nome;
    delete cognome;
    delete text_Cognome;
    delete lunedi;
    delete text_Lun;
    delete martedi;
    delete text_Mar;
    delete mercoledi;
    delete text_Mer;
    delete giovedi;
    delete text_Gio;
    delete venerdi;
    delete text_Ven;
    delete sabato;
    delete text_Sab;
    delete username;
    delete text_User;
    delete password;
    delete text_Pass;
    delete scuola;
    delete text_Scuola;
    delete p_oraria;
    delete text_P_oraria;

    delete insert;

    delete layout;
}
