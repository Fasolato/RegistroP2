#include "PresideView.h"

PresideView::PresideView(lista<personale>* li, preside* user_preside, QWidget *parent) : QWidget(parent), pli(li)
{
    content= new PresideContent(pli, this, user_preside);
    label=new QLabel("Benvenuto "+user_preside->getNomeutente(),this);
    exit=new QPushButton("Esci",this);

    showMaximized();
    connect(exit,SIGNAL(clicked()),this,SIGNAL(quit()));

    layout=new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(content);
    layout->addWidget(exit);

    setLayout(layout);
}

PresideView::~PresideView(){

    delete label;
    delete exit;
    delete layout;

    label=0;
    exit=0;
    layout=0;
    //delete content;
    content=0;
    std::cout<<"arrivati~presideView"<<std::endl;

    emit disconnectUserView();
}

PresideContent* PresideView::getPresideContent(){
    return content;
}
