#ifndef ATA
#define ATA

#include"ATA.h"


ata::ata(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso* s, double p_mq): personale(n, c, lun, mar, mer, gio, ven, sab, n_u, p, s), paga_mq(p_mq) {}

double ata::stipendio() const {
    int num_persone=getScuola().getAta();
    double metri= getScuola().getMq();
    return (metri/num_persone)*paga_mq;
}

void ata::writeTipo(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("tipologia", "ata");
}

void ata::writeSpecifiche(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("paga_mq", QString::number(paga_mq));
}

void ata::openRightWindow(){
    AtaWindow w(this->getNomeutente());
    w.show();
}

double ata::getPagaM() const {return paga_mq;}
void ata::setPagaM(double pm) {paga_mq=pm;}

#endif // ATA
