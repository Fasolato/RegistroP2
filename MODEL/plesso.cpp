#ifndef PLESSO
#define PLESSO

#include"plesso.h"


plesso::plesso(QString n, QString s, QString v, QString t, int p, double m): nome(n), sede(s), via(v), telefono(t), pers_Ata(p), mq(m) {}

QString plesso::getNome() const {return nome;}

QString plesso::getSede() const {return sede;}

QString plesso::getVia() const {return via;}

QString plesso::getTelefono() const {return telefono;}

int plesso::getAta() const {return pers_Ata;}

double plesso::getMq() const {return mq;}

void plesso::modNome(QString n) {nome=n;}

void plesso::modSede(QString s) {sede=s;}

void plesso::modVia(QString v) {via=v;}

void plesso::modTelefono(QString t) {telefono=t;}

void plesso::modAta(int p) {pers_Ata=p;}

void plesso::modMq(double m) {mq=m;}

#endif // PLESSO
