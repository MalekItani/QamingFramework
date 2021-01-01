#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include<accounts/user.h>


/**
* \file loginwindow.h
* \brief Header file of the window that users will use to login to their accounts.
* \author Malek Itani
*/

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

    User* userPtr;

public slots:
    /**
    * \brief Tries to perform a login given the entered credentials.
    */
    void attempt_login();

signals:
    /**
    * \brief Returns a pointer to the user object that just logged in.
    */
    void userApproved(User*);

};

#endif // LOGINWINDOW_H
