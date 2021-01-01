#include "reversistatswidget.h"

/**
* \file reversistatswidget.cpp
* \brief Implementation of the ReversiStatsWidget.
* \author Malek Itani
*/

ReversiStatsWidget::ReversiStatsWidget(QWidget *parent) : QWidget(parent){

    layout = new QGridLayout();

    QFont titleFont( "Arial", 22, QFont::Bold);
    QFont scoreFont( "Arial", 14, QFont::Bold);
    player1Label = new QLabel("BLACK");
    player1Label->setAlignment(Qt::AlignCenter);
    player1Label->setFont(titleFont);
    layout->addWidget(player1Label, 0, 0, 1, 2);

    score1Label = new QLabel("Score: ");
    score1Label->setFont(scoreFont);
    layout->addWidget(score1Label, 1, 0);

    score1ValueLabel = new QLabel("0");
    score1ValueLabel->setFont(scoreFont);
    layout->addWidget(score1ValueLabel, 1, 1);

    timeRemaining1Label = new QLabel("Time Remaining: ");
    timeRemaining1Label->setFont(scoreFont);
    layout->addWidget(timeRemaining1Label, 2, 0);

    timeRemaining1ValueLabel = new QLabel("300 s");
    timeRemaining1ValueLabel->setFont(scoreFont);
    layout->addWidget(timeRemaining1ValueLabel, 2, 1);

    layout->addItem(new QSpacerItem(1, 50), 3, 0);

    player2Label = new QLabel("WHITE");
    player2Label->setFont(titleFont);
    player2Label->setAlignment(Qt::AlignCenter);
    layout->addWidget(player2Label, 4, 0, 1, 2);

    score2Label = new QLabel("Score: ");
    score2Label->setFont(scoreFont);
    layout->addWidget(score2Label, 5, 0);

    score2ValueLabel = new QLabel("0");
    score2ValueLabel->setFont(scoreFont);
    layout->addWidget(score2ValueLabel, 5, 1);

    timeRemaining2Label = new QLabel("Time Remaining: ");
    timeRemaining2Label->setFont(scoreFont);
    layout->addWidget(timeRemaining2Label, 6, 0);

    timeRemaining2ValueLabel = new QLabel("300 s");
    timeRemaining2ValueLabel->setFont(scoreFont);
    layout->addWidget(timeRemaining2ValueLabel, 6, 1);

    setLayout(layout);
}

void ReversiStatsWidget::scoreUpdate(int blackCnt, int whiteCnt){
    score1ValueLabel->setText(QString::number(blackCnt));
    score2ValueLabel->setText(QString::number(whiteCnt));
}

void ReversiStatsWidget::timeUpdate(int blackTime, int whiteTime){
    timeRemaining1ValueLabel->setText(QString::number(blackTime) + " s");
    timeRemaining2ValueLabel->setText(QString::number(whiteTime) + " s");
}


