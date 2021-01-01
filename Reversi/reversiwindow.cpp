#include "reversiwindow.h"
#include "reversirun.h"
/**
* \file reversiwindow.cpp
* \brief Reversi window class defintion
*
* Contains the iniatialization of the reversi game window and and the implementation of its functions.
* \author Khalil Baydoun
*/


ReversiWindow::ReversiWindow(User *user, QWidget *parent) : GameWindow(parent){
    this->setFixedSize(1200,500);
    this->setObjectName("REVERSI");
    MainLayout=new QHBoxLayout();

    gameProfile = GameProfile::build<ReversiRun>("../Reversi", user);
    playerWidget = new ReversiPlayerWidget(gameProfile);
    MainLayout->addWidget(playerWidget);

    gameView = new ReversiView();
    MainLayout->addWidget(gameView);
    gameScene = new ReversiScene();

    gameView->setGameScene(gameScene);

    statsWidget = new ReversiStatsWidget();
    MainLayout->addWidget(statsWidget);

    connect(gameScene, SIGNAL(gameOver(ReversiRun*)), this, SLOT(resetWindow(ReversiRun*)));
    connect(gameView, SIGNAL(gameExited()), this, SLOT(exit()));
    connect(gameScene, SIGNAL(scoreUpdate(int, int)), statsWidget, SLOT(scoreUpdate(int, int)));
    connect(gameScene, SIGNAL(timeUpdate(int, int)), statsWidget, SLOT(timeUpdate(int, int)));

    this->setLayout(MainLayout);
}

void ReversiWindow::resetWindow(ReversiRun* run){
    run->setDateTime(QDateTime::currentDateTime());
    run->setPlayerName(gameProfile->getUser()->getUsername());

    gameProfile->addRun((BaseRun *) run);
    gameView->MainMenu();

    playerWidget->update();

    gameProfile->save();
}
