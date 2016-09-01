#include "PresideView.h"

PresideView::PresideView(lista<personale>* li, preside* user_preside, QWidget *parent) : QWidget(parent), pli(li)
{
    content= new PresideContent(pli, this, user_preside);
    label=new QLabel(user_preside->getCognome(),this);
    exit=new QPushButton("Esci",this);

    connect(exit,SIGNAL(clicked()),this,SLOT(quit()));

    layout=new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(content);
    layout->addWidget(exit);

    setLayout(layout);
}

void PresideView::quit(){
    delete this;
}

PresideView::~PresideView(){

    delete label;
    delete exit;
    delete layout;

    label=0;
    exit=0;
    layout=0;
    content=0;
    std::cout<<"arrivati~presideView"<<std::endl;

    emit disconnectUserView();
    delete content;
}

PresideContent* PresideView::getPresideContent(){
    return content;
}
