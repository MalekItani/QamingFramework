#include "virus.h"
#include "killcovid19scene.h"
#include "Utils/Utils.h"

Virus::Virus(QString imagePath,int virusType,int score, QObject *parent):QObject(parent)
{
    smashed=false;
    setPixmap((QPixmap(imagePath).scaled(75,75)));
    this->score=score;
    type=virusType;
    QTimer * MoveDownTimer = new QTimer();
    connect(MoveDownTimer, SIGNAL(timeout()), this, SLOT(MoveDown()));
    MoveDownTimer->start(10);
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
    KillCovid_19Scene* gameScene=(KillCovid_19Scene*)scene();
    setPixmap((QPixmap(":KillCovid-19/res/virus_"+gameScene->viruses[type]+"_smashed.png").scaled(75,75)));
    Utils::delay(500);
}

void Virus::DeleteVirusFromScene(){
    scene()->removeItem(this);
    delete this;
}
