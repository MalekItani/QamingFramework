#include "virus.h"
#include "killcovid19scene.h"
#include "Utils/Utils.h"
/**
* \file virus.cpp
* \brief kill covid_19 virus class defintion
*
* Contains the iniatialization of the killCovid-19 game virus and the implementation of its functions.
* \author Khalil Baydoun
*/

Virus::Virus(int virusType, QObject *parent):QObject(parent){
    smashed=false;

    QString imagePath = ":KillCovid-19/res/virus_"+names[virusType]+".png";
    int score = scores[virusType];

    setPixmap((QPixmap(imagePath).scaled(75,75)));
    this->score=score;
    type=virusType;
    QTimer * MoveDownTimer = new QTimer();
    connect(MoveDownTimer, SIGNAL(timeout()), this, SLOT(MoveDown()));
    MoveDownTimer->start(10);

    soundEffect.setSource(QUrl::fromLocalFile(":KillCovid-19/res/squish_sound.wav"));
    soundEffect.setLoopCount(1);
    soundEffect.setVolume(1.0f);
}

void Virus::MoveDown(){
    if(smashed)return;
    KillCovid_19Scene* gameScene=(KillCovid_19Scene*)scene();
    setPos(x(),y()+0.13*gameScene->virusRollingSpeed);
    if(y()+0.13*gameScene->virusRollingSpeed>scene()->height()){
        DeleteVirusFromScene();
    }
}

void Virus::ShowSmashed(){
    setPixmap((QPixmap(":KillCovid-19/res/virus_"+names[type]+"_smashed.png").scaled(75,75)));
    soundEffect.play();
    Utils::delay(500);
}

void Virus::DeleteVirusFromScene(){
    scene()->removeItem(this);
    delete this;
}

int Virus::getScore(){
    return score;
}
