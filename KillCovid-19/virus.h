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



 class Virus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Virus(QString imagePath,int virusType,int score,QObject *parent = nullptr);
    int score,type;
    bool smashed;
    int getScore();
    void DeleteVirusFromScene();
    void ShowSmashed();
public slots:
    void MoveDown();
};



#endif // VIRUS_H
