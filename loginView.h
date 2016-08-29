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

#include<lista.h>

class LoginView : public QFrame
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = 0);

signals:
    void setPersonale(personale*);

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

#endif // LOGINVIEW_H
