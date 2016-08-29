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

#include"preside.h"

class PresideView : public QWidget
{
    Q_OBJECT

public:
    explicit PresideView(preside* user_preside, QWidget *parent = 0);

signals:

public slots:

private:
};

#endif // PRESIDEVIEW_H
