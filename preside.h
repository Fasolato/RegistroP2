#ifndef PRESIDEH
#define PRESIDEH

#include"docente.h"
#include"PresideWindow.h"

using namespace std;

class preside: public docente
{
    private:
		double paga_straordinari;
		int ore_straordinari;
        QString numero_telefono;
	public:
		virtual double stipendio() const;
        virtual void writeTipo(QXmlStreamWriter& xmlWriter) const;
        virtual void writeSpecifiche(QXmlStreamWriter& xmlWriter) const;
        virtual void openRightWindow();
        preside(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso* s, double paga, double ps, int os, QString num);
        double getPagaS() const;
        int getOreS() const;
        QString getTel() const;
        void setPagaS(double p);
        void setOreS(int o);
        void setTel(QString t);
};


#endif // PRESIDEH
