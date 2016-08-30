#ifndef C_ATAVIEW_H
#define C_ATAVIEW_H

#include <QObject>

#include"AtaView.h"


class C_AtaView : public QObject
{
    Q_OBJECT
public:
    explicit C_AtaView(QObject *parent = 0, ata* user =0, AtaView* a_view =0);
    ~C_AtaView();

signals:

public slots:

private:
    ata* model;
    AtaView* view;

};

#endif // C_ATAVIEW_H
