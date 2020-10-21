#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>

/**
* \file game1scene.h
* \brief Game1Scene class header file
*
* This is the main scene of the game that contains the garbagman object, rubbish objects, and a background image
* \author Khalil Baydoun
*/
class KillCovid_19Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    KillCovid_19Scene(); ///< main scene of the game
public slots:
    void CreateRubbish();
    void DeleteCollidingRubbish();

};

#endif // GAME1SCENE_H
