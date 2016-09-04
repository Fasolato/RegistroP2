#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include<QWidget>
#include<QGroupBox>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>
#include<QApplication>
#include<QIcon>
#include<QDesktopWidget>

#include"../MODEL/lista.h"

class LoginView : public QFrame
{
    Q_OBJECT

public:
    explicit LoginView(lista<personale>* li,QWidget *parent = 0);

    void centerWidget();

signals:
    void setPersonale(personale*);
    void createAta(personale*);
    void createDocente(personale*);
    void createPreside(personale*);

public slots:
    void setLogin();
    void getLogin();
    void selectText();

private:
    lista<personale>* pli;

    QLabel* label;
    QLineEdit* tUser;
    QLineEdit* tPass;
    QPushButton* button;
    QPushButton* exit;
    QVBoxLayout* layout1;
    QHBoxLayout* layout2;
    QVBoxLayout* layoutFinal;
};

#endif // LOGINVIEW_H
