#ifndef PERSONALEH
#define PERSONALEH

#include<QXmlStreamWriter>
#include<iostream>

#include<QString>
#include"orarioSettimanale.h"
#include"plesso.h"

using namespace std;

class personale
{
    private:
		QString nome;
		QString cognome;
        orarioSettimanale oreSettimana;
		QString nome_utente;
		QString password; // i controlli posso farli dopo(?)
        plesso* scuola_afferenza;

	public:
        virtual double stipendio() const=0; //virtuale puro
        virtual void writeTipo(QXmlStreamWriter& xmlWriter) const =0;// virtuale puro
        virtual void writeSpecifiche(QXmlStreamWriter& xmlWriter) const =0;// virtuale puro
        virtual QString openRightView() const=0;// virtuale puro
        virtual QVector<QString> ottieniInfo()=0;// virtuale puro
        personale(QString n, QString c, int lun, int mar, int mer, int gio, int ven, int sab, QString n_u, QString p, plesso* s);//costruttore
		//metodi get
	QString getNome() const;
	QString getCognome() const;
        vector<int> getOre() const;
	QString getNomeutente() const;
	QString getPassword() const;
        plesso* getScuola() const;
		//metodi post
        void setNome(QString n);
        void setCognome(QString c);
        void setOre(vector<int> v);
        void setNomeutente(QString n_u);
        void setPassword(QString p);
        void setScuola(plesso *s);
        virtual ~personale() {}
};


#endif // PERSONALEH
