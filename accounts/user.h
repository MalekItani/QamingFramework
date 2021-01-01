#ifndef USER_H
#define USER_H

#include <QDate>

/**
* \file user.h
* \brief Header file for the User class.
* A user is just a collection of fields related to a registered (or Guest) account.
* \author Malek Itani
*/

class User{
public:
    User();

    /**
    * \brief Retrieves the user first name.
    */
    QString getFirstName();

    /**
    * \brief Retrieves the user's last name.
    */
    QString getLastName();

    /**
    * \brief Retrieves the user's username.
    */
    QString getUsername();

    /**
    * \brief Retrieves the user's password.
    */
    QString getPassword();

    /**
    * \brief Retrieves the path to the user's profile picture.
    */
    QString getProfilePicturePath();

    /**
    * \brief Retrieves the user's date of birth.
    */
    QDate getDateOfBirth();

    /**
    * \brief Retrieves the user's gender.
    */
    int getGender();

    /**
    * \brief Sets the user's first name.
    */
    void setFirstName(QString);

    /**
    * \brief Sets the user's last name.
    */
    void setLastName(QString);

    /**
    * \brief Sets the user's username.
    */
    void setUsername(QString);

    /**
    * \brief Sets the user's password.
    */
    void setPassword(QString);

    /**
    * \brief Sets the path to the user's profile picture.
    */
    void setProfilePicturePath(QString);

    /**
    * \brief Sets the user's date of birth.
    */
    void setDateOfBirth(QDate);

    /**
    * \brief Sets the user's gender.
    */
    void setGender(int);

    /**
    * \brief Loads the guest user from JSON.
    */
    int fromJSON();

    /**
    * \brief Loads the user details given the username and password.
    */
    int fromJSON(QString, QString);

    /**
    * \brief Writes the user details to JSON.
    */
    int toJSON();

    const static int USER_INVALID_USERNAME = 0;
    const static int USER_INVALID_PASSWORD = 1;
    const static int USER_LOGIN_SUCCESS = 2;

private:
    QString firstName;
    QString lastName;
    QString username;
    QString password;
    QString profilePicturePath;

    QDate dateOfBirth;

    int gender;

};

#endif // USER_H
