#ifndef REVERSISCENE_H
#define REVERSISCENE_H
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
#include "stone.h"
#include "reversirun.h"

/**
* \file reversiscene.h
* \brief reversi scene header file
* The scene of the reversi game, contains the board and the added stones
* \author Khalil Baydoun
*/
class ReversiScene: public QGraphicsScene{
    Q_OBJECT
public:
    ReversiScene();
    /**
    * \brief Starts the game .
    */
    void StartGame();
    /**
    * \brief shows the main menu of the game
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
    * \brief makes the necessary updates and deletes when the game ends
    */
    void EndGame();
    /**
    * \param stoneColor the color of the stone
    * \param x the x position of the stone item in the scene
    * \param y the y position of the stone item in the scene
    * \brief initializes a Stone item and adds it to the scene
    */
    void CreateStone(bool stoneColor, int xcor, int ycor);
    /**
    * \brief Called when the mouse is pressed to place a stone on the board
    */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /**
    * \param x the x position of the stone item in the scene
    * \param y the y position of the stone item in the scene
    * \param value the color of the stone
    * \brief checks if the stone at the given position has the sent color
    */
    bool CheckVal(int x,int y, bool value);
    /**
    * \param x the x position of the stone item in the scene
    * \param y the y position of the stone item in the scene
    * \param value the color of the stone
    * \brief checks if stone can be placed at the given coordinates
    */
    bool CheckIfValidMove(int x,int y, bool value);
    /**
    * \param x the x position of the stone item in the scene
    * \param y the y position of the stone item in the scene
    * \param xInc the x increment to the position of the stone item in the scene
    * \param yInc the y increment to the position of the stone item in the scene
    * \param value the color of the stone
    * \brief checks if path can be outflanked
    */
    int CheckPath(int xcur, int ycur, int xInc, int yInc, bool value);
    /**
    * \param stoneType the color of the stone
    * \brief checks if player with the given stone color has a valid move
    */
    bool CheckIfThereIsPossibleMove(bool stoneType);
    /**
    * \param xcur the x position of the stone item in the scene
    * \param ycur the y position of the stone item in the scene
    * \param xInc the x increment to the position of the stone item in the scene
    * \param yInc the y increment to the position of the stone item in the scene
    * \param value the color of the stone
    * \brief flips the path
    */
    void FlipPath(int xcur, int ycur, int xInc, int yInc, bool value);
    /**
    * \param x the x position of the stone item in the scene
    * \param y the y position of the stone item in the scene
    * \brief plays a move at the specified position
    */
    void PlayMove(int x, int y);
    /**
    * \brief plays a turn
    */
    void PrintTurn();

    bool gameEnded=false, turn=false, gameStarted=false;
    int blackCnt=2, whiteCnt=2;
    int blackPlayerTimeRemaining=300, whitePlayerTimeRemaining=300;
    std::vector<std::vector<Stone*>>stones;
    QGraphicsTextItem *blackTurn, *whiteTurn;
    QTimer * timeUpdateTimer;
public slots:
    /**
    * \brief update the timers for the players
    */
    void UpdateTime();
signals:
    /**
    * \brief signal emitted to update the scores
    */
    void scoreUpdate(int black, int white);
    /**
    * \brief signal emitted to update the timers
    */
    void timeUpdate(int timeBlack, int timeWhite);
    /**
    * \brief signal emitted when the game ends
    */
    void gameOver(ReversiRun *run);

};

#endif // REVERSISCENE_H
