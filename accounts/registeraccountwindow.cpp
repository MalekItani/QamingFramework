#include "registeraccountwindow.h"
#include <accounts/user.h>

#include <iostream>

registerAccountWindow::registerAccountWindow(QWidget *parent) : QWidget(parent){

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
    gridLayout->addWidget(passwordLineEdit, 3, 1);

    retypePasswordLabel = new QLabel("Retype Password");
    gridLayout->addWidget(retypePasswordLabel, 4, 0);

    retypePasswordLineEdit = new QLineEdit();
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

    QObject::connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(registerAccount()));
}

void registerAccountWindow::registerAccount(){
    if(passwordLineEdit->text() != retypePasswordLineEdit->text()){
        // TODO: Post error message
        return;
    }
    // TODO: Add sanity checks like gender selected, valid password, etc...

    User user;
    user.setFirstName(firstNameLineEdit->text());
    user.setLastName(lastNameLineEdit->text());
    user.setUsername(usernameLineEdit->text());
    user.setPassword(passwordLineEdit->text());

    int gender;
    if(maleRadioButton->isChecked()) gender = 1;
    if(femaleRadioButton->isChecked()) gender = 2;
    user.setGender(gender);
    user.setDateOfBirth(dateSelector->selectedDate());

    int code = user.toJSON();
    switch(code){
        case 1:
            std::cerr << "ERROR: Could not open JSON for write" << std::endl; // TODO: This is not appropriate
            return;
    }
    close();
}
