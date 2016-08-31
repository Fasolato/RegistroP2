#include "PresideView.h"

PresideView::PresideView(lista<personale>* li, preside* user_preside, QWidget *parent) : QWidget(parent), pli(li)
{
    content= new PresideContent(pli, this, user_preside);
    label=new QLabel(user_preside->getCognome(),this);
    exit=new QPushButton("Esci",this);

    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));

    layout=new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(content);
    layout->addWidget(exit);

    setLayout(layout);
}

PresideView::~PresideView(){
    emit disconnectUserView();
}

PresideContent* PresideView::getPresideContent(){
    return content;
}
