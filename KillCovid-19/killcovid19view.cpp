
#include "killcovid19view.h"
#define ButtonHeight 40
#define ButtonWidth 160
#define ButtonSpacing 30
#define ButtonXPos 300
#define InitialButtonPosition 100
KillCovid_19View::KillCovid_19View()
{
    gameScene=new KillCovid_19Scene();
    this->setScene(gameScene);
    auto titleLabel = new QLabel("KILL COVID-19",this);
    titleLabel->setGeometry(ButtonXPos-65,10,500,50);
    QFont titleFont( "Arial", 32, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setAttribute(Qt::WA_TranslucentBackground);
    titleLabel->setStyleSheet("QLabel { color : red; }");
    this->setFixedSize(750,500);
    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    enterGame=positionButton("Play",InitialButtonPosition);
    gameSettings=positionButton("Game Settings",InitialButtonPosition+ButtonHeight+ButtonSpacing);
    history=positionButton("History",InitialButtonPosition+ButtonHeight*2+2*ButtonSpacing);
    howToPlay=positionButton("How To Play",InitialButtonPosition+ButtonHeight*3+3*ButtonSpacing);
    exit=positionButton("Exit",InitialButtonPosition+ButtonHeight*4+4*ButtonSpacing);
}


QPushButton* KillCovid_19View::positionButton(QString buttonText,int ypos)
{
    auto button = new QPushButton(buttonText,this);
    button->setObjectName(buttonText);
    button->setGeometry(QRect(ButtonXPos, ypos, ButtonWidth, ButtonHeight));
    return button;
}



