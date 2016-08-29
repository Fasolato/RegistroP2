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
