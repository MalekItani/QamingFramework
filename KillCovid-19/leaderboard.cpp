#include "leaderboard.h"
void fillLeaderboard()
{
    //todo: get leaderboard from file


}

Leaderboard::Leaderboard()
{
    QVBoxLayout* v=new QVBoxLayout();
//for trial: should be replaced by fillLeaderboard that gets data from the leadboard file
    QString spaces="            ";
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
    auto titleLabel=new QLabel("<h2>LEADERBOARD<h2>");
    v->addWidget(titleLabel);
    v->addSpacing(2);
    v->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    for(auto pair: highScores)
    {
       v->addWidget(new QLabel(pair.first+spaces+pair.second));
       v->addSpacing(20);
    }

    this->setLayout(v);
}


