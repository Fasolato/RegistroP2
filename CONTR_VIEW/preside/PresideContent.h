#ifndef PRESIDECONTENT_H
#define PRESIDECONTENT_H

#include <QWidget>
#include<QTableWidget>
#include<QPushButton>
#include<QTextEdit>
#include<QLabel>
#include<QTabWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QRadioButton>
#include<QLineEdit>
#include <QHeaderView>
#include<QTableWidget>
#include<QMessageBox>
#include<QItemSelectionModel>
#include<QHeaderView>

#include"../../MODEL/lista.h"

class PresideContent : public QWidget
{
   Q_OBJECT
public:
   explicit PresideContent(lista<personale>* li, QWidget *parent = 0, preside* model_ =0);
   ~PresideContent();

   void buildTable();

signals:
   void insertPlesso(const QString& nome, const QString &sede, const QString &via, const QString &telefono, int p_ata, double m_q);
   void insertAta(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_mq);
   void insertDocente(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_ora);
   void insertPreside(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_ora, int ore_s, const QString& num);
   void removeUserClicked(const QString& user);

private slots:
   void enableButtons();

   void removeUser();
   void setSelectedUser(int r);

private:

   void refreshTable();
   void disableButtons();
   void updateLabel();

   lista<personale>* pli;

   preside* model;

   QTableWidget* table;
   QString selected_user;
   QLabel* selected_text_label;
   QLabel* selected_user_label;
   QPushButton* remove_user;

   QPushButton* show_info;
   //insertView* insert_User;

   QVBoxLayout* layout_Buttons;
   QVBoxLayout* layout_Table;

   QHBoxLayout* layout;
};

#endif // PRESIDECONTENT_H
