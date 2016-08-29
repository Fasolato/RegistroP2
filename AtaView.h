#ifndef ATAVIEW_H
#define ATAVIEW_H

#include<QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>

#include"ATA.h"

class AtaView : public QWidget
{
    Q_OBJECT

public:
    explicit AtaView(ata* user_ata, QWidget *parent = 0);

signals:

public slots:

private:
};

#endif // ATAVIEW_H
