
#include "playerdetails.h"

PlayerDetails::PlayerDetails(KillCovidUser *user)
{
    this->gameUser=user;
    QVBoxLayout* v=new QVBoxLayout();
    v->addWidget(new QLabel("Player: "+ user->username));
    v->addSpacing(50);
    v->addWidget(new QLabel("HIGHSCORE: "+ QString::number(user->highScore)));
    v->addSpacing(50);
    v->addWidget(new QLabel("TOTAL VIRUSES KILLED: "+  QString::number(user->totalVirusesKilled)));
    v->addSpacing(50);
    v->addWidget(new QLabel("TOTAL TIME PLAYED(hrs): "+ QString::number(user->totalTimePlayedInMinutes)));
    v->addSpacing(50);
    v->addWidget(new QLabel("ACURRACY: "+  QString::number(user->accuracy)));
    v->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    v->addSpacing(50);
    this->setLayout(v);
}
