#include "Utils.h"
#include<regex>
#include<qpassworddigestor.h>

Utils::Utils()
{
}

std::string Utils:: HashPbdkf1(std::string password){
    std::string salt="saltsalt";
    QByteArray bytePass(password.c_str(),password.length());
    QByteArray byteSalt(salt.c_str(),salt.length());
    QByteArray byteHash= QPasswordDigestor::deriveKeyPbkdf1(QCryptographicHash::Sha1, bytePass, byteSalt, 10, 20);
    std::string hash(byteHash.constData(),byteHash.length());
    return hash;
}

bool Utils:: IsValidPassword(std::string password) {
    std::regex hasNumber = std::regex("[0-9]+");
    std::regex hasUpperChar = std::regex("[A-Z]+");
    std::regex hasLowerChar = std::regex("[a-z]+");
    std::regex hasMinimum8Chars = std::regex(".{8,}");
    return regex_search(password, hasNumber)
            && regex_search(password, hasUpperChar)
            && regex_search(password, hasLowerChar)
            && regex_search(password, hasMinimum8Chars);
}

bool IsLatinName(std::string name)
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

bool Utils:: IsValidName(std::string name)
{
    return !name.empty() && IsLatinName(name);
}
