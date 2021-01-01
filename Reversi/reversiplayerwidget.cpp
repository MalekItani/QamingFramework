#include "reversiplayerwidget.h"
#include "reversirun.h"
#include <shared/gameprofile.h>


/**
* \file reversiplayerwidget.cpp
* \brief Implementation for the ReversiPlayerWidget.
* \author Malek Itani
*/


ReversiPlayerWidget::ReversiPlayerWidget(GameProfile *profile){
    this->gameProfile = profile;

    layout = new QGridLayout();

    QPixmap pixmap("../" + profile->getUser()->getProfilePicturePath());
    pixmap = pixmap.scaled(96, 96,Qt::KeepAspectRatio);
    QLabel* userPicture = new QLabel();
    userPicture->setPixmap(pixmap);

    layout->addWidget(userPicture, 0, 0, 1, 2);

    layout->addWidget(new QLabel("Player: "), 1, 0);

    usernameLabel = new QLabel(profile->getUser()->getUsername());
    layout->addWidget(usernameLabel, 1, 1);

    layout->addWidget(new QLabel("PREVIOUS SCORE: "), 2, 0);

    ReversiRun* lastRun = (ReversiRun *) profile->getLastRun();
    QString previousScore = (lastRun ? QString::number(lastRun->getScore()) : "N/A");
    previousScoreLabel = new QLabel(previousScore);

    layout->addWidget(previousScoreLabel, 2, 1);

    layout->addWidget(new QLabel("HIGHSCORE: "), 3, 0);

    ReversiRun* bestRun = (ReversiRun *) profile->getBestRun();
    QString highscore = (bestRun ? QString::number(bestRun->getScore()) : "N/A");
    highScoreLabel = new QLabel(highscore);

    layout->addWidget(highScoreLabel, 3, 1);

    layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    this->setLayout(layout);
}

void ReversiPlayerWidget::update(){
    ReversiRun* lastRun = (ReversiRun *) gameProfile->getLastRun();
    QString previousScore = (lastRun ? QString::number(lastRun->getScore()) : "N/A");
    previousScoreLabel->setText(previousScore);

    ReversiRun* bestRun = (ReversiRun *) gameProfile->getBestRun();
    QString highscore = (bestRun ? QString::number(bestRun->getScore()) : "N/A");
    highScoreLabel->setText(highscore);
}
