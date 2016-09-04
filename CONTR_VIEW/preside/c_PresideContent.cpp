#include"c_PresideContent.h"

C_PresideContent::C_PresideContent(ListaPlessi* lp, preside* pres, lista<personale>* li, QObject *parent, PresideContent* view_) :
    QObject(parent), model(pres), view(view_), list(li), p(lp)
{
    connect(view,SIGNAL(inserisciPlesso(QString, QString, QString, QString, int, double)),this,SLOT(inserisciPlesso(QString, QString, QString, QString, int, double)));
    connect(view,SIGNAL(inserisciAta(QString, QString, int, int, int, int, int, int, QString, QString, QString, double)),this,SLOT(inserisciAta(QString, QString, int, int, int, int, int, int, QString, QString, QString, double)));
    connect(view,SIGNAL(inserisciDocente(QString, QString, int, int, int, int, int, int, QString, QString, QString, double)),this,SLOT(inserisciDocente(QString, QString, int, int, int, int, int, int, QString, QString, QString, double)));
    connect(view,SIGNAL(inserisciPreside(QString, QString, int, int, int, int, int, int, QString, QString, QString, double, double, int, QString)),this,SLOT(inserisciPreside(QString, QString, int, int, int, int, int, int, QString, QString, QString, double, double, int, QString)));
    connect(view,SIGNAL(removeUserClicked(QString)),this,SLOT(removeUser(QString)));
}

void C_PresideContent::inserisciPlesso(const QString& nome, const QString &sede, const QString &via, const QString &telefono, int p_ata, double m_q){
    if(!(p->ricercaPlesso(nome))){
        plesso* pl= new plesso(nome, sede, via, telefono, p_ata, m_q);
        p->aggiungiMembro(pl);
        p->Close();
        view->buildTable();
        std::cout<<"Inserisco: "<<nome.toStdString()<<" "<<std::endl;
        std::cout<<"arrivatiinsPlesso"<<std::endl;
    }
    else{
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Inserimento Plesso");
        warning.setText("Impossibile inserire il nuovo plesso");
        warning.setInformativeText("Il plesso è già stato inserito.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
}

void C_PresideContent::inserisciAta(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_mq){
    if(!(list->trova(n_u))){
        plesso* pl=p->ricercaPlesso(scuola);
        if(pl){
            ata* utente= new ata(nome, cognome, lun, mar, mer, gio, ven, sab, n_u, pass, pl, p_mq);
            list->aggiungiMembro(utente);
            list->Close();
            view->buildTable();
            std::cout<<"Inserisco: "<<n_u.toStdString()<<" "<<std::endl;
        }
        else{

            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Inserimento Ata");
            warning.setText("Impossibile inserire il nuovo utente");
            warning.setInformativeText("Il plesso di afferenza selezionato non esiste.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
    }
    else{

        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Inserimento Ata");
        warning.setText("Impossibile inserire il nuovo utente");
        warning.setInformativeText("L'username è già in uso.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
}

void C_PresideContent::inserisciDocente(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_ora){
    if(!(list->trova(n_u))){
        plesso* pl=p->ricercaPlesso(scuola);
        if(pl){
            docente* utente= new docente(nome, cognome, lun, mar, mer, gio, ven, sab, n_u, pass, pl, p_ora);
            list->aggiungiMembro(utente);
            list->Close();
            view->buildTable();
            std::cout<<"Inserisco: "<<n_u.toStdString()<<" "<<std::endl;
        }
        else{

            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Inserimento Docente");
            warning.setText("Impossibile inserire il nuovo utente");
            warning.setInformativeText("Il plesso di afferenza selezionato non esiste.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
    }
    else{

        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Inserimento Docente");
        warning.setText("Impossibile inserire il nuovo utente");
        warning.setInformativeText("L'username è già in uso.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
}

void C_PresideContent::inserisciPreside(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_ora, double p_stra, int ore_s, const QString& num){
    if(!(list->trova(n_u))){
        plesso* pl=p->ricercaPlesso(scuola);
        if(pl){
            preside* utente= new preside(nome, cognome, lun, mar, mer, gio, ven, sab, n_u, pass, pl, p_ora, p_stra, ore_s, num);
            list->aggiungiMembro(utente);
            list->Close();
            view->buildTable();
            std::cout<<"Inserisco: "<<n_u.toStdString()<<" "<<std::endl;
        }
        else{

            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Inserimento Preside");
            warning.setText("Impossibile inserire il nuovo utente");
            warning.setInformativeText("Il plesso di afferenza selezionato non esiste.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
    }
    else{

        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Inserimento Preside");
        warning.setText("Impossibile inserire il nuovo utente");
        warning.setInformativeText("L'username è già in uso.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
}

void C_PresideContent::removeUser(const QString &user){
    personale* p=list->trova(user);
    if(p){
        list->togliMembro(p);
        list->Close();
        view->buildTable();
    }
    else{
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Rimuovi utente");
        warning.setText("Impossibile eliminare l'utente");
        warning.setInformativeText("L'utente selezionato non esite.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
}

    C_PresideContent::~C_PresideContent(){
        std::cout<<"arrivati~c_presidecontent"<<std::endl;
    model=0;
    view=0;
}
