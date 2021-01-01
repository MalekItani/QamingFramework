#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <shared/gameprofile.h>
#include <shared/leaderboard.h>
#include "killcovid19view.h"
#include "killcovid19leaderboardwidget.h"
#include "killcovid19playerwidget.h"
#include "killcovid19scene.h"
#include <shared/gamewindow.h>

/**
* \file killcovid_19window.h
* \brief kill covid-19 window header file
* The window of the killCovid game
* \author Khalil Baydoun
*/
class KillCovid_19Window : public GameWindow
{
    Q_OBJECT
public:
    explicit KillCovid_19Window(User *user, QWidget *parent = nullptr);
private:
    KillCovid19LeaderboardWidget *leaderboardWidget;
    Leaderboard *leaderboard;
    KillCovid19PlayerWidget *playerWidget;
    KillCovid_19View * gameView;
    KillCovid_19Scene * gameScene;
    QHBoxLayout* MainLayout;

public slots:
    /**
    * \brief resets the window when the game restarts
    */
    void resetWindow(KillCovidRun*);
};

#endif // GAME1SCENE_H
