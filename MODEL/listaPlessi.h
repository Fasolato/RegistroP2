#ifndef LISTAPLESSI_H
#define LISTAPLESSI_H

#include<iostream>
#include<typeinfo>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>

#include"plesso.h"


class ListaPlessi{
    static QString filename2;
    friend class iteratorePlessi;

private:
    class nodo {
    public:
        nodo();
        ~nodo();
        nodo(plesso*, nodo*);
        plesso* scuola;
        nodo* next;
    };

    nodo* first;

public:
    class iteratorePlessi {
            friend class ListaPlessi;
        private:
            ListaPlessi::nodo* punt;
        public:
            bool operator==(iteratorePlessi) const;
            bool operator!=(iteratorePlessi) const;
            iteratorePlessi& operator++(); // operator++ prefisso
            iteratorePlessi operator++(int); // operator++ postfisso
        };

        iteratorePlessi begin() const;
        iteratorePlessi end() const;
        plesso& operator[](iteratorePlessi) const;

        void Load();
        void Close();

        //per Test
        void stampa(const plesso* p) const;

        ListaPlessi();
        ~ListaPlessi();
        bool Vuota() const;
        bool matchMembro(plesso* p);
        void modificaMembro(plesso*, plesso*);
        void aggiungiMembro(plesso*);
        void togliMembro(plesso*);
        plesso* ricercaPlesso(QString p);
};

#endif // LISTAPLESSI_H
