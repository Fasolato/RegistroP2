#ifndef C_DOCENTEVIEW_H
#define C_DOCENTEVIEW_H

#include <QObject>

#include"DocenteView.h"


class C_DocenteView : public QObject
{
    Q_OBJECT
public:
    explicit C_DocenteView(QObject *parent = 0, docente* user =0, DocenteView* d_view =0);
    ~C_DocenteView();

signals:

public slots:

private:
    docente* model;
    DocenteView* view;

};

#endif // C_DOCENTEVIEW_H
