#ifndef VIRUS_H
#define VIRUS_H

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
* \file Virus.h
* \brief Kill covid 19 virus class header file
* This is the virus that falls in the kill covid 19 game and gets shot by the cursor
* author Khalil Baydoun
*/
 class Virus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    const int scores[3]={3,5,7};
    const QString names[3]={"small", "medium", "large"};

    explicit Virus(int virusType, QObject *parent = nullptr);
    /**
    * \brief gets the score rewarded when the virus is shot
    */
    int getScore();
    /**
    * \brief deletes the virus when its shot, or gets out of bounds, or the game ends
    */
    void DeleteVirusFromScene();
    /**
    * \brief changes the virus the image to be smashed when its shot
    */
    void ShowSmashed();
    int score,type;
    bool smashed;

private:
    QSoundEffect soundEffect;

public slots:
    /**
    * \brief moves the virus down
    */
    void MoveDown();
};



#endif // VIRUS_H
