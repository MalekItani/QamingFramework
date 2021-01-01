#ifndef CURSOR_H
#define CURSOR_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include<QKeyEvent>
#include<QtAlgorithms>
#include <QSoundEffect>
/**
* \file Cursor.h
* \brief Kill covid 19 cursor class header file
* This is the cursor that is shot in the kill covid 19 game
* author Khalil Baydoun
*/
class Cursor : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Cursor(QObject *parent = nullptr);
    /**
    * \brief shoots the cursor in the direction it is pointing at when the space key is pressed
    */
    void Shoot();
    /**
    * \brief rebases the cursor
    */
    void Rebase();
    int  curRot=-1;
    bool isShooted=false;
    /**
    * \brief deletes the cursor when the game ends or when the cursor gets out of bounds
    */
    void DeleteCursorFromScene();

private:
    QSoundEffect soundEffect;


public slots:
    /**
    * \brief starts the rotation of the cursor
    */
    void StartMoving();
    /**
    * \brief helper function for the shooting of the cursor
    */
    void ShootHelper();
};



#endif // CURSOR_H
