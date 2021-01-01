#ifndef REVERSISTATSWIDGET_H
#define REVERSISTATSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

/**
* \file reversistatswidget.h
* \brief Header file for the widget that displays Reversi-specific
* game states like remaining time for each user and the score for
* each user.
* \author Malek Itani
*/


class ReversiStatsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReversiStatsWidget(QWidget *parent = nullptr);

    QGridLayout *layout;

    QLabel *player1Label;
    QLabel *player2Label;

    QLabel *score1Label;
    QLabel *score2Label;

    QLabel *score1ValueLabel;
    QLabel *score2ValueLabel;

    QLabel *timeRemaining1Label;
    QLabel *timeRemaining2Label;

    QLabel *timeRemaining1ValueLabel;
    QLabel *timeRemaining2ValueLabel;

public slots:

    /**
    * \brief Updates the player scores on the stats widget.
    */
    void scoreUpdate(int blackCnt, int whiteCnt);

    /**
    * \brief Updates the time remaining on the scores on the stats widget.
    */
    void timeUpdate(int blackTime, int whiteTime);

signals:

};

#endif // REVERSISTATSWIDGET_H
