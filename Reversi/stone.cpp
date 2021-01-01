#include "stone.h"
/**
* \file stone.cpp
* \brief Reversi Game Stone class defintion
*
* Contains the iniatialization of the reversi game stone and and the implementation of its flip color function that is called when its outflanked.
* \author Khalil Baydoun
*/

Stone::Stone(bool stoneType, QObject *parent):QObject(parent){
    QString type="moon";
    if(stoneType)type="sun";
    QString imagePath = ":Reversi/res/"+type+".png";
    setPixmap((QPixmap(imagePath).scaled(50,45)));
    _stoneType=stoneType;
}

void Stone::FlipColor(){
    _stoneType=!_stoneType;
    QString type="moon";
    if(_stoneType)type="sun";
    QString imagePath = ":Reversi/res/"+type+".png";
    setPixmap((QPixmap(imagePath).scaled(50,45)));
}


