#include"c_PresideView.h"

C_PresideView::C_PresideView(lista<personale>* lis, preside* user, QObject *parent, PresideView* p_view) :
    QObject(parent), model(user), view(p_view), li(lis)
{
    c_presidecontent=new C_PresideContent(model, li, this, view->getPresideContent());
}

C_PresideView::~C_PresideView(){

    delete c_presidecontent;
}