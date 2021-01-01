#include "gameprofile.h"

#include <QJsonObject>
#include <Utils/jsonio.h>

/**
* \file gameprofile.cpp
* \brief Game Profile class defintion
* \author Malek Itani
*/

GameProfile::GameProfile(){

}

int GameProfile::toJSON(){
    QJsonObject gameProfile;

    gameProfile["games_played"] = gamesPlayed;
    gameProfile["last_run"] = lastRun->getId();
    gameProfile["best_run"] = bestRun->getId();

    return JsonIO::writeObject(gameProfile, path + "/profile.json");
}

void GameProfile::addRun(BaseRun* run){
    run->setId(gamesPlayed);
    run->setPath(path + "/" + QString::number(gamesPlayed) + ".json");
    lastRun = run;
    if(bestRun == NULL || bestRun->lessThan(run) ){
        bestRun = run;
    }
    leaderboard->addRun(run);
    run->toJson();
    gamesPlayed++;
}

Leaderboard* GameProfile::getLeaderboard(){
    return leaderboard;
}

void GameProfile::save(){
    this->toJSON();
    leaderboard->save();
}

int GameProfile::getNumberOfGamesPlayed(){
    return gamesPlayed;
}

User* GameProfile::getUser(){
    return user;
}

BaseRun* GameProfile::getBestRun(){
    return bestRun;
}

BaseRun* GameProfile::getLastRun(){
    return lastRun;
}
