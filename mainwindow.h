#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<iostream>

#include<QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>

#include"lista.h"

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

#endif // MAINWINDOW_H
