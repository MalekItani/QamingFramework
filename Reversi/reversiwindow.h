#ifndef REVERSIWINDOW_H
#define REVERSIWINDOW_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <shared/gameprofile.h>
#include <shared/leaderboard.h>
#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include "reversiview.h"
#include "reversiplayerwidget.h"
#include "reversirun.h"
#include "reversistatswidget.h"
#include <shared/gamewindow.h>
/**
* \file reversiview.h
* \brief reversi window header file
* The window of the reversi game
* \author Khalil Baydoun
*/
class ReversiWindow : public GameWindow
{
    Q_OBJECT
public:
    explicit ReversiWindow(User *user, QWidget *parent = nullptr);
private:
    ReversiPlayerWidget *playerWidget;
    ReversiView *gameView;
    QHBoxLayout *MainLayout;
    ReversiScene * gameScene;
    ReversiStatsWidget *statsWidget;

public slots:
    /**
    * \brief resets the window when the game restarts
    */
    void resetWindow(ReversiRun*);

};

#endif // REVERSIWINDOW_H
