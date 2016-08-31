#include "DocenteView.h"

DocenteView::DocenteView(docente* user_docente, QWidget *parent) : QWidget(parent)
{
        label=new QLabel(user_docente->getCognome(),this);
        exit=new QPushButton("Esci",this);

        connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));

        layout=new QVBoxLayout(this);
        layout->addWidget(label);
        layout->addWidget(exit);

        setLayout(layout);
}

DocenteView::~DocenteView(){
    emit disconnectUserView();
}
