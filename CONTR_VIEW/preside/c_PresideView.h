#ifndef C_PRESIDEVIEW_H
#define C_PRESIDEVIEW_H

#include <QObject>

#include"PresideView.h"
#include"c_PresideContent.h"


class C_PresideView : public QObject
{
    Q_OBJECT
public:
    explicit C_PresideView(ListaPlessi* lp, lista<personale>* lis, preside* user, QObject *parent = 0, PresideView* p_view =0);
    ~C_PresideView();

signals:

public slots:
    void quit();

private:
    preside* model;
    PresideView* view;

    lista<personale>* li;
    ListaPlessi* p;
    C_PresideContent* c_presidecontent;

};

#endif // C_PRESIDEVIEW_H
