#include"insertPlesso.h"

insertPlesso::insertPlesso(QWidget *parent) : QFrame(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    QSize sizeLine(200,28);

    title=new QLabel("Inserisci Nuovo Plesso",this);
    title->setFont(QFont("Helvetica [Cronyx]", 14, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps;");

    nome=new QLabel("Nome",this);
    text_Nome=new QLineEdit(this);
    text_Nome->setFixedSize(sizeLine);
    sede=new QLabel("Sede",this);
    text_Sede=new QLineEdit(this);
    text_Sede->setFixedSize(sizeLine);
    via=new QLabel("Via",this);
    text_Via=new QLineEdit(this);
    text_Via->setFixedSize(sizeLine);
    tel=new QLabel("Telefono",this);
    text_Tel=new QLineEdit(this);
    text_Tel->setFixedSize(sizeLine);
    p_ata=new QLabel("Personale Ata presente",this);
    text_P_Ata=new QLineEdit(this);
    text_P_Ata->setFixedSize(sizeLine);
    m_q=new QLabel("Metri quadri",this);
    text_M_q=new QLineEdit(this);
    text_M_q->setFixedSize(sizeLine);

    insert=new QPushButton("Aggiungi",this);
    insert->setToolTip("Inserisci il nuovo plesso \n N.B. Tutti i campi devono essere riempiti");
    insert->setToolTipDuration(3000);

    connect(insert,SIGNAL(clicked()),this,SLOT(insertUser()));

    layout=new QGridLayout(this);

        layout->addWidget(title,0,0,1,2);
        layout->setRowMinimumHeight(1,10);
        layout->addWidget(nome,2,0);
        layout->addWidget(text_Nome,2,1);
        layout->addWidget(sede,3,0);
        layout->addWidget(text_Sede,3,1);
        layout->addWidget(via,4,0);
        layout->addWidget(text_Via,4,1);
        layout->addWidget(tel,5,0);
        layout->addWidget(text_Tel,5,1);
        layout->addWidget(p_ata,6,0);
        layout->addWidget(text_P_Ata,6,1);
        layout->addWidget(m_q,7,0);
        layout->addWidget(text_M_q,7,1);
        layout->setRowMinimumHeight(6,10);
        layout->addWidget(insert,14,1);

    setLayout(layout);
    setMaximumWidth(350);
}

void insertPlesso::insertUser(){

    if(text_Nome->text().isEmpty() || text_Nome->text().isNull() ||
       text_Sede->text().isEmpty() || text_Sede->text().isNull() ||
       text_Via->text().isEmpty() || text_Via->text().isNull() ||
       text_Tel->text().isEmpty() || text_Tel->text().isNull() ||
       text_P_Ata->text().isEmpty() || text_P_Ata->text().isNull() ||
       text_M_q->text().isEmpty() || text_M_q->text().isNull()){
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Inserisci nuovo plesso");
        warning.setText("E' necessario compilare tutti i campi.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
    else{
        QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Inserisci nuovo plesso");
        warning.setText("Sei sicuro di voler inserire il plesso: <b>"+text_Nome->text()+"</b>?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit inserisciPlesso(text_Nome->text(), text_Sede->text(), text_Via->text(), text_Tel->text(), text_P_Ata->text().toInt(), text_M_q->text().toDouble());
            clearTextEdit();
        }
    }
}

void insertPlesso::clearTextEdit(){
    text_Nome->clear();
    text_Sede->clear();
    text_Via->clear();
    text_Tel->clear();
    text_P_Ata->clear();
    text_M_q->clear();
}

insertPlesso::~insertPlesso(){
    delete title;
    delete nome;
    delete text_Nome;
    delete sede;
    delete text_Sede;
    delete via;
    delete text_Via;
    delete tel;
    delete text_Tel;
    delete p_ata;
    delete text_P_Ata;
    delete m_q;
    delete text_M_q;

    delete insert;

    delete layout;
}
