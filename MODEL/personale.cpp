#ifndef PERSONALE
#define PERSONALE

#include"personale.h"


personale::personale(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso* s): nome(n), cognome(c), oreSettimana(lun, mar, mer, gio, ven, sab), nome_utente(n_u), password(p), scuola_afferenza(s) {}

QString personale::getNome() const { return nome; }
QString personale::getCognome() const { return cognome; }
vector<int> personale::getOre() const { return oreSettimana.getOrario(); }
QString personale::getNomeutente() const { return nome_utente; }
QString personale::getPassword() const { return password; }
plesso *personale::getScuola() const { return scuola_afferenza; }
void personale::setNome(QString n) {nome=n;}
void personale::setCognome(QString c) {cognome=c;}
void personale::setOre(vector<int> v) {oreSettimana.modificaOrario(v);}
void personale::setNomeutente(QString n_u) {nome_utente=n_u;}
void personale::setPassword(QString p) {password=p;}
void personale::setScuola(plesso* s) {scuola_afferenza=s;}


#endif // PERSONALE
