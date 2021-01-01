#include "leaderboard.h"

#include <Utils/jsonio.h>

#include <QJsonArray>
#include <QJsonObject>


/**
* \file leaderboard.cpp
* \brief Leaderboard class defintion
*
* Contains the definitions of the leaderboard methods
* \author Malek Itani
*/

Leaderboard::Leaderboard(){

}

Leaderboard::Leaderboard(const QString &gameBasePath, int size) : maxSize(size){
    path = gameBasePath + "/user_data/Leaderboard.json";
}

int Leaderboard::toJson(){
    QJsonArray leaderboardList;

    for(auto run : *this){
        leaderboardList.append(run->getPath());
    }

    QJsonObject leaderboardObject;
    leaderboardObject["leaderboard"] = leaderboardList;

    return JsonIO::writeObject(leaderboardObject, path);
}

void Leaderboard::save(){
    toJson();
}

bool Leaderboard::addRun(BaseRun *run){
    if((int) this->size() < maxSize) {
        insert(run);
        return 1;
    }
    comparator comp;
    bool ret = comp(*rbegin(), run);

    insert(run);
    erase(*rbegin());

    return ret;
}

bool comparator::operator()(BaseRun *run1, BaseRun *run2) const{
    return run2->lessThan(run1);
}
