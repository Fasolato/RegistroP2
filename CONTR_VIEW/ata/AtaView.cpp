#include "AtaView.h"

AtaView::AtaView(ata* user_ata, QWidget *parent) : QWidget(parent)
{
    label=new QLabel(user_ata->getCognome(),this);
    exit=new QPushButton("Esci",this);

    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));

    layout=new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(exit);

    setLayout(layout);
}

AtaView::~AtaView(){
    emit disconnectUserView();
}
