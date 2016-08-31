#ifndef INSERTDOCENTE_H
#define INSERTDOCENTE_H

#include <QWidget>
#include<QGroupBox>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLineEdit>
#include<QMessageBox>
#include<QComboBox>

class insertDocente : public QFrame
{
    Q_OBJECT
public:
    explicit insertDocente(QWidget *parent = 0);
    ~insertDocente();

signals:

    void inserisciDocente(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_oraria);

private slots:
    void insertUser();

private:
    void clearTextEdit();

    QLabel* title;
    QLabel* nome;
    QLineEdit* text_Nome;
    QLabel* cognome;
    QLineEdit* text_Cognome;
    QLabel* Orario;
    QLabel* lunedì;
    QLineEdit* text_Lun;
    QLabel* martedì;
    QLineEdit* text_Mar;
    QLabel* mercoledì;
    QLineEdit* text_Mer;
    QLabel* giovedì;
    QLineEdit* text_Gio;
    QLabel* venerdì;
    QLineEdit* text_Ven;
    QLabel* sabato;
    QLineEdit* text_Sab;
    QLabel* username;
    QLineEdit* text_User;
    QLabel* password;
    QLineEdit* text_Pass;
    QLabel* scuola;
    QLineEdit* text_Scuola;
    QLabel* p_oraria;
    QLineEdit* text_P_oraria;

    QPushButton* insert;

    QGridLayout* layout;
};

#endif // INSERTDOCENTE_H
