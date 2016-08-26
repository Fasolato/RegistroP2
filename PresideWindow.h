#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>


class PresideWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PresideWindow(QString user, QWidget *parent = 0);

signals:

public slots:

private:
    QLabel* label;
    QPushButton* button;
    QVBoxLayout* layout;
};

#endif // MAINWINDOW_H
