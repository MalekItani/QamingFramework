#include "gamewindow.h"

/**
* \file gamewindow.cpp
* \brief Game Window class defintion
*
* Contains the definitions of the base methods that all game windows will use
* \author Malek Itani
*/

GameWindow::GameWindow(QWidget *parent) : QWidget(parent){

}

void GameWindow::exit(){
    gameProfile->save();
    emit windowClosed();
}

