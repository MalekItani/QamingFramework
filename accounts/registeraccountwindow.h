#ifndef REGISTERACCOUNTWINDOW_H
#define REGISTERACCOUNTWINDOW_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

#include <accounts/user.h>

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

    User* userPtr;

public slots:
    void registerAccount();
    void checkMatchingPasswords(const QString&);

signals:
    void userApproved(User*);

};

#endif // REGISTERACCOUNTWINDOW_H
