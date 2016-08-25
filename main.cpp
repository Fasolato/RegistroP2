//#include "Viste/mainwindow.h"
#include "mainwindow.h"
#include "lista.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ListaPlessi lp;
    ListaPlessi* plp=&lp;
    lista<personale> li(plp);
    /*plesso *p1= new plesso("plesso1", "Padova", "Garibaldi 28", "049-736405", 4, 500);
    plesso *p2= new plesso("plesso2", "Padova", "A. Volta 12", "049-8253110", 7, 650);
    lp.aggiungiMembro(p2);
    lp.aggiungiMembro(p1);

    docente*u1= new docente("Giovanni", "Soave", 3, 5, 2, 0, 3, 4, "MSoave01", "peppapig", plp->ricercaPlesso("plesso2"), 20.5);
    docente*u2= new docente("Paola", "Merli", 0, 4, 3, 3, 5, 4, "PMerli01", "ciao123", plp->ricercaPlesso("plesso1"), 17.3);
    li.aggiungiMembro(u2);
    li.aggiungiMembro(u1);*/

    return a.exec();
}
