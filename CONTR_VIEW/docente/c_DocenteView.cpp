#include"c_DocenteView.h"

C_DocenteView::C_DocenteView(QObject *parent, docente* user , DocenteView* d_view) :
    QObject(parent), model(user), view(d_view)
{
    //clientprofile=new C_ClientProfile(this,model,view->getClientProfile());
    //clientweb=new C_ClientWeb(this,model,view->getClientWeb());
    //clientsearch=new C_ClientSearch(this,model,view->getClientSearch());
}

C_DocenteView::~C_DocenteView(){
    //delete clientprofile;
    //delete clientweb;
    //delete clientsearch;
}
