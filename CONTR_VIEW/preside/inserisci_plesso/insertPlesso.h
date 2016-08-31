#ifndef INSERTPLESSO_H
#define INSERTPLESSO_H

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

class insertPlesso : public QFrame
{
    Q_OBJECT
public:
    explicit insertPlesso(QWidget *parent = 0);
    ~insertPlesso();

signals:

    void inserisciPlesso(const QString& nome, const QString &sede, const QString &via, const QString &telefono, int ata, double mq);

private slots:
    void insertUser();

private:
    void clearTextEdit();

    QLabel* title;
    QLabel* nome;
    QLineEdit* text_Nome;
    QLabel* sede;
    QLineEdit* text_Sede;
    QLabel* via;
    QLineEdit* text_Via;
    QLabel* tel;
    QLineEdit* text_Tel;
    QLabel* p_ata;
    QLineEdit* text_P_Ata;
    QLabel* m_q;
    QLineEdit* text_M_q;

    QPushButton* insert;

    QGridLayout* layout;
};

#endif // INSERTPLESSO_H
