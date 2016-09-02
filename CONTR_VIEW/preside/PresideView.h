#ifndef PRESIDEVIEW_H
#define PRESIDEVIEW_H

#include<QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>
#include<QApplication>

#include"../../MODEL/preside.h"
#include"PresideContent.h"

class PresideView : public QWidget
{
    Q_OBJECT

public:
    explicit PresideView(lista<personale>* li, preside* user_preside, QWidget *parent = 0);
    ~PresideView();

    PresideContent* getPresideContent();

signals:
    void disconnectUserView();
    void quit();

public slots:

private slots:

private:
    QLabel* label;
    QPushButton* exit;
    QVBoxLayout* layout;

    lista<personale>* pli;

    PresideContent* content;
};

#endif // PRESIDEVIEW_H
