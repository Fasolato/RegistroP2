#ifndef LISTAH
#define LISTAH

#include<iostream>

#include"ATA.h"
#include"preside.h"
#include"listaPlessi.h"

using namespace std;

template <class T>
class lista
{
    static QString filename1;
    friend class iteratore;
private:
    class nodo {
    public:
        nodo();
        ~nodo();
        nodo(T*, nodo*);
        T* dipendente;
        nodo* next;
    };

    nodo* first;

public:

    class iteratore {
        friend class lista<T>;
    private:
        lista<T>::nodo* punt;
    public:
        bool operator==(iteratore) const;
        bool operator!=(iteratore) const;
        iteratore& operator++(); // operator++ prefisso
        iteratore operator++(int); // operator++ postfisso
        T* operator->() const;
    };

    iteratore begin() const;
    iteratore end() const;
    T& operator[](iteratore) const;

    void Load(ListaPlessi* lp);
    void Close();

    //per Test
    void stampa(const T* p) const;

    lista(ListaPlessi* lp=0);
    ~lista();
    bool Vuota() const;
    bool matchMembro(T* p) const;
    void modificaMembro(T*, T*);
    void aggiungiMembro(T*);
    void togliMembro(T*);
    T* ricercaMembro(T* p) const;
    T* trova(QString username) const;
};

template <class T>
QString lista<T>::filename1="/Volumes/KINGS 32 GB/Registro_GitHub/RegistroP2/DATABASE/DB.xml";

// METODI DI LISTA <T>

template <class T>
lista<T>::lista(ListaPlessi *lp): first(0) {
    Load(lp);
}

template <class T>
lista<T>::~lista() {
    Close();
    if(first)
        delete first;
}

template <class T>
bool lista<T>::Vuota() const {
    return first==0;
}

template <class T>
void lista<T>::modificaMembro(T* a, T* b){
    nodo* x= first;
    while(x && !(x->dipendente==a)){
        x= x->next;
    }
    if(x) { //se siamo usciti dal ciclo while a causa della seconda condizione
        x->dipendente=b;
    }
}

template <class T>
bool lista<T>::matchMembro(T* p) const{
    nodo* x= first;
    while(x && !(x->dipendente==p)){
        x= x->next;
    }
    if(x) { //se siamo usciti dal ciclo while a causa della seconda condizione
        return true;
    }
    return false;
}

template <class T>
void lista<T>::aggiungiMembro(T* p){
    if(!matchMembro(p))
        first= new nodo(p, first);
}

template <class T>
void lista<T>::togliMembro(T* p){
    nodo* a= first, *prec= 0;
    while(a && !(a->dipendente==p)){
        prec= a;
        a= a->next;
    }
    if(a) { //se siamo usciti dal ciclo while a causa della seconda condizione
        if(!prec) //se abbiamo trovato il match ma con il primo nodo
            first=a->next;
        else
            prec->next=a->next;
        delete a;
    }
}

template <class T>
T* lista<T>::ricercaMembro(T* p) const{
    nodo* a= first;
    QString username=p->getNomeutente();
    while(a && !(a->dipendente->getNomeutente()==username))
        a= a->next;
    if(a)
        return a->dipendente;
}

template <class T>
T* lista<T>::trova(QString username) const{
    nodo* a= first;
    while(a && !((a->dipendente->getNomeutente()==username))){
        a= a->next;
    }
    if(a)
        return a->dipendente;
    return 0;
}

template <class T>
void lista<T>::Close(){

     QFile file1(filename1);
     file1.open(QIODevice::WriteOnly);

     QXmlStreamWriter xmlWriter(&file1);
     xmlWriter.setAutoFormatting(true);
     xmlWriter.writeStartDocument();

     xmlWriter.writeStartElement("database");

     typename lista<T>::iteratore it =lista<T>::begin();
     for(; it!=lista<T>::end(); ++it){

     xmlWriter.writeStartElement("personale");

     xmlWriter.writeTextElement("username", ((it.punt)->dipendente->getNomeutente()));

     ((it.punt)->dipendente)->writeTipo(xmlWriter);  //scrittura polimorfica del tipo;

     xmlWriter.writeStartElement("profilo");

     xmlWriter.writeStartElement("info_generali");
     xmlWriter.writeTextElement("nome", ((it.punt)->dipendente)->getNome());
     xmlWriter.writeTextElement("cognome", ((it.punt)->dipendente)->getCognome());
     xmlWriter.writeStartElement("orario");
     xmlWriter.writeTextElement("lun", QString::number((((it.punt)->dipendente)->getOre())[0]));
     xmlWriter.writeTextElement("mar", QString::number((((it.punt)->dipendente)->getOre())[1]));
     xmlWriter.writeTextElement("mer", QString::number((((it.punt)->dipendente)->getOre())[2]));
     xmlWriter.writeTextElement("gio", QString::number((((it.punt)->dipendente)->getOre())[3]));
     xmlWriter.writeTextElement("ven", QString::number((((it.punt)->dipendente)->getOre())[4]));
     xmlWriter.writeTextElement("sab", QString::number((((it.punt)->dipendente)->getOre())[5]));
     xmlWriter.writeEndElement(); //orario
     xmlWriter.writeTextElement("password", ((it.punt)->dipendente)->getPassword());
     xmlWriter.writeTextElement("plesso",((it.punt)->dipendente)->getScuola().getNome());
     xmlWriter.writeEndElement(); //info_generali

     xmlWriter.writeStartElement("info_specifiche");
     ((it.punt)->dipendente)->writeSpecifiche(xmlWriter);  //scrittura polimorfica delle specifiche
     xmlWriter.writeEndElement();// info spec

     xmlWriter.writeEndElement();//profilo


     xmlWriter.writeEndElement();//personale

     }

     xmlWriter.writeEndElement(); // database

     xmlWriter.writeEndDocument();

     file1.close();
     std::cout<<"arrivaticlose"<<std::endl;

     std::cout<<std::endl<<"database written"<<std::endl;
}

template <class T>
void lista<T>::Load(ListaPlessi* lp){
    //variabili temporanee
    QString nome_utente="Unknown";
    QString tipo="Unknown";
    QString nome="Unknown";
    QString cognome="Unknown";
    int lun=0;
    int mar=0;
    int mer=0;
    int gio=0;
    int ven=0;
    int sab=0;
    QString password="Unknown";
    QString scuola_afferenza="Unknown";
    double paga_mq=0;
    double paga_oraria=0;
    double paga_straordinari=0;
    int ore_straordinari=0;
    QString numero_telefono="Unknown";


    QFile file1(filename1);
    if (!file1.open(QFile::ReadOnly | QFile::Text)){
        std::cout << "Error: Cannot read file"<< std::endl;
    }
    QXmlStreamReader xmlReader(&file1);
    xmlReader.readNext();

    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())  //legge apertura Tag
        {
            if(xmlReader.name()=="database" || xmlReader.name()=="personale" || xmlReader.name()=="profilo" || xmlReader.name()=="info_generali" || xmlReader.name()=="orario" || xmlReader.name()=="info_specifiche")
            {
               xmlReader.readNext();
            }
            else if(xmlReader.name()=="username")
            {
                nome_utente=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="tipologia")
            {
                tipo=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="nome")
            {
                nome=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="cognome")
            {
                cognome=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="lun")
            {
                lun=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="mar")
            {
                mar=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="mer")
            {
                mer=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="gio")
            {
                gio=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="ven")
            {
                ven=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="sab")
            {
                sab=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="password")
            {
                password=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="plesso")
            {
                scuola_afferenza=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="paga_mq")
            {
                paga_mq=xmlReader.readElementText().toDouble();
            }
            else if(xmlReader.name()=="paga_oraria")
            {
                paga_oraria=xmlReader.readElementText().toDouble();
            }
            else if(xmlReader.name()=="paga_straordinari")
            {
                paga_straordinari=xmlReader.readElementText().toDouble();
            }
            else if(xmlReader.name()=="ore_straordinari")
            {
                ore_straordinari=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="numero_telefono")
            {
                numero_telefono=xmlReader.readElementText();
            }
            else{
                std::cout<<"prob plesso";
                std::cout<<"we got a problem "; //FLAG di allarme;
            }
        }
        else
        {
            if(xmlReader.isEndElement() && xmlReader.name()=="personale"){//leggo </personale> //costruisco user
                    plesso* pl= lp->ricercaPlesso(scuola_afferenza);
                    if(tipo=="ata"){
                        ata* a= new ata(nome, cognome, lun, mar, mer, gio, ven, sab, nome_utente, password, pl, paga_mq);
                        first= new nodo(a, first);
                    }
                    else if(tipo=="docente"){
                        docente* d= new docente(nome, cognome, lun, mar, mer, gio, ven, sab, nome_utente, password, pl, paga_oraria);
                        first= new nodo(d, first);
                    }
                    else{ //tipo=="preside"
                        preside* p= new preside(nome, cognome, lun, mar, mer, gio, ven, sab, nome_utente, password, pl, paga_oraria, paga_straordinari, ore_straordinari, numero_telefono);
                        first= new nodo(p, first);
                    }
                    nome_utente="Unknown";
                    tipo="Unknown";
                    nome="Unknown";
                    cognome="Unknown";
                    lun=0;
                    mar=0;
                    mer=0;
                    gio=0;
                    ven=0;
                    sab=0;
                    password="Unknown";
                    scuola_afferenza="Unknown";
                    paga_mq=0;
                    paga_oraria=0;
                    paga_straordinari=0;
                    ore_straordinari=0;
                    numero_telefono="Unknown";

                xmlReader.readNext();
            }
            else //leggo vuoto o EndElement!="utente"
                xmlReader.readNext();
        }
   }
    std::cout<<std::endl<<std::endl<<"database read"<<std::endl;
    file1.close();
}

// METODI DI NODO

template <class T>
lista<T>::nodo::nodo(): dipendente(0), next(0) {}

template <class T>
lista<T>::nodo::~nodo(){
    delete dipendente;
    if(next!=0)
        delete next;
}

template <class T>
lista<T>::nodo::nodo(T* p, nodo* n) :dipendente(p), next(n) {}

// METODI DI ITERATORE

template <class T>
bool lista<T>::iteratore::operator==(iteratore it) const {
    return punt==it.punt;
}

template <class T>
bool lista<T>::iteratore::operator!=(iteratore it) const {
    return punt!=it.punt;
}

template <class T>
typename lista<T>::iteratore & lista<T>::iteratore::operator++() {
    if(punt)
        punt=punt->next; //qui fa sideeff. quindi non posso marchiare const
    return *this;
}

template <class T>
typename lista<T>::iteratore lista<T>::iteratore::operator++(int) {
    iteratore x=*this;
    if(punt)
        punt=punt->next;
    return x;
}

template <class T>
typename lista<T>::iteratore lista<T>::begin() const {
    iteratore aux;
    aux.punt=first;
    return aux;
}

template <class T>
typename lista<T>::iteratore lista<T>::end() const {
    iteratore aux;
    aux.punt=0;
    return aux;
}

template <class T>
T& lista<T>::operator[](lista<T>::iteratore it) const {
    return *((it.punt)->dipendente);
}

template <class T>
T* lista<T>::iteratore::operator->() const{
    return punt->dipendente;
}


#endif // LISTAH
