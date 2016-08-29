#ifndef DOCENTE
#define DOCENTE

#include<iostream>
#include"docente.h"


docente::docente(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso* s, double paga): personale(n, c, lun, mar, mer, gio, ven, sab, n_u, p, s), paga_oraria(paga) {}

double docente::stipendio() const {
    double tot=0;
    vector<int> v=getOre();
    for(int i=0; i<6; ++i)
        tot=tot+v[i];
    return paga_oraria*tot;
}

void docente::writeTipo(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("tipologia", "docente");
}

void docente::writeSpecifiche(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("paga_oraria", QString::number(paga_oraria));
}

void docente::openRightView(){
    emit openDocenteView();
}

double docente::getPagaO() const {return paga_oraria;}
void docente::setPagaO(double po) {paga_oraria=po;}

#endif // DOCENTE
