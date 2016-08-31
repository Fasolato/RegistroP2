#ifndef C_PRESIDEVIEW_H
#define C_PRESIDEVIEW_H

#include <QObject>

#include"PresideView.h"
#include"c_PresideContent.h"


class C_PresideView : public QObject
{
    Q_OBJECT
public:
    explicit C_PresideView(lista<personale>* lis, preside* user, QObject *parent = 0, PresideView* p_view =0);
    ~C_PresideView();

signals:

public slots:

private:
    preside* model;
    PresideView* view;

    lista<personale>* li;
    C_PresideContent* c_presidecontent;

};

#endif // C_PRESIDEVIEW_H
