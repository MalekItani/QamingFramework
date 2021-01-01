#ifndef KillCovid_19Scene_H
#define KillCovid_19Scene_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>
#include <QtAlgorithms>
#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include "Utils/Utils.h"
#include "cursor.h"
#include "virus.h"
#include "killcovidrun.h"
/**
* \file killcovid19scene.h
* \brief Kill covid 19 scene class header file
* This is the main scene of the kill covid 19 game that contains the falling viruses, cursor, score labels, and a background image
* author Khalil Baydoun
*/


class KillCovid_19Scene : public QGraphicsScene{
    Q_OBJECT
public:

    QGraphicsTextItem *misses,*smallViruses,*mediumViruses,*largeViruses,*score;
    int missesCnt,scoreCnt,killedVirus=0,virusRollingSpeed;
    int virusesCnts[3]={0,0,0};
    bool gameEnded=false;
    std::vector<std::vector<int>>virusesPostions;
    Cursor *cursor;
    Virus *virus;
    /**
    * \brief kill covid 19 game constructor, responsible for initializing the scene
    */
    KillCovid_19Scene();
    /**
    * \param _virusesPositions the starting positions of the falling viruses
    * \brief starts the game by changing the background, and showing the rotating cursors and makes the viruses starts falling.
    */
    void StartGame(std::vector<std::vector<int>> &_virusesPostions);
    /**
    * \brief Initializes the main menu of the game
    */
    void MainMenu();
    /**
    * \param item the text item to be initialized
    * \param x the x position of the text item in the scene
    * \param y the y position of the text item in the scene
    * \brief initializes a graphics text item and adds it to the scene
    */
    void inializeTextItem(QGraphicsTextItem * &item,int x,int y);
    /**
    * \brief initializes the labels on the scene
    */
    void FillLabels();
    /**
    * \brief makes the necessary updates and deletes when the game ends
    */
    void EndGame(bool win);
    /**
    * \brief detects when a key is pressed to shoot the cursor
    */
    void keyPressEvent(QKeyEvent *event);

private:
    KillCovidRun *run;
    int numSpawned;

signals:
    /**
    * \brief  signal emitted when the game ends
    */
    void gameOver(KillCovidRun *run);

public slots:
    /**
    * \brief creates and initializes the cursor
    */
    void CreateCursor();
    /**
    * \brief creates and initializes the virus
    */
    void CreateVirus();
    /**
    * \brief deletes the virus that got hit with the  cursor
    */
    void DeleteHitVirus();
};

#endif // KillCovid_19Scene_H
