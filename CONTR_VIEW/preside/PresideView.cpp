#include "PresideView.h"

PresideView::PresideView(preside* user_preside, QWidget *parent) : QWidget(parent)
{
    label=new QLabel(user_preside->getCognome(),this);
    exit=new QPushButton("Esci",this);

    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));

    layout=new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(exit);

    setLayout(layout);
}

PresideView::~PresideView(){
    emit disconnectUserView();
}
