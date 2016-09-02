#include "DocenteView.h"

DocenteView::DocenteView(docente* user_docente, QWidget *parent) : QWidget(parent)
{
        label=new QLabel("Benvenuto "+user_docente->getNomeutente(),this);
        label->setFixedHeight(20);

        title1=new QLabel("Informazioni Utente",this);
        title1->setFont(QFont("Helvetica [Cronyx]", 14, QFont::Bold));
        title1->setStyleSheet("font-variant: small-caps;");
        title2=new QLabel("Plesso di afferenza",this);
        title2->setFont(QFont("Helvetica [Cronyx]", 14, QFont::Bold));
        title2->setStyleSheet("font-variant: small-caps;");
        Orario=new QLabel("Orario Settimanale",this);
        Orario->setFont(QFont("Helvetica [Cronyx]", 14, QFont::Bold));
        Orario->setStyleSheet("font-variant: small-caps;");

        nome=new QLabel("Nome: ",this);
        text_Nome=new QLabel(user_docente->getNome(),this);
        cognome=new QLabel("Cognome: ",this);
        text_Cognome=new QLabel(user_docente->getCognome(),this);
        lunedì=new QLabel("lunedì: ",this);
        text_Lun=new QLabel(QString::number(user_docente->getOre()[0]),this);
        martedì=new QLabel("martedì: ",this);
        text_Mar=new QLabel(QString::number(user_docente->getOre()[1]),this);
        mercoledì=new QLabel("mercoledì: ",this);
        text_Mer=new QLabel(QString::number(user_docente->getOre()[2]),this);
        giovedì=new QLabel("giovedì: ",this);
        text_Gio=new QLabel(QString::number(user_docente->getOre()[3]),this);
        venerdì=new QLabel("venerdì: ",this);
        text_Ven=new QLabel(QString::number(user_docente->getOre()[4]),this);
        sabato=new QLabel("sabato: ",this);
        text_Sab=new QLabel(QString::number(user_docente->getOre()[5]),this);
        username=new QLabel("Username: ",this);
        text_User=new QLabel(user_docente->getNomeutente(),this);
        password=new QLabel("Password: ",this);
        text_Pass=new QLabel(user_docente->getPassword(),this);
        scuola=new QLabel("Scuola di appartenenza: ",this);
        text_Scuola=new QLabel(user_docente->getScuola().getNome(),this);
        p_oraria=new QLabel("Paga all'ora: ",this);
        text_P_oraria=new QLabel(QString::number(user_docente->getPagaO()),this);
        stipendio=new QLabel("Stipendio mensile percepito: : ",this);
        text_Stip=new QLabel(QString::number(user_docente->stipendio()),this);

        plesso pl=user_docente->getScuola();

        nomeS=new QLabel("Nome: ",this);
        text_nomeS=new QLabel(pl.getNome(),this);
        sede=new QLabel("Sede: ",this);
        text_Sede=new QLabel(pl.getSede(),this);
        via=new QLabel("Via: ",this);
        text_Via=new QLabel(pl.getVia(),this);
        tel=new QLabel("Numero di telefono: ",this);
        text_Tel=new QLabel(pl.getTelefono(),this);
        pers_ata=new QLabel("Personale ATA presente: ",this);
        text_P_ata=new QLabel(QString::number(pl.getAta()),this);
        m_q=new QLabel("Metri quadri: ",this);
        text_Mq=new QLabel(QString::number(pl.getMq()),this);

        exit=new QPushButton("Esci",this);

        connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));

        layout1=new QGridLayout();
        layout2=new QGridLayout();


            layout1->addWidget(title1,0,0,1,2);
            layout1->setRowMinimumHeight(1,10);
            layout1->addWidget(nome,2,0);
            layout1->addWidget(text_Nome,2,1);
            layout1->addWidget(cognome,3,0);
            layout1->addWidget(text_Cognome,3,1);
            layout1->addWidget(Orario,4,0,1,2);
            layout1->setRowMinimumHeight(1,10);
            layout1->addWidget(lunedì,5,0);
            layout1->addWidget(text_Lun,5,1);
            layout1->addWidget(martedì,6,0);
            layout1->addWidget(text_Mar,6,1);
            layout1->addWidget(mercoledì,7,0);
            layout1->addWidget(text_Mer,7,1);
            layout1->addWidget(giovedì,8,0);
            layout1->addWidget(text_Gio,8,1);
            layout1->addWidget(venerdì,9,0);
            layout1->addWidget(text_Ven,9,1);
            layout1->addWidget(sabato,10,0);
            layout1->addWidget(text_Sab,10,1);
            layout1->addWidget(username,11,0);
            layout1->addWidget(text_User,11,1);
            layout1->addWidget(password,12,0);
            layout1->addWidget(text_Pass,12,1);
            layout1->addWidget(scuola,13,0);
            layout1->addWidget(text_Scuola,13,1);
            layout1->addWidget(p_oraria,14,0);
            layout1->addWidget(text_P_oraria,14,1);
            layout1->addWidget(stipendio,15,0);
            layout1->addWidget(text_Stip,15,1);

            layout2->addWidget(title2,0,0,1,2);
            layout2->setRowMinimumHeight(1,10);
            layout2->addWidget(nomeS,2,0);
            layout2->addWidget(text_nomeS,2,1);
            layout2->addWidget(sede,3,0);
            layout2->addWidget(text_Sede,3,1);
            layout2->addWidget(via,4,0);
            layout2->addWidget(text_Via,4,1);
            layout2->addWidget(tel,5,0);
            layout2->addWidget(text_Tel,5,1);
            layout2->addWidget(pers_ata,6,0);
            layout2->addWidget(text_P_ata,6,1);
            layout2->addWidget(m_q,7,0);
            layout2->addWidget(text_Mq,7,1);

            layout= new QHBoxLayout();
            layout->addLayout(layout1);
            layout->addSpacing(400);
            layout->addLayout(layout2);

            layoutFinal= new QVBoxLayout(this);
            layoutFinal->addWidget(label);
            layoutFinal->addLayout(layout);
            layoutFinal->addWidget(exit);

            std::cout<<"arrivatiCreazione"<<std::endl;
        setLayout(layoutFinal);
        setMaximumWidth(1200);
}

DocenteView::~DocenteView(){
    emit disconnectUserView();
}
