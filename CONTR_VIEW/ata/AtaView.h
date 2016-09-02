#ifndef ATAVIEW_H
#define ATAVIEW_H

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

#include"../../MODEL/ATA.h"

class AtaView : public QWidget
{
    Q_OBJECT

public:
    explicit AtaView(ata* user_ata, QWidget *parent = 0);
    ~AtaView();

signals:
    void disconnectUserView();

public slots:

private:
    QLabel* label;
    QPushButton* exit;

    QLabel* title1;
    QLabel* nome;
    QLabel* text_Nome;
    QLabel* cognome;
    QLabel* text_Cognome;
    QLabel* Orario;
    QLabel* lunedì;
    QLabel* text_Lun;
    QLabel* martedì;
    QLabel* text_Mar;
    QLabel* mercoledì;
    QLabel* text_Mer;
    QLabel* giovedì;
    QLabel* text_Gio;
    QLabel* venerdì;
    QLabel* text_Ven;
    QLabel* sabato;
    QLabel* text_Sab;
    QLabel* username;
    QLabel* text_User;
    QLabel* password;
    QLabel* text_Pass;
    QLabel* scuola;
    QLabel* text_Scuola;
    QLabel* p_mq;
    QLabel* text_P_Mq;
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

#endif // ATAVIEW_H
