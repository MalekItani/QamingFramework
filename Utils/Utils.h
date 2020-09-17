#ifndef USER_H
#define USER_H
#include<regex>
using namespace std;
class Utils
{
public:
    Utils();
    static bool IsValidPassword(string& password);
    static bool IsValidName(string& name);
};

#endif // USER_H
