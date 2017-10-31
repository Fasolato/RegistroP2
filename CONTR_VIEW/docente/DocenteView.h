#ifndef DOCENTEVIEW_H
#define DOCENTEVIEW_H

#include <QWidget>
#include<QTableWidget>
#include<QPushButton>
#include<QTextEdit>
#include<QLabel>
#include<QTabWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QRadioButton>
#include <QHeaderView>
#include<QTableWidget>
#include<QMessageBox>
#include<QItemSelectionModel>
#include<QHeaderView>
#include<QApplication>

#include"../../MODEL/docente.h"

class DocenteView : public QWidget
{
    Q_OBJECT

public:
    explicit DocenteView(docente* user_docente, QWidget *parent = 0);
    ~DocenteView();

signals:
    void disconnectUserView();

public slots:

private slots:
    void quit();

private:
    QLabel* label;
    QPushButton* exit;

    QLabel* title1;
    QLabel* nome;
    QLabel* text_Nome;
    QLabel* cognome;
    QLabel* text_Cognome;
    QLabel* Orario;
    QLabel* lunedi;
    QLabel* text_Lun;
    QLabel* martedi;
    QLabel* text_Mar;
    QLabel* mercoledi;
    QLabel* text_Mer;
    QLabel* giovedi;
    QLabel* text_Gio;
    QLabel* venerdi;
    QLabel* text_Ven;
    QLabel* sabato;
    QLabel* text_Sab;
    QLabel* username;
    QLabel* text_User;
    QLabel* password;
    QLabel* text_Pass;
    QLabel* scuola;
    QLabel* text_Scuola;
    QLabel* p_oraria;
    QLabel* text_P_oraria;
    QLabel* stipendio;
    QLabel* text_Stip;

    QLabel* title2;
    QLabel* nomeS;
    QLabel* text_nomeS;
    QLabel* sede;
    QLabel* text_Sede;
    QLabel* via;
    QLabel* text_Via;
    QLabel* tel;
    QLabel* text_Tel;
    QLabel* pers_ata;
    QLabel* text_P_ata;
    QLabel* m_q;
    QLabel* text_Mq;

    QGridLayout* layout1;
    QGridLayout* layout2;
    QHBoxLayout* layout;
    QVBoxLayout* layoutFinal;
};

#endif // DOCENTEVIEW_H
