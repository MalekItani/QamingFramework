#include "loginwindow.h"
#include <accounts/user.h>
#include <Utils/Utils.h>


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

    errorBox = new QMessageBox();

    QObject::connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(attempt_login()));
}

void loginWindow::attempt_login(){
    userPtr = new User();
    int code = userPtr->fromJSON(usernameLineEdit->text(), QString::fromStdString(Utils::HashPbdkf1(passwordLineEdit->text().toStdString())) );
    switch (code){
        case 0:
            break;
        case 1:
            errorBox->setWindowTitle("Login Failed");
            errorBox->setText("No account with this username was found.");
            errorBox->exec();
            userPtr = NULL;
            return;
        case 2:
            errorBox->setWindowTitle("Login Failed");
            errorBox->setText("Incorrect password.");
            errorBox->exec();
            userPtr = NULL;
            return;
    }
    errorBox->setWindowTitle("Login Successful");
    errorBox->setText("Login Successful");
    errorBox->exec();
    emit userApproved(userPtr);
    close();
}
