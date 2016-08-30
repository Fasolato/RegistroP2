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

#include"preside.h"

class PresideView : public QWidget
{
    Q_OBJECT

public:
    explicit PresideView(preside* user_preside, QWidget *parent = 0);
    ~PresideView();

signals:
    void disconnectUserView();

public slots:

private:
    QLabel* label;
    QPushButton* exit;
    QVBoxLayout* layout;
};

#endif // PRESIDEVIEW_H
