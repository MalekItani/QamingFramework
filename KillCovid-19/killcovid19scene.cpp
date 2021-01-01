#include "killcovid19scene.h"
#include "virus.h"
#include "killcovidrun.h"
#include <QRandomGenerator>
#include <vector>
#include <iostream>
/**
* \file killcovid_19scene.cpp
* \brief kill covid_19 scene class defintion
*
* Contains the iniatialization of the killCovid-19 game scene and the implementation of its functions.
* \author Khalil Baydoun
*/

#define TextItemsSpacing 20
#define TextItemsX 600

KillCovid_19Scene::KillCovid_19Scene()
{
    this->setSceneRect(0, 0, 750, 400);
    MainMenu();
}

void KillCovid_19Scene::MainMenu(){
    this->setBackgroundBrush(QBrush(QImage(":KillCovid-19/res/blueBg.jpg").scaledToHeight(500).scaledToWidth(750)));
}

void KillCovid_19Scene::inializeTextItem(QGraphicsTextItem * &item,int x,int y){
    item=new QGraphicsTextItem();
    this->addItem(item);
    item->setPos(x,y);
    item->setFont(QFont( "Arial", 11, QFont::Bold));
}

void KillCovid_19Scene::StartGame(std::vector<std::vector<int>> &_virusesPostions){
    virusesPostions.clear();
    virusesPostions=_virusesPostions;

    numSpawned = 0;
    gameEnded = false;
    cursor = nullptr;
    virusRollingSpeed = 1;
    missesCnt = scoreCnt = killedVirus = 0;
    virusesCnts[0] = virusesCnts[1] = virusesCnts[2] = 0;

    this->setBackgroundBrush(QBrush(QImage(":KillCovid-19/res/yellowGameBg.jpg").scaledToHeight(500).scaledToWidth(750)));

    CreateVirus();
    CreateCursor();

    QTimer * collisionDetectionTimer = new QTimer();
    connect(collisionDetectionTimer, SIGNAL(timeout()), this, SLOT(DeleteHitVirus()));
    collisionDetectionTimer->start(1);

    inializeTextItem(score,TextItemsX,10);
    score->setDefaultTextColor(QColor(26,141,9));
    inializeTextItem(misses,TextItemsX,10+TextItemsSpacing);
    misses->setDefaultTextColor(QColor(255,35,84));

    inializeTextItem(smallViruses,TextItemsX,10+2*TextItemsSpacing);
    inializeTextItem(mediumViruses,TextItemsX,10+3*TextItemsSpacing);
    inializeTextItem(largeViruses,TextItemsX,10+4*TextItemsSpacing);

    FillLabels();
}

void KillCovid_19Scene::FillLabels(){
    misses->setPlainText("Misses: "+ QString::number(missesCnt));
    smallViruses->setPlainText("Small Viruses: "+ QString::number(virusesCnts[0]));
    mediumViruses->setPlainText("Medium Viruses: "+ QString::number(virusesCnts[1]));
    largeViruses->setPlainText("Large Viruses: "+ QString::number(virusesCnts[2]));
    score->setPlainText("Score: "+ QString::number(scoreCnt));
}

void KillCovid_19Scene::CreateCursor(){
    if(cursor!=nullptr){
        if(killedVirus>0){
            int toadd = Virus(killedVirus-1).getScore();
            if(scoreCnt+toadd<=150)scoreCnt+=toadd;
            virusesCnts[killedVirus-1]++;
            if((virusesCnts[0]+virusesCnts[1]+virusesCnts[2])%5==0){
                if(virusRollingSpeed<16){
                    virusRollingSpeed*=2;
                }
            }
        }
        else {
            missesCnt++;
        }
        FillLabels();
    }

    killedVirus = 0;
    if(scoreCnt == 150){
        EndGame(true);
    }
    else if(missesCnt == 3){
        EndGame(false);
    }
    if(gameEnded)return;
    cursor = new Cursor(this);
    cursor->setFlag(QGraphicsItem::ItemIsFocusable);
    cursor->setFocus();
    this->addItem(cursor);
    connect(cursor, SIGNAL(destroyed()), this, SLOT(CreateCursor()));
    virus->show();
}

void KillCovid_19Scene:: CreateVirus(){
    if(gameEnded)return;

    int xpos, ypos,virusInd;

    if(virusesPostions.size()>0){
        virusInd = virusesPostions[numSpawned][0];
        xpos = virusesPostions[numSpawned][1];
        ypos = virusesPostions[numSpawned][2];
        numSpawned = (numSpawned + 1) % virusesPostions.size();
    }
    else {
        virusInd = QRandomGenerator::global()->generate()%3;
        xpos = QRandomGenerator::global()->generate()%400;
        ypos = QRandomGenerator::global()->generate()%200;
    }
    virus = new Virus(virusInd,this);
    virus->setPos(xpos, ypos);

    this->addItem(virus);
    connect(virus, SIGNAL(destroyed()), this, SLOT(CreateVirus()));
    if(cursor != nullptr){
        if(cursor->isShooted){
            virus->hide();
        }
    }
}

void KillCovid_19Scene::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space){
        cursor->Shoot();
    }
}

void KillCovid_19Scene::EndGame(bool win){
    gameEnded = true;
    QGraphicsTextItem *gameEndText;
    if(win){
        gameEndText = new QGraphicsTextItem("You Win!");
        gameEndText->setDefaultTextColor(QColor(26,141,9));
    }
    else{
        virus->DeleteVirusFromScene();
        gameEndText = new QGraphicsTextItem("You Lose!");
        gameEndText->setDefaultTextColor(QColor(255,35,84));
    }
    this->addItem(gameEndText);

    gameEndText->setPos(270,150);
    gameEndText->setFont(QFont( "Arial", 34, QFont::Bold));

    misses->hide();
    score->hide();
    mediumViruses->hide();
    smallViruses->hide();
    largeViruses->hide();

    Utils::delay(3000);

    this->removeItem(gameEndText);
    delete gameEndText;

    emit gameOver(new KillCovidRun(scoreCnt));
}

void KillCovid_19Scene::DeleteHitVirus(){
    if(gameEnded)return;
    if(virus->smashed)return;
    if(cursor->collidesWithItem(virus)){
        virus->smashed=true;
        killedVirus=virus->type+1;
        virus->ShowSmashed();
        this->removeItem(virus);
        delete virus;
    }
}

