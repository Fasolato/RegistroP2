#ifndef ATAWINDOW_H
#define ATAWINDOW_H

#include<QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>


class AtaWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AtaWindow(QString user, QWidget *parent = 0);

signals:

public slots:

private:
    QLabel* label;
    QPushButton* button;
    QVBoxLayout* layout;
};

#endif // MAINWINDOW_H
