#ifndef REGISTERACCOUNTWINDOW_H
#define REGISTERACCOUNTWINDOW_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

#include <accounts/user.h>
#include <accounts/profilepicturechooser.h>

/**
* \file registeraccountwindow.h
* \brief This is the window that lets users register new accounts.
* \author Malek Itani
*/

class registerAccountWindow : public QWidget
{
    Q_OBJECT
public:
    explicit registerAccountWindow(QWidget *parent = nullptr);

private:
    QGridLayout* gridLayout;
    QVBoxLayout* genderButtonLayout;

    QLabel* firstNameLabel;
    QLabel* lastNameLabel;
    QLabel* usernameLabel;
    QLabel* passwordLabel;
    QLabel* retypePasswordLabel;
    QLabel* genderLabel;
    QLabel* dateOfBirthLabel;

    QLineEdit* firstNameLineEdit;
    QLineEdit* lastNameLineEdit;
    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;
    QLineEdit* retypePasswordLineEdit;

    QGroupBox* genderButtonGroupBox;

    QRadioButton* maleRadioButton;
    QRadioButton* femaleRadioButton;

    QPushButton* submitButton;

    QCalendarWidget* dateSelector;

    ProfilePictureChooser* profilePictureChooser;

    User* userPtr;

public slots:
    /**
    * \brief Performs account registration.
    * If an account has a valid first name, lastname, username and password,
    * it emits a userApproved() signal and transfers control back to the main window.
    */
    void registerAccount();
    /**
    * \brief Checks if the password and retyped passwords match.
    * This is used to change the cell colors to green when they match and red when they don't.
    * It lets a user figure out if the passwords match without needing to click register
    * and fail.
    */
    void checkMatchingPasswords(const QString&);

signals:
    /**
    * \brief Signal that is emitted if an account is successfully registered.
    */
    void userApproved(User*);
};

#endif // REGISTERACCOUNTWINDOW_H
