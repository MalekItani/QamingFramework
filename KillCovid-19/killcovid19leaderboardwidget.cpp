#include "killcovid19leaderboardwidget.h"
#include "killcovidrun.h"

#include <shared/leaderboard.h>

/**
* \file killcovid19leaderboardwidget.h
* \brief Implementation of the KillCovid19LeaderboardWidget.
* \author Malek Itani
*/

void KillCovid19LeaderboardWidget::setLeaderboard(Leaderboard *lb){
    leaderboard = lb;
    page = new QWidget();
    layout = new QVBoxLayout();
    refresh();
}

void KillCovid19LeaderboardWidget::refresh(){

    delete page;
    delete layout;

    page = new QWidget();
    layout = new QVBoxLayout();

    auto titleLabel=new QLabel("<h2>LEADERBOARD<h2>");
    layout->addWidget(titleLabel);
    layout->addSpacing(2);
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    auto it = leaderboard->begin();

    for(int i = 1; i <= 10 && it != leaderboard->end(); i++){
        KillCovidRun* covidRun = (KillCovidRun*) *it;
        QString rank = QString::number(i) + ". ";
        QString playerName = covidRun->getPlayerName() + " ";
        QString score = QString::number(covidRun->getScore());
        layout->addWidget(new QLabel(rank + playerName + score));
        layout->addSpacing(20);
        it++;
    }
    page->setLayout(layout);
    setWidget(page);
}

KillCovid19LeaderboardWidget::KillCovid19LeaderboardWidget(){

}


