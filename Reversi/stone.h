#ifndef STONE_H
#define STONE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include<QKeyEvent>
#include<QtAlgorithms>
/**
* \file Stone.h
* \brief Kill covid 19 virus class header file
* This is the virus that falls in the kill covid 19 game and gets shot by the cursor
* author Khalil Baydoun
*/
class Stone: public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    explicit Stone(bool stoneType, QObject *parent = nullptr);
    bool _stoneType;
    /**
    * \brief flips the color of the stone when it gets outflanked
    */
    void FlipColor();
};

#endif // STONE_H
