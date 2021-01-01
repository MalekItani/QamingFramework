#ifndef KILLCOVIDUSER_H
#define KILLCOVIDUSER_H
#include "accounts/user.h"

class KillCovidUser
{
public:
    KillCovidUser();
    QString username;
    int highScore;
    int totalVirusesKilled;
    int totalTimePlayedInMinutes;
    double accuracy;
};

#endif // KILLCOVIDUSER_H
