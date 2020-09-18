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
    User user;
    int code = user.fromJSON(usernameLineEdit->text(), QString::fromStdString(Utils::HashPbdkf1(passwordLineEdit->text().toStdString())) );
    switch (code){
        case 1:
            errorBox->setWindowTitle("Login Failed");
            errorBox->setText("No account with this username was found.");
            errorBox->exec();
            return;
        case 2:
            errorBox->setWindowTitle("Login Failed");
            errorBox->setText("Incorrect password.");
            errorBox->exec();
            return;
    }
    errorBox->setWindowTitle("Login Successful");

    if(user.getDateOfBirth() == QDate::currentDate()){
        errorBox->setText("Welcome back, " + user.getFirstName() + " " + user.getLastName() + "!");
    }else{
        errorBox->setText("Happy Birthday, " + user.getFirstName() + " " + user.getLastName() + "!");
    }
    errorBox->exec();
    close();
}
