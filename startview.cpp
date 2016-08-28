#include "startview.h"

MainWindow::MainWindow(QWidget *parent) : QFrame(parent)
{
        setWindowTitle("MainWindow");
        setFrameStyle(QFrame::Panel | QFrame::Raised);
        setFrameShadow(QFrame::Plain);
        setFixedSize(320,160);

        setStyleSheet("MainWindow{ background-color: grey; border: 1px solid #FFF;}");

        label=new QLabel("Inserisci i tuoi Dati: ",this);
        label->setStyleSheet("color: black; font: 18pt;");
        tUser=new QLineEdit(this);
        tUser->setPlaceholderText("inserisci qui lo username");
        tUser->setFixedSize(180,30);
        tPass=new QLineEdit(this);
        tPass->setPlaceholderText("inserisci qui la password");
        tPass->setFixedSize(180,30);
        button=new QPushButton("Login",this);
        button->setDisabled(true);

        setLogin();

        connect(button,SIGNAL(clicked()),this,SLOT(getLogin()));
        connect(tUser,SIGNAL(returnPressed()),this,SLOT(getLogin()));
        connect(tPass,SIGNAL(returnPressed()),this,SLOT(getLogin()));

        layout=new QVBoxLayout(this);
        layout->addWidget(label);
        layout->addWidget(tUser,0,Qt::AlignCenter);
        layout->addWidget(tPass,0,Qt::AlignCenter);
        layout->addWidget(button,0,Qt::AlignRight);

        button->setToolTip(tr("Esegui il login"));
        button->setToolTipDuration(3000);

        setLayout(layout);
    }

    void MainWindow::getLogin(){
        if(!tUser->text().isEmpty() && !tUser->text().isNull() && !tPass->text().isEmpty() && !tPass->text().isNull()){


            personale *current_user=li.trova(tUser->text(), tPass->text());
            if(current_user){
                std::cout<<"arrivati"<<std::endl;
                current_user->openRightWindow();
            }
            setLogin();
        }
        else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Information);
            warning.setText("UserName non valido");
            warning.exec();
        }
    }

    void MainWindow::selectText(){
        tUser->setStyleSheet("color: #808080;");
        tPass->setStyleSheet("color: #808080;");
        if(!tUser->text().isEmpty() && !tUser->text().isNull() && !tPass->text().isEmpty() && !tPass->text().isNull())
            button->setEnabled(true);
        disconnect(tUser,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
    }

    void MainWindow::setLogin(){
        button->setDisabled(true);
        tUser->clear();
        tUser->setStyleSheet("color: #808080;");
        connect(tUser,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
        tPass->clear();
        tPass->setStyleSheet("color: #808080;");
        connect(tPass,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
    }