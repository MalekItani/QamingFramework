#ifndef KillCovid_19Scene_H
#define KillCovid_19Scene_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>
#include <QtAlgorithms>
#include "cursor.h"
#include "virus.h"
#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include "Utils/Utils.h"


class KillCovid_19Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    QGraphicsTextItem *misses,*smallViruses,*mediumViruses,*largeViruses,*score;
    int missesCnt,scoreCnt,killedVirus=0,virusRollingSpeed;
    int virusesScores[3]={3,5,7};
    int virusesCnts[3]={0,0,0};
    bool gameEnded=false;
    Cursor *cursor;
    Virus *virus;
    QString viruses[3]={"small", "medium", "large"};
    KillCovid_19Scene();
    void StartGame();
    void MainMenu();
    void inializeTextItem(QGraphicsTextItem * &item,int x,int y);
    void FillLabels();
    void EndGame(bool win);
signals:
    void toMainMenu();

public slots:
    void CreateCursor();
    void CreateVirus();
    void DeleteHitVirus();
};

#endif // KillCovid_19Scene_H
