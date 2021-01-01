#ifndef KillCovid_19View_H
#define KillCovid_19View_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QTimer>
#include "killcovid19scene.h"
#include "virus.h"
/**
* \file killcovid19view.h
* \brief Kill covid 19 view class header file
* This is the main view of the kill covid 19 game that contains the game scene
* author Khalil Baydoun
*/


class KillCovid_19View : public QGraphicsView
{
    Q_OBJECT
public:
    QPushButton*exit,*enterGame,*gameSettings,*loadMap,*howToPlay;
    QLabel *titleLabel;
    /**
    * \brief constructor of the kill covid 19 view
    */
    KillCovid_19View();
    /**
    * \brief fits the scene as required inside the view
    */
    void resizeEvent(QResizeEvent *event);
    /**
    * \param scene the scene to be added to the view
    * \brief sets the game scene inside the view
    */
    void setGameScene(KillCovid_19Scene* scene);
    /**
    * \brief initializes the main menu of the game
    */
    void MainMenu();

private:
    QPushButton* positionButton(QString buttonText,int ypos);

    KillCovid_19Scene *gameScene;

    std::vector<std::vector<int> > virusDescriptors;

public slots:
    /**
    * \brief starts the game when the start game button is pressed
    */
    void StartGame();
    /**
    * \brief exits the game when the game ends
    */
    void ExitGame();
    /**
    * \brief sets the map with the location of the falling viruses
    */
    void SelectMap();
    /**
    * \brief shows a general description of the game and how its played when the show help button is pressed
    */
    void showHelp();

signals:
    /**
    * \brief the signal that is emitted when the game finishes
    */
    void gameExited();

};

#endif // KillCovid_19View_H
