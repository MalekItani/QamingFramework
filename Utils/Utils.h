#ifndef USER_H
#define USER_H
#include<regex>
#include<qpassworddigestor.h>

using namespace std;
class Utils
{
public:
    Utils();
    static bool IsValidPassword(string& password);
    static bool IsValidName(string& name);
    static string HashPbdkf1(string& password);
};

#endif // USER_H
