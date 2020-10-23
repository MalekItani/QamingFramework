#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include "leaderboard.h"
#include "playerdetails.h"
#include "killcovid19view.h"
#include "killcoviduser.h"


class KillCovid_19Window : public QWidget
{
    Q_OBJECT
public:
    explicit KillCovid_19Window(QString username, QWidget *parent = nullptr);
    Leaderboard * leaderboard;
    PlayerDetails * playerDetails;
    KillCovid_19View * gameView;
    KillCovidUser * gameUser;
    QPushButton*qPushButton1,*qPushButton2;
    QHBoxLayout* MainLayout;
private:
    void FillUserData(QString username);

public slots:


};

#endif // GAME1SCENE_H
