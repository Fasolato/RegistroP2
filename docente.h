#ifndef DOCENTEH
#define DOCENTEH

#include"personale.h"
//#include"Viste/DocWindow.h"

using namespace std;

class docente: public personale
{
    private:
        double paga_oraria;

	public:
		virtual double stipendio() const;
        virtual void writeTipo(QXmlStreamWriter& xmlWriter) const;
        virtual void writeSpecifiche(QXmlStreamWriter& xmlWriter) const;
        virtual void openRightWindow();
        docente(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso *s, double paga);
        double getPagaO() const;
        void setPagaO(double po);
};


#endif // DOCENTEH
