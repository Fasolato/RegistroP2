#ifndef DOCENTEVIEW_H
#define DOCENTEVIEW_H

#include<QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>

#include"docente.h"

class DocenteView : public QWidget
{
    Q_OBJECT

public:
    explicit DocenteView(docente* user_docente, QWidget *parent = 0);

signals:

public slots:

private:
};

#endif // DOCENTEVIEW_H
