#ifndef PLESSOH
#define PLESSOH


#include<QString>

using namespace std;

class plesso
{
private:
    QString nome;
    QString sede;
    QString via;
    QString telefono;
    int pers_Ata;
    double mq;

public:
    plesso(QString n="", QString s="", QString v="", QString t="", int p=0, double m=0);
    QString getNome() const;
    QString getSede() const;
    QString getVia() const;
    QString getTelefono() const;
    int getAta() const;
    double getMq() const;
    void modNome(QString n);
    void modSede(QString s);
    void modVia(QString v);
    void modTelefono(QString t);
    void modAta(int p);
    void modMq(double m);
};


#endif // PLESSOH
