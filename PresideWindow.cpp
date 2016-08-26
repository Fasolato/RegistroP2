#include "PresideWindow.h"

PresideWindow::PresideWindow(QString user, QWidget *parent) : QWidget(parent)
{
        setWindowTitle("PresideWindow");
        label=new QLabel("Inserisci i tuoi Dati: ",this);
        label->setStyleSheet("color: black; font: 18pt;");
        button=new QPushButton("Login",this);
        button->setDisabled(true);



        layout=new QVBoxLayout(this);
        layout->addWidget(label);
        layout->addWidget(button,0,Qt::AlignRight);

        button->setToolTip(tr("Esegui il login"));
        button->setToolTipDuration(3000);

        setLayout(layout);
    }
