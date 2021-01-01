#include "killcovidrun.h"

#include <Utils/jsonio.h>

/**
* \file killcovidrun.cpp
* \brief Implementation of the KillCovid-specific Game Run.
* \author Malek Itani
*/

KillCovidRun::KillCovidRun(){

}

KillCovidRun::KillCovidRun(const QString& path):BaseRun(path){}

KillCovidRun::KillCovidRun(int score) : score(score){}

bool KillCovidRun::lessThan(const BaseRun *rhs){
    KillCovidRun* other = (KillCovidRun *) rhs;
    if(this->score == other->score){
        return this->datetime > other->datetime;
    }else{
        return this->score < other->score;
    }
}

int KillCovidRun::toJson(){
    QJsonObject killCovidRun;

    killCovidRun["datetime"] = QString::number(this->datetime);

    killCovidRun["player_name"] = this->playerName;
    killCovidRun["score"] = this->score;

    return JsonIO::writeObject(killCovidRun, path);
}

int KillCovidRun::fromJson(){
    QJsonObject killCovidRun;

    int errorCode = JsonIO::readObject(killCovidRun, path);

    this->datetime = killCovidRun["datetime"].toString().toULongLong();
    this->playerName = killCovidRun["player_name"].toString();
    this->score = killCovidRun["score"].toInt();
    return errorCode;
}

int KillCovidRun::getScore(){
    return this->score;
}
