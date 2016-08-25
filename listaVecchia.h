#ifndef LISTAH
#define LISTAH


#include<QString>
#include"personale.h"

using namespace std;

template <class T>
class lista
{
    friend class orarioGiornaliero;//orarioGiornaliero è un template o no?
private:

    class orarioGiornaliero;

    class smartp {
    public:
        orarioGiornaliero* punt; //unico campo dati di smartp
        smartp(orarioGiornaliero* p=0); //COSTRUTTORE
        //agisce da convertitore implicito da orarioGiornaliero* a smartp
        //e funziona anche da costruttore senza argomenti
        smartp(const smartp &); //COSTR. COPIA
        ~smartp(); //DISTRUTTORE
        smartp & operator=(const smartp &); //ASSEGNAZIONE
        orarioGiornaliero* operator->() const; //ACCESSO A MEMBRO
    };

    class orarioGiornaliero {
    public:
        T ore;
        smartp* next;
        int riferimenti;
        orarioGiornaliero();
        orarioGiornaliero(const T &, const smartp&);
    };
    orarioGiornaliero* first;
public:
    lista();
    lista(T[6]);
    ~lista();//distruttore da utilizzare solo quando viene deallocato un oggetto di
    //tipo (che deriva da) personale: distrugge tutta la lista
};

// METODI DI LISTA <T>

template <class T>
lista<T>::lista() {
    orarioGiornaliero* attuale= first;
    for(i=0; i<7; ++i){
        orarioGiornaliero* successivo;
        *attuale=orarioGiornaliero("non inserito", successivo);
        attuale=successivo;
    }
    return first;
}

template <class T>
lista<T>::lista(T[6]) {
    orarioGiornaliero* attuale= first;
    for(i=0; i<7; ++i){
        orarioGiornaliero* successivo;
        *attuale=orarioGiornaliero(T[i], successivo);
        attuale=successivo;
    }
    return first;
}

template <class T>
lista<T>::~lista(){
    orarioGiornaliero* attuale= first;
    for(i=0; i<7; ++i){
        orarioGiornaliero* successivo;
        *attuale=orarioGiornaliero(T[i], successivo);
        attuale=successivo;
    }
    return first;
}

// METODI DI SMARTP

template <class T> //COSTRUTTORE
lista<T>::smartp::smartp(orarioGiornaliero* p=0): punt(p){
    if(punt)
        punt->riferimenti++;
}

template <class T> //COSTR. COPIA
lista<T>::smartp::smartp(const orarioGiornaliero & s): punt(s.punt){
    if(punt)
        punt->riferimenti++;
}

template <class T>// DISTRUTTORE
lista<T>::smartp::~smartp(){
    if(punt) {
        punt->riferimenti--;
        if(punt->riferimenti == 0)
            delete punt;
        //è la delete standard di OrarioGiornaliero, che elimina la lista ricors.
    }
}

template <class T> //ASSEGNAZIONE
lista<T>::smartp& lista<T>::smartp::operator=(const smartp & s){
    if(this!=&s){
        orarioGiornaliero*t= punt;
        punt=s.punt;
        if(punt)
            punt->riferimenti++;
        if(t){
            t->riferimenti--;
            if(t->riferimenti == 0)
                delete t;
        }
    }
    return *this;
}

template <class T> //OPERATORE DI ACCESSO A MEMBRO
lista<T>::orarioGiornaliero* lista<T>::smartp::operator->() const {
    return punt;
}

// METODI DI ORARIOGIORNALIERO

template <class T>
lista<T>::orarioGiornaliero::orarioGiornaliero(): ore("non specificato"), riferimenti(0){}
//invocazione di next implicita

template <class T>
lista<T>::orarioGiornaliero::orarioGiornaliero(const T& o, const smartp& p) :ore(o), next(p), riferimenti(0){}
//il costruttore di copia di next di tipo smartp aumenta il campo riferimenti

#endif // LISTAH
