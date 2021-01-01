#include "Utils.h"
#include<regex>
#include<qpassworddigestor.h>
#include <QFileInfo>
/**
* \file Utils.cpp
* \brief Utils class defintion
*
* Contains the iniatialization of the Utils class and and the implementation of its functions.
* \author Khalil Baydoun
*/
Utils::Utils()
{
}

QString Utils:: HashPbdkf1(QString password){
    QString salt="saltsalt";
    QByteArray bytePass=password.toUtf8();
    QByteArray byteSalt=salt.toUtf8();
    QByteArray byteHash= QPasswordDigestor::deriveKeyPbkdf1(QCryptographicHash::Sha1, bytePass, byteSalt, 10, 20);
    QString hash(byteHash);
    return hash;
}

bool Utils:: IsValidPassword(QString Qpassword) {
    std::regex hasNumber = std::regex("[0-9]+");
    std::regex hasUpperChar = std::regex("[A-Z]+");
    std::regex hasLowerChar = std::regex("[a-z]+");
    std::regex hasMinimum8Chars = std::regex(".{8,}");
    std::string password=Qpassword.toUtf8().constData();
    return regex_search(password, hasNumber)
            && regex_search(password, hasUpperChar)
            && regex_search(password, hasLowerChar)
            && regex_search(password, hasMinimum8Chars);
}

bool IsLatinName(QString name)
{
    if (name.size() == 0)return false;

    for (int i = 0; i < (int) name.size(); i++)
    {
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' '))
        {
            return false;
        }
    }

    return true;
}

bool Utils:: IsValidName(QString name)
{
    return !name.isEmpty() && IsLatinName(name);
}

bool Utils:: fileExists(QString path) {
    QFileInfo check_file(path);
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

void Utils::Popup(QString title, QString text){
    auto errorBox = new QMessageBox();
    errorBox->setWindowTitle(title);
    errorBox->setText(text);
    errorBox->exec();
}

void  Utils::delay(int milliSeconds)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(milliSeconds);
    loop.exec();
}
