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
#include<QInputDialog>

#include"../../MODEL/lista.h"

#include"inserisci_plesso/insertPlesso.h"
#include"inserisci_ata/insertAta.h"
#include"inserisci_docente/insertDocente.h"
#include"inserisci_preside/insertPreside.h"

class PresideContent : public QWidget
{
   Q_OBJECT
public:
   explicit PresideContent(lista<personale>* li, QWidget *parent = 0, preside* model_ =0);
   ~PresideContent();

   void buildTable();

signals:
   void inserisciPlesso(const QString& nome, const QString &sede, const QString &via, const QString &telefono, int p_ata, double m_q);
   void inserisciAta(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_mq);
   void inserisciDocente(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_ora);
   void inserisciPreside(const QString& nome, const QString& cognome, int lun, int mar, int mer, int gio, int ven, int sab, const QString& n_u, const QString& pass, const QString& scuola, double p_ora, double p_stra, int ore_s, const QString& num);
   void removeUserClicked(const QString& user);

private slots:
   void buildPlessoView();
   void buildAtaView();
   void buildDocenteView();
   void buildPresideView();

   void enableButtons();

   void removeUser();
   void setSelectedUser(int r);

private:

   void removeInsWidget();
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

   QPushButton* i_plesso;
   QPushButton* i_ata;
   QPushButton* i_docente;
   QPushButton* i_preside;

   insertPlesso* insPlessoView;
   insertAta* insAtaView;
   insertDocente* insDocenteView;
   insertPreside* insPresideView;

   QVBoxLayout* layout_Buttons;
   QVBoxLayout* layout_Table;

   QHBoxLayout* layout;
};

#endif // PRESIDECONTENT_H
