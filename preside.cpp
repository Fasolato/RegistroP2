#ifndef PRESIDE
#define PRESIDE

#include"preside.h"

preside::preside(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso* s, double paga, double ps, int os, QString num): docente(n, c, lun, mar, mer, gio, ven, sab, n_u, p, s, paga), paga_straordinari(ps), ore_straordinari(os), numero_telefono(num) {}

double preside::stipendio() const {
	double tot= docente::stipendio();
	tot+=(paga_straordinari*ore_straordinari);
	return tot;
	}

void preside::writeTipo(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("tipologia", "preside");
}

void preside::writeSpecifiche(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("paga_oraria", QString::number(getPagaO()));
    xmlWriter.writeTextElement("paga_straordinari", QString::number(paga_straordinari));
    xmlWriter.writeTextElement("ore_straordinari", QString::number(ore_straordinari));
    xmlWriter.writeTextElement("numero_telefono", numero_telefono);
}

void preside::openRightView(){
    emit openPresideView();
}

double preside::getPagaS() const {return paga_straordinari;}
int preside::getOreS() const {return ore_straordinari;}
QString preside::getTel() const {return numero_telefono;}
void preside::setPagaS(double p) {paga_straordinari=p;}
void preside::setOreS(int o) {ore_straordinari=o;}
void preside::setTel(QString t) {numero_telefono=t;}


#endif // PRESIDE
