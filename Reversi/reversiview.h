#ifndef REVERSIVIEW_H
#define REVERSIVIEW_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QTimer>
#include "reversiscene.h"
/**
* \file reversiview.h
* \brief reversi view header file
* The view of the reversi game, contains the game scene
* \author Khalil Baydoun
*/
class ReversiView : public QGraphicsView
{
    Q_OBJECT

public:
    QPushButton*exit,*enterGame,*gameSettings,*howToPlay;
    QLabel *titleLabel;
    ReversiView();
    /**
    * \brief fits the scene inside the view well
    */
    void resizeEvent(QResizeEvent *event);
    /**
    * \param scene the scene to be added to the view
    * \brief sets the game scene inside the view
    */
    void setGameScene(ReversiScene* scene);
    /**
    * \brief main menu of the view
    */
    void MainMenu();


private:

    QPushButton* positionButton(QString buttonText,int ypos);
    ReversiScene *gameScene;

public slots:
    /**
    * \brief does the necessary initializations when the game starts
    */
    void StartGame();
    /**
    * \brief does the necessary deletes and updates when the game ends
    */
    void ExitGame();
    /**
    * \brief shows how the game is played
    */
    void showHelp();

signals:
    /**
    * \brief signal emitted when the game ends
    */
    void gameExited();
};

#endif // REVERSIVIEW_H

