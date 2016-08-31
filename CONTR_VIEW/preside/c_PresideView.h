#ifndef C_PRESIDEVIEW_H
#define C_PRESIDEVIEW_H

#include <QObject>

#include"PresideView.h"


class C_PresideView : public QObject
{
    Q_OBJECT
public:
    explicit C_PresideView(QObject *parent = 0, preside* user =0, PresideView* p_view =0);
    ~C_PresideView();

signals:

public slots:

private:
    preside* model;
    PresideView* view;

};

#endif // C_PRESIDEVIEW_H
