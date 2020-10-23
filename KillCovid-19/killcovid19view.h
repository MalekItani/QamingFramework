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

class KillCovid_19View : public QGraphicsView
{
    Q_OBJECT
public:
    QPushButton*exit,*enterGame,*gameSettings,*history,*howToPlay;
    KillCovid_19Scene * gameScene;
    KillCovid_19View();
private:
    QPushButton* positionButton(QString buttonText,int ypos);
public slots:

};

#endif // KillCovid_19View_H
