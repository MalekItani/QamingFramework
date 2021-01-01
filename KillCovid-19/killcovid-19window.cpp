#include "killcovid-19window.h"
#include "killcovidrun.h"
#include <accounts/user.h>
#include <iostream>
/**
* \file killcovid_19window.cpp
* \brief kill covid_19 window class defintion
*
* Contains the iniatialization of the killCovid-19 game window and the implementation of its functions.
* \author Khalil Baydoun
*/

KillCovid_19Window::KillCovid_19Window(User *user, QWidget *parent) : GameWindow(parent){
    this->setFixedSize(1200,500);
    this->setObjectName("KILL COVID-19");

    MainLayout=new QHBoxLayout();

    gameProfile = GameProfile::build<KillCovidRun>("../KillCovid-19", user);
    playerWidget = new KillCovid19PlayerWidget(gameProfile);
    MainLayout->addWidget(playerWidget);

    gameView = new KillCovid_19View();
    MainLayout->addWidget(gameView);

    gameScene = new KillCovid_19Scene();
    gameView->setGameScene(gameScene);

    leaderboardWidget = new KillCovid19LeaderboardWidget();
    leaderboardWidget->setLeaderboard(gameProfile->getLeaderboard());
    MainLayout->addWidget(leaderboardWidget);

    this->setLayout(MainLayout);

    connect(gameScene, SIGNAL(gameOver(KillCovidRun*)), this, SLOT(resetWindow(KillCovidRun*)));
    connect(gameView, SIGNAL(gameExited()), this, SLOT(exit()));    
}

void KillCovid_19Window::resetWindow(KillCovidRun* run){

    run->setDateTime(QDateTime::currentDateTime());
    run->setPlayerName(gameProfile->getUser()->getUsername());

    gameProfile->addRun((BaseRun *) run);
    gameView->MainMenu();

    playerWidget->update();

    gameProfile->save();

    leaderboardWidget->setLeaderboard(gameProfile->getLeaderboard());
}
