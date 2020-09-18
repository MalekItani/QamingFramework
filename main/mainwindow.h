#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>

class mainWindow : public QWidget{
    Q_OBJECT
public:
    explicit mainWindow(QWidget *parent = nullptr);
private:
    QVBoxLayout* vLayout;

    QLabel* titleLabel;
    QLabel* creditsLabel;

    QPushButton* loginButton;
    QPushButton* registerButton;
    QPushButton* killCovidGameButton;
    QPushButton* reversiGameButton;

public slots:
    void openRegisterAccountForm();
    void openLoginForm();
};

#endif // MAINWINDOW_H
