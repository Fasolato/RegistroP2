#include"loginView.h"

LoginView::LoginView(lista<personale>* li, QWidget *parent) : QFrame(parent), pli(li)
{

        setFrameStyle(QFrame::Panel | QFrame::Raised);
        setFrameShadow(QFrame::Plain);
        setLineWidth(3);


        setStyleSheet("LoginWindow{ background-color: red; border: 1px solid #F12;}");

        exit= new QPushButton("Esci", this);
        exit->setFixedSize(150,35);

        connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));

        label=new QLabel("Inserisci i tuoi Dati: ",this);
        label->setStyleSheet("color: black; font: 22pt;");
        label->setFixedSize(250,35);
        tUser=new QLineEdit(this);
        tUser->setPlaceholderText("inserisci qui lo username");
        tUser->setFixedSize(300,35);
        tPass=new QLineEdit(this);
        tPass->setPlaceholderText("inserisci qui la password");
        tPass->setFixedSize(300,35);
        tPass->setEchoMode(QLineEdit::Password);
        button=new QPushButton("Login",this);
        button->setFixedSize(150,35);
        button->setDisabled(true);

        setLogin();

        connect(button,SIGNAL(clicked()),this,SLOT(getLogin()));
        connect(tUser,SIGNAL(returnPressed()),this,SLOT(getLogin()));
        connect(tPass,SIGNAL(returnPressed()),this,SLOT(getLogin()));

        layout1=new QVBoxLayout();
        layout1->addWidget(label);
        layout1->addWidget(tUser,0,Qt::AlignCenter);
        layout1->addWidget(tPass,0,Qt::AlignCenter);

        layout2= new QHBoxLayout();
        layout2->addWidget(button,0,Qt::AlignRight);
        layout2->addWidget(exit,0,Qt::AlignRight);

        button->setToolTip(tr("Esegui il login"));
        button->setToolTipDuration(3000);
        layoutFinal= new QVBoxLayout(this);
        layoutFinal->addLayout(layout1);
        layoutFinal->addLayout(layout2);
        layoutFinal->setAlignment(Qt::AlignCenter);
        setLayout(layoutFinal);
    }

    void LoginView::getLogin(){
        if(!tUser->text().isEmpty() && !tUser->text().isNull() && !tPass->text().isEmpty() && !tPass->text().isNull()){

            personale *current_user=pli->auth(tUser->text(), tPass->text());
            if(current_user){
                emit setPersonale(current_user);
                if(current_user->openRightView()=="ata")
                    emit createAta(current_user);
                else if(current_user->openRightView()=="docente")
                    emit createDocente(current_user);
                else{
                    emit createPreside(current_user);
                }
            }

        else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Information);
            warning.setText("UserName o Password non validi");
            warning.exec();
        }
        setLogin();
      }
    }

    void LoginView::selectText(){
        tUser->setStyleSheet("color: #808080;");
        tPass->setStyleSheet("color: #808080;");
        if(!tUser->text().isEmpty() && !tUser->text().isNull() && !tPass->text().isEmpty() && !tPass->text().isNull())
            button->setEnabled(true);
        disconnect(tUser,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
    }

    void LoginView::setLogin(){
        button->setDisabled(true);
        tUser->clear();
        tUser->setStyleSheet("color: #808080;");
        connect(tUser,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
        tPass->clear();
        tPass->setStyleSheet("color: #808080;");
        connect(tPass,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
    }
