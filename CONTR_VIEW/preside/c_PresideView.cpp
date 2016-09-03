#include"c_PresideView.h"

C_PresideView::C_PresideView(ListaPlessi* lp, lista<personale>* lis, preside* user, QObject *parent, PresideView* p_view) :
    QObject(parent), model(user), view(p_view), li(lis), p(lp)
{
    connect(view,SIGNAL(quit()),this,SLOT(quit()));
    c_presidecontent=new C_PresideContent(p, model, li, this, view->getPresideContent());
}

void C_PresideView::quit(){
    std::cout<<"arrivatiquitc_presideView"<<std::endl;
    delete this;
}

C_PresideView::~C_PresideView(){
    delete view;
    view=0;
    delete c_presidecontent;
    c_presidecontent=0;
    std::cout<<"arrivati~c_presideView"<<std::endl;
}
