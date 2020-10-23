#include "killcovid-19window.h"
KillCovid_19Window::KillCovid_19Window(QString _username, QWidget *parent) : QWidget(parent)
{
   this->setFixedSize(1200,500);
   FillUserData(_username);
   this->setObjectName("KILL COVID-19");
   MainLayout=new QHBoxLayout();
   leaderboard=new Leaderboard();
   playerDetails=new PlayerDetails(gameUser);
   gameView=new KillCovid_19View();
   MainLayout->addWidget(playerDetails);
   MainLayout->addWidget(gameView);
   MainLayout->addWidget(leaderboard);
   this->setLayout(MainLayout);
}

void KillCovid_19Window :: FillUserData(QString username){
    gameUser=new KillCovidUser();
    gameUser->username=username;
    //fill other data from the user file of this game;

    //sample data:
    gameUser->accuracy=62.5;
    gameUser->totalTimePlayedInMinutes=150;
    gameUser->totalVirusesKilled=1430;
    gameUser->highScore=113;
}
