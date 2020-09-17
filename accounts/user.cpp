#include "user.h"
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>


User::User(){

}

int User::toJSON(){

    QJsonObject userJsonObject;
    userJsonObject["username"] = username;
    userJsonObject["password"] = username;
    userJsonObject["firstName"] = firstName;
    userJsonObject["lastName"] = lastName;
    userJsonObject["pathToProfilePic"] = profilePicturePath;
    userJsonObject["gender"] = gender;

    QJsonObject dateOfBirthJsonObject;
    dateOfBirthJsonObject["day"] = dateOfBirth.day();
    dateOfBirthJsonObject["month"] = dateOfBirth.month();
    dateOfBirthJsonObject["year"] = dateOfBirth.year();

    userJsonObject["dateOfBirth"] = dateOfBirthJsonObject;

    QJsonDocument document(userJsonObject);

    QFile userFile(username + ".json");
    if(userFile.open(QIODevice::WriteOnly)){
        userFile.write(document.toJson());
        return 0;
    }
    return 1;
}

int User::fromJSON(QString& username, QString &password){
    QFile userFile(username + ".json");
    if (userFile.open(QIODevice::ReadOnly)) {
        QByteArray data = userFile.readAll();
        QJsonDocument loadDoc(QJsonDocument::fromJson(data));
        QJsonObject userJsonObject = loadDoc.object();

        if(userJsonObject["password"] == password){
            username = userJsonObject["username"].toString();
            password = userJsonObject["password"].toString();
            firstName = userJsonObject["firstName"].toString();
            lastName = userJsonObject["lastName"].toString();
            profilePicturePath = userJsonObject["firstName"].toString();
            gender = userJsonObject["gender"].toInt();

            QJsonObject dateOfBirthJsonObject = userJsonObject["dateOfBirth"].toObject();
            dateOfBirth = QDate(dateOfBirthJsonObject["year"].toInt(),
                                dateOfBirthJsonObject["month"].toInt(),
                                dateOfBirthJsonObject["day"].toInt());
        }
        return 2;
    }
    return 1;
}

QString User::getFirstName(){
    return firstName;
}

QString User::getLastName(){
    return lastName;
}

QString User::getUsername(){
    return username;
}

QString User::getPassword(){
    return password;
}

QString User::getProfilePicturePath(){
    return profilePicturePath;
}

QDate User::getDateOfBirth(){
    return dateOfBirth;
}

int User::getGender(){
    return gender;
}

void User::setFirstName(QString &value){
    firstName = value;
}

void User::setLastName(QString &value){
    lastName = value;
}

void User::setUsername(QString &value){
    username = value;
}

void User::setPassword(QString &value){
    password = value;
}

void User::setProfilePicturePath(QString &value){
    profilePicturePath = value;
}

void User::setDateOfBirth(QDate &value){
    dateOfBirth = value;
}

void User::setGender(int value){
    gender = value;
}
