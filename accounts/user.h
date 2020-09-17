#ifndef USER_H
#define USER_H

#include <QDate>

class User{
public:
    User();

    QString getFirstName();
    QString getLastName();
    QString getUsername();
    QString getPassword();
    QString getProfilePicturePath();
    QDate getDateOfBirth();
    int getGender();

    void setFirstName(QString);
    void setLastName(QString);
    void setUsername(QString);
    void setPassword(QString);
    void setProfilePicturePath(QString);
    void setDateOfBirth(QDate);
    void setGender(int);

    int fromJSON(QString, QString);
    int toJSON();

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
