#ifndef C_STARTVIEW_H
#define C_STARTVIEW_H

#include <QObject>

#include"startview.h"
#include"preside/c_PresideView.h"

class StartView;

class C_StartView : public QObject
{
    Q_OBJECT
public:
    explicit C_StartView(ListaPlessi* lp, lista<personale>* pli, StartView* pview =0, QObject *parent =0);

signals:

public slots:
    void createC_PresideView();


    void createAtaModel(personale* pers);
    void createDocenteModel(personale* pers);
    void createPresideModel(personale* pers);

    void deleteControllers();
    void deleteModel();

private:
    ata* pers_ata;
    docente* pers_docente;
    preside* pers_preside;

    lista<personale>* li;
    ListaPlessi* p;

    StartView* view;

    C_PresideView* c_preside;

};

#endif // C_STARTVIEW_H
