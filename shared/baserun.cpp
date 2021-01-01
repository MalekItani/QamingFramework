#include "baserun.h"

/**
* \file baserun.cpp
* \brief Base Run class defintion
*
* Contains the definitions of the base methods that all runs will need
* \author Malek Itani
*/


BaseRun::BaseRun(){}

BaseRun::BaseRun(const QString &path) : path(path){}

QString BaseRun::getPath(){
    return path;
}

int BaseRun::getId(){
    return id;
}

void BaseRun::setId(int _id){
    id = _id;
}

void BaseRun::setPath(const QString &newPath){
    path = newPath;
}

void BaseRun::setPlayerName(const QString& value){
    playerName = value;
}

void BaseRun::setDateTime(const QDateTime& dt){
    datetime = dt.toSecsSinceEpoch();
}

QString BaseRun::getPlayerName(){
    return playerName;
}

QDateTime BaseRun::getDateTime(){
    return QDateTime::fromSecsSinceEpoch(datetime);
}
