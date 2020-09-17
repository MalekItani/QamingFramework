#include "Utils.h"

Utils::Utils()
{
}

string Utils:: HashPbdkf1(string& password){
    string salt="saltsalt";
    QByteArray bytePass(password.c_str(),password.length());
    QByteArray byteSalt(salt.c_str(),salt.length());
    QByteArray byteHash= QPasswordDigestor::deriveKeyPbkdf1(QCryptographicHash::Sha1, bytePass, byteSalt, 10, 20);
    string hash(byteHash.constData(),byteHash.length());
    return hash;
}

bool Utils:: IsValidPassword(string& password) {
    regex hasNumber = regex("[0-9]+");
    regex hasUpperChar = regex("[A-Z]+");
    regex hasLowerChar = regex("[a-z]+");
    regex hasMinimum8Chars = regex(".{8,}");
    return regex_search(password, hasNumber)
            && regex_search(password, hasUpperChar)
            && regex_search(password, hasLowerChar)
            && regex_search(password, hasMinimum8Chars);
}

bool IsLatinName(string& name)
{
    if (name.size() == 0)return false;

    for (int i = 0; i < name.size(); i++)
    {
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' '))
        {
            return false;
        }
    }

    return true;
}

bool Utils:: IsValidName(string& name)
{
    return !name.empty() && IsLatinName(name);
}
