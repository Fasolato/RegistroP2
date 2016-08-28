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

class MainWindow : public QFrame
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:
    void setLogin();
    void getLogin();
    void selectText();

private:
    QLabel* label;
    QLineEdit* tUser;
    QLineEdit* tPass;
    QPushButton* button;
    QVBoxLayout* layout;
};


class StartView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartView(QGroupBox *parent = 0);

    ClientView* getClientView();
    AdminView* getAdminView();

    void setAdminModel(const Admin* model_);
    void setClientModel(const Client* model_);
    void noMatchUser();

signals:
    void createC_ClientView();
    void createC_AdminView();
    void deleteControllers();

    void createClientModel(const QString&);
    void createAdminModel();
    void deleteModel();

private slots:
    void createAdmin();
    void createClient(const QString& user);
    void backInTime();

private:
    void centerWidget();
    void createMain();

    MainView* main_view;
    ClientView* client_view;
    AdminView* admin_view;

    const Client* client_model; //puntatori read-only
    const Admin* admin_model;
};

#endif // STARTVIEW_H
