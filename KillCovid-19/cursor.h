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



class Cursor : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Cursor(QObject *parent = nullptr);
    void Shoot();
    void Rebase();
    void keyPressEvent(QKeyEvent *event);
    int  curRot=-1;
    bool isShooted=false;
    void DeleteCursorFromScene();
public slots:
    void StartMoving();
    void ShootHelper();
};



#endif // CURSOR_H
