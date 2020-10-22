#include "leaderboard.h"
void fillLeaderboard()
{



}

Leaderboard::Leaderboard()
{
    QVBoxLayout* v=new QVBoxLayout();
//for trial: should be replaced by fillLeaderboard that gets data from the leadboard file
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    highScores.push_back({"KHALIL", "12"});
    fillLeaderboard();
    v->addWidget(new QLabel("LEADERBOARD"));
    v->addSpacing(2);
    v->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    for(auto pair: highScores)
    {
       v->addWidget(new QLabel(pair.first+"  "+pair.second));
       v->addSpacing(20);
    }

    this->setLayout(v);
}


