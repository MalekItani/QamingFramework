#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class loginWindow : public QWidget{
    Q_OBJECT
public:
    explicit loginWindow(QWidget *parent = nullptr);

private:
    QGridLayout* gridLayout;

    QLabel* usernameLabel;
    QLabel* passwordLabel;

    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;

    QPushButton* submitButton;

    QMessageBox* errorBox;

public slots:
    void attempt_login();

};

#endif // LOGINWINDOW_H
