//#include "Viste/mainwindow.h"
#include "startview.h"
#include "c_startview.h"
#include "lista.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lista<personale> list;
    StartView view;
    C_StartView controller(&list,&view);

    return a.exec();
}

