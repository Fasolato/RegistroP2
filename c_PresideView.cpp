#include<c_PresideView.h>

C_PresideView::C_PresideView(QObject *parent, preside* user , PresideView* p_view) :
    QObject(parent), model(user), view(p_view)
{
    //clientprofile=new C_ClientProfile(this,model,view->getClientProfile());
    //clientweb=new C_ClientWeb(this,model,view->getClientWeb());
    //clientsearch=new C_ClientSearch(this,model,view->getClientSearch());
}

C_PresideView::~C_PresideView(){
    //delete clientprofile;
    //delete clientweb;
    //delete clientsearch;
}
