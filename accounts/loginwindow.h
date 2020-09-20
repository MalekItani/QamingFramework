#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include<accounts/user.h>


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

    User* userPtr;

public slots:
    void attempt_login();

signals:
    void userApproved(User*);

};

#endif // LOGINWINDOW_H
