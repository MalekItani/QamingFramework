#include "user.h"
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QDir>


User::User(){

}

// Writes user into accounts/user_data/{username}.json
int User::toJSON(){

    QJsonObject userJsonObject;
    userJsonObject["username"] = username;
    userJsonObject["password"] = password;
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
    QDir dir;
    dir.mkpath("../QamingFramework/accounts/user_data");

    QString filename = "../QamingFramework/accounts/user_data/" + username + ".json";

    QFile userFile(filename);
    if(userFile.open(QIODevice::WriteOnly)){
        userFile.write(document.toJson());
        userFile.close();
        return 0;
    }
    return 1;
}

// Initializes a guest user (i.e. user with default properties)
int User::fromJSON(){
    if(!QFile::exists("../QamingFramerwork/accounts/" + username + ".json")){
        username = "Guest";
        password="";
        firstName = "";
        lastName = "";
        gender=0;
        dateOfBirth = QDate(2020, 2, 30); // Invalid date, will never wish a happy birthday :'(
        profilePicturePath = "media/pp/default.png";
        toJSON();
    }
    return fromJSON("Guest", "");
}

// Initializes a user from username or password
int User::fromJSON(QString username, QString password){
    QFile userFile("../QamingFramework/accounts/user_data/" + username + ".json");
    if (userFile.open(QIODevice::ReadOnly)) {
        QByteArray data = userFile.readAll();
        userFile.close();
        QJsonDocument loadDoc(QJsonDocument::fromJson(data));
        QJsonObject userJsonObject = loadDoc.object();

        if(userJsonObject["password"] == password){
            this->username = userJsonObject["username"].toString();
            this->password = userJsonObject["password"].toString();
            this->firstName = userJsonObject["firstName"].toString();
            this->lastName = userJsonObject["lastName"].toString();
            this->profilePicturePath = userJsonObject["pathToProfilePic"].toString();
            this->gender = userJsonObject["gender"].toInt();

            QJsonObject dateOfBirthJsonObject = userJsonObject["dateOfBirth"].toObject();
            this->dateOfBirth = QDate(dateOfBirthJsonObject["year"].toInt(),
                                dateOfBirthJsonObject["month"].toInt(),
                                dateOfBirthJsonObject["day"].toInt());
            return 0;
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

void User::setFirstName(QString value){
    firstName = value;
}

void User::setLastName(QString value){
    lastName = value;
}

void User::setUsername(QString value){
    username = value;
}

void User::setPassword(QString value){
    password = value;
}

void User::setProfilePicturePath(QString value){
    profilePicturePath = value;
}

void User::setDateOfBirth(QDate value){
    dateOfBirth = value;
}

void User::setGender(int value){
    gender = value;
}
