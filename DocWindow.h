#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#include<QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>


class DocWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DocWindow(QString user, QWidget *parent = 0);

signals:

public slots:

private:
    QLabel* label;
    QPushButton* button;
    QVBoxLayout* layout;
};

#endif // DOCWINDOW_H
