#include "loginwindow.h"
#include <accounts/user.h>
#include <Utils/Utils.h>

/**
* \file loginwindow.cpp
* \brief Implementation of the window that users will use to login to their accounts.
* \author Malek Itani
*/


loginWindow::loginWindow(QWidget *parent) : QWidget(parent){

    setWindowTitle("Login to an Existing Account");

    gridLayout = new QGridLayout();

    usernameLabel = new QLabel("Username");
    gridLayout->addWidget(usernameLabel, 0, 0);

    usernameLineEdit = new QLineEdit();
    gridLayout->addWidget(usernameLineEdit, 0, 1);

    passwordLabel = new QLabel("Password");
    gridLayout->addWidget(passwordLabel, 1, 0);

    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    gridLayout->addWidget(passwordLineEdit, 1, 1);

    submitButton = new QPushButton("Submit");
    gridLayout->addWidget(submitButton, 2, 0, 1, 2);

    setLayout(gridLayout);

    QObject::connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(attempt_login()));
}


/**
* \brief Tries to perform a login given the entered credentials.
* If the username is not found, or the passwords don't match, then a message box informs the user.
* Otherwise, the user is granted access and control is transferred back to the main window.
*/
void loginWindow::attempt_login(){
    userPtr = new User();
    int code = userPtr->fromJSON(usernameLineEdit->text(), Utils::HashPbdkf1(passwordLineEdit->text()) );
    switch (code){
    case User::USER_LOGIN_SUCCESS:
        Utils::Popup("Login Successful","Login Successful");
        break;
    case User::USER_INVALID_USERNAME:
        Utils::Popup("Login Failed","No account with this username was found.");
        return;
    case User::USER_INVALID_PASSWORD:
        Utils::Popup("Login Failed","Incorrect password.");
        userPtr = NULL;
        return;
    }
    emit userApproved(userPtr);
    close();
}
