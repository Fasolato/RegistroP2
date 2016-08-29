#ifndef STARTVIEW_H
#define STARTVIEW_H

#include<iostream>

#include<QWidget>
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

#include<lista.h>


class StartView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartView(QGroupBox *parent = 0);

    AtaView* getAtatView();
    DocenteView* getDocenteView();
    PresideView* getPresideView();

    void setAtaModel(const ata* p_ata);
    void setDocenteModel(const docente* p_docente);
    void setPresideModel(const preside* p_preside);

    void noMatchUser();

signals:
    void createC_AtaView();
    void createC_DocenteView();
    void createC_PresideView();

    void deleteControllers();

    void deleteModel();

private slots:
    void createAta(personale*);
    void createDocente(personale*);
    void createPreside(personale *);

    void backInTime();

private:
    void centerWidget();
    void createLogin();

    LoginView* login_view;
    AtaView* ata_view;
    DocenteView* docente_view;
    PresideView* preside_view;

    personale* pers;

    const ata* ata_model; //puntatori read-only
    const docente* docente_model;
    const preside* preside_model;
};

#endif // STARTVIEW_H
