#ifndef KillCovid19LeaderboardWidget_H
#define KillCovid19LeaderboardWidget_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <accounts/user.h>
#include <shared/leaderboard.h>

/**
* \file killcovid19leaderboardwidget.h
* \brief Header file for the widget that displays a leaderboard at on side of
* the KillCovid19 game window.
* \author Malek Itani
*/

class KillCovid19LeaderboardWidget : public QScrollArea{
    Q_OBJECT
public:
    explicit KillCovid19LeaderboardWidget();

    /**
    * \brief Sets the Leaderboard for the widget. The widget will update accordingly.
    */
    void setLeaderboard(Leaderboard *leaderboard);

private:
    void refresh();

    QWidget *page;
    QVBoxLayout* layout;
    Leaderboard* leaderboard;

};

#endif // KillCovid19LeaderboardWidget_H
