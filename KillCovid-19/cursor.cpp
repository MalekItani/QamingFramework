#include "cursor.h"
#include <QtMath>
/**
* \file cursor.cpp
* \brief kill covid_19 cursor class defintion
*
* Contains the iniatialization of the killCovid-19 game cursor and the implementation of its functions.
* \author Khalil Baydoun
*/

Cursor::Cursor(QObject *parent) : QObject(parent)
{
    isShooted=false;
    setPixmap((QPixmap(":KillCovid-19/res/cursor.png")));
    setPos(700,150);
    this->setTransformOriginPoint(65,170);
    QTimer * MoveDownTimer = new QTimer();
    connect(MoveDownTimer, SIGNAL(timeout()), this, SLOT(StartMoving()));
    MoveDownTimer->start(50);

    soundEffect.setSource(QUrl::fromLocalFile(":KillCovid-19/res/shoot_sound.wav"));
    soundEffect.setLoopCount(1);
    soundEffect.setVolume(0.25f);
}

void Cursor::StartMoving(){
    if(!isShooted){
        if(this->rotation()==-90||this->rotation()==0)curRot*=-1;
        this->setRotation(this->rotation()-curRot*2);
    }
}

void Cursor::Shoot(){
    if(isShooted)return;
    isShooted=true;
    soundEffect.play();
    QTimer * MoveDownTimer = new QTimer();
    connect(MoveDownTimer, SIGNAL(timeout()), this, SLOT(ShootHelper()));
    MoveDownTimer->start(1);
}

void Cursor::ShootHelper(){
    qreal slope =tan(qDegreesToRadians(this->rotation()*-1+90));

    this->setPos(this->x()-2,this->y()+slope*2);

    if(this->x()<0||this->y()<-300){
        DeleteCursorFromScene();
    }
}

void Cursor::DeleteCursorFromScene(){
    scene()->removeItem(this);
    delete this;
}



