#include"listaPlessi.h"

QString ListaPlessi::filename2="../../../../RegistroP2/DATABASE/plessoDB.xml";

// METODI DI LISTAPLESSI

ListaPlessi::ListaPlessi(): first(0) {
    Load();
}

ListaPlessi::~ListaPlessi(){
    Close();
    if(first)
        delete first;
}

bool ListaPlessi::Vuota() const {
    return first==0;
}

void ListaPlessi::modificaMembro(plesso* a, plesso* b){
    nodo* x= first;
    while(x && !(x->scuola==a)){
        x= x->next;
    }
    if(x) { //se siamo usciti dal ciclo while a causa della seconda condizione
        x->scuola=b;
    }
}

bool ListaPlessi::matchMembro(plesso* p){
    nodo* x= first;
    while(x && !(x->scuola==p)){
        x= x->next;
    }
    if(x) { //se siamo usciti dal ciclo while a causa della seconda condizione
        return true;
    }
    return false;
}

void ListaPlessi::aggiungiMembro(plesso* p){
    if(!matchMembro(p)){
        first= new nodo(p, first);
    }
}

void ListaPlessi::togliMembro(plesso* p){
    nodo* a= first, *prec= 0;
    while(a && !(a->scuola==p)){
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

plesso* ListaPlessi::ricercaPlesso(QString p){
    for(ListaPlessi::iteratorePlessi it=ListaPlessi::begin(); it!=ListaPlessi::end(); ++it)
        if(((it.punt)->scuola)->getNome()==p)
            return (it.punt)->scuola;
    return 0;
}

ListaPlessi::iteratorePlessi ListaPlessi::begin() const {
    iteratorePlessi aux;
    aux.punt=first;
    return aux;
}

ListaPlessi::iteratorePlessi ListaPlessi::end() const {
    iteratorePlessi aux;
    aux.punt=0;
    return aux;
}

plesso& ListaPlessi::operator[](ListaPlessi::iteratorePlessi it) const {
    return *((it.punt)->scuola);
}

// METODI DI NODO

ListaPlessi::nodo::nodo(): scuola(0), next(0) {}

ListaPlessi::nodo::~nodo(){
    delete scuola;
    if(next!=0)
        delete next;
}

ListaPlessi::nodo::nodo(plesso* p, nodo* n) :scuola(p), next(n) {}

// METODI DI iteratorePlessi

bool ListaPlessi::iteratorePlessi::operator==(iteratorePlessi it) const {
    return punt==it.punt;
}

bool ListaPlessi::iteratorePlessi::operator!=(iteratorePlessi it) const {
    return punt!=it.punt;
}

ListaPlessi::iteratorePlessi & ListaPlessi::iteratorePlessi::operator++() {
    if(punt)
        punt=punt->next; //qui fa sideeff. quindi non posso marchiare const
    return *this;
}

ListaPlessi::iteratorePlessi ListaPlessi::iteratorePlessi::operator++(int) {
    iteratorePlessi x=*this;
    if(punt)
        punt=punt->next;
    return x;
}

plesso* ListaPlessi::iteratorePlessi::operator->() const{
    return punt->scuola;
}


void ListaPlessi::Close(){

     QFile file2(filename2);
     file2.open(QIODevice::WriteOnly);

     QXmlStreamWriter xmlWriter(&file2);
     xmlWriter.setAutoFormatting(true);
     xmlWriter.writeStartDocument();
     xmlWriter.writeStartElement("database");

     ListaPlessi::iteratorePlessi it =ListaPlessi::begin();
     for(; it!=ListaPlessi::end(); ++it){

     xmlWriter.writeStartElement("plesso");

     xmlWriter.writeTextElement("nome", (it->getNome()));

     xmlWriter.writeTextElement("sede", (it->getSede()));

     xmlWriter.writeTextElement("via", (it->getVia()));

     xmlWriter.writeTextElement("telefono", (it->getTelefono()));

     xmlWriter.writeTextElement("pers_ata", QString::number((it->getAta())));

     xmlWriter.writeTextElement("metri_quadri", QString::number((it->getMq())));


     xmlWriter.writeEndElement();//plesso

     }

     xmlWriter.writeEndElement(); // database

     xmlWriter.writeEndDocument();

     file2.close();

     std::cout<<std::endl<<"plessoDB written"<<std::endl;
}

void ListaPlessi::Load(){
    //variabili temporanee
    QString nome="Unknown";
    QString sede="Unknown";
    QString via="Unknown";
    QString telefono="Unknown";
    int ata=0;
    double mq=0;

    QFile file2(filename2);
    if (!file2.open(QFile::ReadOnly | QFile::Text)){
        std::cout << "Error: Cannot read file"<< std::endl;
    }
    QXmlStreamReader xmlReader(&file2);
    xmlReader.readNext();

    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())  //legge apertura Tag
        {

            if(xmlReader.name()=="database" || xmlReader.name()=="plesso")
            {
               xmlReader.readNext();
            }
            else if(xmlReader.name()=="nome"){
                nome=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="sede")
            {
                sede=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="via")
            {
                via=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="telefono")
            {
                telefono=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="pers_ata")
            {
                ata=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="metri_quadri")
            {
                mq=xmlReader.readElementText().toDouble();
            }
            else std::cout<<"we got a problem "; //FLAG di allarme;
        }
        else
        {
            if(xmlReader.isEndElement() && xmlReader.name()=="plesso"){ //leggo </utente> //costruisco utente

                plesso* pl= new plesso(nome, sede, via, telefono, ata, mq);
                ListaPlessi::nodo* point=first;
                if(point){
                    while(point->next!=0)
                        point=point->next;
                    point->next= new nodo(pl, 0);
                }
                else
                    first= new nodo(pl, 0);

                nome="Unknown";
                sede="Unknown";
                via="Unknown";
                telefono="Unknown";
                ata=0;
                mq=0;

                xmlReader.readNext();
            }
            else //leggo vuoto o EndElement!="utente"
                xmlReader.readNext();
        }
   }
    std::cout<<std::endl<<std::endl<<"database read"<<std::endl;
    file2.close();
}
