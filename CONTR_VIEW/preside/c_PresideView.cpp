#include"c_PresideView.h"

C_PresideView::C_PresideView(QObject *parent, preside* user , PresideView* p_view) :
    QObject(parent), model(user), view(p_view)
{

}

C_PresideView::~C_PresideView(){
    //delete clientprofile;
    //delete clientweb;
    //delete clientsearch;
}
