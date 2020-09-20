#include "registeraccountwindow.h"
#include <accounts/user.h>
#include <Utils/Utils.h>

#include <iostream>

registerAccountWindow::registerAccountWindow(QWidget *parent) : QWidget(parent){

    setWindowTitle("Create a New Account");

    gridLayout = new QGridLayout();

    firstNameLabel = new QLabel("First Name");
    gridLayout->addWidget(firstNameLabel, 0, 0);

    firstNameLineEdit = new QLineEdit();
    gridLayout->addWidget(firstNameLineEdit, 0, 1);

    lastNameLabel = new QLabel("Last Name");
    gridLayout->addWidget(lastNameLabel, 1, 0);

    lastNameLineEdit = new QLineEdit();
    gridLayout->addWidget(lastNameLineEdit, 1, 1);

    usernameLabel = new QLabel("Username");
    gridLayout->addWidget(usernameLabel, 2, 0);

    usernameLineEdit = new QLineEdit();
    gridLayout->addWidget(usernameLineEdit, 2, 1);

    passwordLabel = new QLabel("Password");
    gridLayout->addWidget(passwordLabel, 3, 0);

    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    gridLayout->addWidget(passwordLineEdit, 3, 1);

    retypePasswordLabel = new QLabel("Retype Password");
    gridLayout->addWidget(retypePasswordLabel, 4, 0);

    retypePasswordLineEdit = new QLineEdit();
    retypePasswordLineEdit->setEchoMode(QLineEdit::Password);
    gridLayout->addWidget(retypePasswordLineEdit, 4, 1);

    genderLabel = new QLabel("Gender");
    gridLayout->addWidget(genderLabel, 5, 0);

    genderButtonLayout = new QVBoxLayout();
    maleRadioButton = new QRadioButton("Male");
    genderButtonLayout->addWidget(maleRadioButton);

    femaleRadioButton = new QRadioButton("Female");
    genderButtonLayout->addWidget(femaleRadioButton);

    genderButtonGroupBox = new QGroupBox();
    genderButtonGroupBox->setLayout(genderButtonLayout);
    gridLayout->addWidget(genderButtonGroupBox, 5, 1);

    genderLabel = new QLabel("Date of Birth");
    gridLayout->addWidget(genderLabel, 6, 0);

    dateSelector = new QCalendarWidget();
    gridLayout->addWidget(dateSelector, 6, 1);

    submitButton = new QPushButton("Submit");
    gridLayout->addWidget(submitButton, 7, 0, 1, 2);

    setLayout(gridLayout);

    errorBox = new QMessageBox();

    QObject::connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(registerAccount()));
    QObject::connect(retypePasswordLineEdit, SIGNAL(textEdited(const QString&)), this, SLOT(checkMatchingPasswords(const QString&)));
    QObject::connect(passwordLineEdit, SIGNAL(textEdited(const QString&)), this, SLOT(checkMatchingPasswords(const QString&)));
}

void registerAccountWindow::registerAccount(){

    if(!Utils::IsValidName(firstNameLineEdit->text().toStdString())){
        errorBox->setWindowTitle("Invalid First Name");
        errorBox->setText("First name must be non-empty and should consist of latin characters only.");
        errorBox->exec();
        return;
    }

    if(!Utils::IsValidName(lastNameLineEdit->text().toStdString())){
        errorBox->setWindowTitle("Invalid Last Name");
        errorBox->setText("Last name must be non-empty and should consist of latin characters only.");
        errorBox->exec();
        return;
    }

    if(passwordLineEdit->text() != retypePasswordLineEdit->text()){
        errorBox->setWindowTitle("Passwords Mismatch");
        errorBox->setText("Passwords do not match.");
        errorBox->exec();
        return;
    }

    // TODO: Add sanity checks like gender selected, valid password, etc...
    if(!Utils::IsValidPassword(passwordLineEdit->text().toStdString())){
        errorBox->setWindowTitle("Invalid Password");
        errorBox->setText("A valid password must fulfill the following criteria:\n\n\
        - Password must be at least 8 characters long.\n\
        - Password must contain at least one lowercase and one\n\
          uppercase character.\n\
        - Password must contain one digit [0-9].");
        errorBox->exec();
        return;
    }

    int gender = 0;
    if(maleRadioButton->isChecked()) gender = 1;
    if(femaleRadioButton->isChecked()) gender = 2;

    if(!gender){
        errorBox->setWindowTitle("Please Select a Gender");
        errorBox->setText("You have not selected a gender.");
        errorBox->exec();
        return;
    }

    userPtr = new User();
    userPtr->setFirstName(firstNameLineEdit->text());
    userPtr->setLastName(lastNameLineEdit->text());
    userPtr->setUsername(usernameLineEdit->text());
    userPtr->setPassword(QString::fromStdString(
                         Utils::HashPbdkf1(passwordLineEdit->text().toStdString())));
    userPtr->setProfilePicturePath("media/pp/default_male.png");
    userPtr->setGender(gender);
    userPtr->setDateOfBirth(dateSelector->selectedDate());

    int code = userPtr->toJSON();
    switch(code){
        case 1:
            std::cerr << "ERROR: Could not open JSON for write" << std::endl; // TODO: This is not appropriate
            userPtr = NULL;
            return;
    }
    emit userApproved(userPtr);
    close();
}

void registerAccountWindow::checkMatchingPasswords(const QString&){
    if(passwordLineEdit->text() == retypePasswordLineEdit->text()){
        QPalette palette;
        palette.setColor(QPalette::Base,QColor(178, 238, 212));
        retypePasswordLineEdit->setPalette(palette);
    }else{
        QPalette palette;
        palette.setColor(QPalette::Base,QColor(255, 155, 155));
        retypePasswordLineEdit->setPalette(palette);
    }
}

