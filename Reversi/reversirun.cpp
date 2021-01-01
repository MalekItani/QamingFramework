#include "reversirun.h"
#include <Utils/jsonio.h>


/**
* \file reversirun.cpp
* \brief Implementation of the Reversi-specific Game Run.
* \author Malek Itani
*/

ReversiRun::ReversiRun(){

}

ReversiRun::ReversiRun(const QString& path):BaseRun(path){}

ReversiRun::ReversiRun(int black, int white) : numBlacks(black), numWhites(white){}

bool ReversiRun::lessThan(const BaseRun *rhs){
    ReversiRun* other = (ReversiRun *) rhs;
    if(this->getScore() == other->getScore()){
        return this->timeTaken > other->timeTaken;
    }else{
        return this->getScore() < other->getScore();
    }
}

int ReversiRun::toJson(){
    QJsonObject reversiRun;

    reversiRun["datetime"] = QString::number(this->datetime);

    reversiRun["player_name"] = this->playerName;

    reversiRun["num_blacks"] = this->numBlacks;
    reversiRun["num_whites"] = this->numWhites;
    reversiRun["time_taken"] = QString::number(this->timeTaken);

    return JsonIO::writeObject(reversiRun, path);
}

int ReversiRun::fromJson(){
    QJsonObject reversiRun;

    int errorCode = JsonIO::readObject(reversiRun, path);

    this->datetime = reversiRun["datetime"].toString().toULongLong();
    this->playerName = reversiRun["player_name"].toString();
    this->numWhites = reversiRun["num_whites"].toInt();
    this->numBlacks = reversiRun["num_blacks"].toInt();
    this->timeTaken= reversiRun["time_taken"].toString().toLong();

    return errorCode;
}

/**
* \brief Score is assumed to be # of blacks - # of whites
*/
int ReversiRun::getScore(){
    return this->numBlacks - this->numWhites;
}
