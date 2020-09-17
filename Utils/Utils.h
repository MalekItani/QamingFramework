#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils
{
public:
    Utils();
    static bool IsValidPassword(std::string password);
    static bool IsValidName(std::string name);
    static std::string HashPbdkf1(std::string password);
};

#endif // USER_H
