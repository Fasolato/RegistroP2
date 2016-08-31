#include "CONTR_VIEW/startview.h"
#include "CONTR_VIEW/c_startview.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListaPlessi lp;
    lista<personale> li(&lp);
    StartView view;
    C_StartView controller(&li,&view);

    return a.exec();
}
