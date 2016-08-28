#ifndef ATAH
#define ATAH

#include"personale.h"
#include"AtaWindow.h"

using namespace std;

class ata: public personale
{
private:
		double paga_mq;

public:
        virtual double stipendio() const;
        virtual void writeTipo(QXmlStreamWriter& xmlWriter) const;
        virtual void writeSpecifiche(QXmlStreamWriter& xmlWriter) const;
        virtual QString getTipologia();
        ata(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso* s, double p_m);
        double getPagaM() const;
        void setPagaM(double pm);
};


#endif // ATAH
