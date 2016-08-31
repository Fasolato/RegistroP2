#include"c_AtaView.h"

C_AtaView::C_AtaView(QObject *parent, ata* user , AtaView* a_view) :
    QObject(parent), model(user), view(a_view)
{
    //clientprofile=new C_ClientProfile(this,model,view->getClientProfile());
    //clientweb=new C_ClientWeb(this,model,view->getClientWeb());
    //clientsearch=new C_ClientSearch(this,model,view->getClientSearch());
}

C_AtaView::~C_AtaView(){
    //delete clientprofile;
    //delete clientweb;
    //delete clientsearch;
}
