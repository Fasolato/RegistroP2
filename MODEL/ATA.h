#ifndef ATAH
#define ATAH

#include"personale.h"

using namespace std;

class ata: public personale
{
private:
		double paga_mq;

public:
        virtual double stipendio() const;//function that returns stipendio
        virtual void writeTipo(QXmlStreamWriter& xmlWriter) const;
        virtual void writeSpecifiche(QXmlStreamWriter& xmlWriter) const;
        virtual QString openRightView() const;//function that opens the right view
        virtual QVector<QString> ottieniInfo();
        ata(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso* s, double p_m);//creator
        double getPagaM() const;//get
        void setPagaM(double pm);//set
};


#endif // ATAH
