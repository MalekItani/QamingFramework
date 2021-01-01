#include "gamehistorywidget.h"

#include <shared/gameprofile.h>
#include <KillCovid-19/killcovidrun.h>
#include <Reversi/reversirun.h>

#include <iostream>

/**
* \file gamehistorywidget.h
* \brief Implementation of the GameHistoryWidget.
* \author Malek Itani
*/


GameHistoryWidget::GameHistoryWidget(QWidget *parent) : QScrollArea(parent){
    tabWidget = new QTabWidget();
}

void GameHistoryWidget::fill(User *user){
    delete tabWidget;

    tabWidget = new QTabWidget();

    QWidget* killCovidPage = new QWidget();

    GameProfile *killCovidGameProfile = GameProfile::build<KillCovidRun>("../KillCovid-19", user);
    Leaderboard *killCovidLeaderboard = killCovidGameProfile->getLeaderboard();

    QGridLayout* killCovidHistoryLayout = new QGridLayout();
    if(killCovidLeaderboard->size() > 0){

        QLabel* overallHighestScoreLabel = new QLabel("Overall Highest Score");
        overallHighestScoreLabel->setAlignment(Qt::AlignCenter);

        killCovidHistoryLayout->addWidget(overallHighestScoreLabel, 0, 0);

        KillCovidRun *bestRun = (KillCovidRun *) *killCovidLeaderboard->begin();

        killCovidHistoryLayout->addWidget(new QLabel("Player Name"), 1, 0);
        killCovidHistoryLayout->addWidget(new QLabel("Score"), 1, 1);

        killCovidHistoryLayout->addWidget(new QLabel(bestRun->getPlayerName()), 2, 0);
        killCovidHistoryLayout->addWidget(new QLabel(QString::number(bestRun->getScore())), 2, 1);

        QLabel* yourHistoryLabel = new QLabel("Your History");
        yourHistoryLabel->setAlignment(Qt::AlignCenter);

        killCovidHistoryLayout->addWidget(yourHistoryLabel, 3, 0);

        int gamesPlayed = killCovidGameProfile->getNumberOfGamesPlayed();
        if(gamesPlayed > 0){
            killCovidHistoryLayout->addWidget(new QLabel("Score"), 4, 0);
            killCovidHistoryLayout->addWidget(new QLabel("Date"), 4, 1);
            for(int i = 0; i < gamesPlayed; i++){
                KillCovidRun *run = new KillCovidRun("../KillCovid-19/user_data/" + user->getUsername() + '/'
                                                     + QString::number(gamesPlayed-i-1) + ".json");
                run->fromJson();
                killCovidHistoryLayout->addWidget(new QLabel(QString::number(run->getScore())), 5 + i, 0);
                killCovidHistoryLayout->addWidget(new QLabel(run->getDateTime().toString("dd/MM/yyyy")), 5 + i, 1);
            }
        }else{
            killCovidHistoryLayout->addWidget(new QLabel("You have not played this game yet."), 4, 0, 1, 2);
        }
    }else{
        killCovidHistoryLayout->addWidget(new QLabel("No one has played this game yet."), 0, 0, 1, 2);
    }

    killCovidPage->setLayout(killCovidHistoryLayout);


    QWidget* reversiPage = new QWidget();

    GameProfile *reversiGameProfile = GameProfile::build<ReversiRun>("../Reversi", user);
    Leaderboard *reversiLeaderboard = reversiGameProfile->getLeaderboard();

    QGridLayout* reversiHistoryLayout = new QGridLayout();
    if(reversiLeaderboard->size() > 0){

        QLabel* overallHighestScoreLabel = new QLabel("Overall Highest Score");
        overallHighestScoreLabel->setAlignment(Qt::AlignCenter);

        reversiHistoryLayout->addWidget(overallHighestScoreLabel, 0, 0);

        ReversiRun *bestRun = (ReversiRun *) *reversiLeaderboard->begin();

        reversiHistoryLayout->addWidget(new QLabel("Player Name"), 1, 0);
        reversiHistoryLayout->addWidget(new QLabel("Score"), 1, 1);

        reversiHistoryLayout->addWidget(new QLabel(bestRun->getPlayerName()), 2, 0);
        reversiHistoryLayout->addWidget(new QLabel(QString::number(bestRun->getScore())), 2, 1);

        QLabel* yourHistoryLabel = new QLabel("Your History");
        yourHistoryLabel->setAlignment(Qt::AlignCenter);

        reversiHistoryLayout->addWidget(yourHistoryLabel, 3, 0);

        int gamesPlayed = reversiGameProfile->getNumberOfGamesPlayed();
        if(gamesPlayed > 0){
            reversiHistoryLayout->addWidget(new QLabel("Score"), 4, 0);
            reversiHistoryLayout->addWidget(new QLabel("Date"), 4, 1);
            for(int i = 0; i < gamesPlayed; i++){
                ReversiRun *run = new ReversiRun("../Reversi/user_data/" + user->getUsername() + '/'
                                                     + QString::number(gamesPlayed-i-1) + ".json");
                run->fromJson();
                reversiHistoryLayout->addWidget(new QLabel(QString::number(run->getScore())), 5 + i, 0);
                reversiHistoryLayout->addWidget(new QLabel(run->getDateTime().toString("dd/MM/yyyy")), 5 + i, 1);
            }
        }else{
            reversiHistoryLayout->addWidget(new QLabel("You have not played this game yet."), 4, 0, 1, 2);
        }
    }else{
        reversiHistoryLayout->addWidget(new QLabel("No one has played this game yet."), 0, 0, 1, 2);
    }

    reversiPage->setLayout(reversiHistoryLayout);

    tabWidget->addTab(killCovidPage, "KillCovid-19");
    tabWidget->addTab(reversiPage, "Reversi");
    tabWidget->setMinimumWidth(viewport()->width());

    setWidget(tabWidget);
}
