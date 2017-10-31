#ifndef INSERTATA_H
#define INSERTATA_H

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
#include<QScrollArea>

class insertAta : public QFrame
{
    Q_OBJECT
public:
    explicit insertAta(QWidget *parent = 0);
    ~insertAta();

signals:

    void inserisciAta(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_mq);

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
    QLabel* lunedi;
    QLineEdit* text_Lun;
    QLabel* martedi;
    QLineEdit* text_Mar;
    QLabel* mercoledi;
    QLineEdit* text_Mer;
    QLabel* giovedi;
    QLineEdit* text_Gio;
    QLabel* venerdi;
    QLineEdit* text_Ven;
    QLabel* sabato;
    QLineEdit* text_Sab;
    QLabel* username;
    QLineEdit* text_User;
    QLabel* password;
    QLineEdit* text_Pass;
    QLabel* scuola;
    QLineEdit* text_Scuola;
    QLabel* p_mq;
    QLineEdit* text_P_mq;

    QPushButton* insert;

    QGridLayout* layout;
};

#endif // INSERTATA_H
