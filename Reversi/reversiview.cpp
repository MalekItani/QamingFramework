#include "reversiview.h"
#define ButtonHeight 40
#define ButtonWidth 160
#define ButtonSpacing 30
#define ButtonXPos 300
#define InitialButtonPosition 100
/**
* \file reversiview.cpp
* \brief Reversi View class defintion
*
* Contains the iniatialization of the reversi game view and and the implementation of its functions.
* \author Khalil Baydoun
*/



ReversiView::ReversiView()
{
    this->setFixedSize(750,500);
    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    titleLabel = new QLabel("Reversi",this);
    titleLabel->setGeometry(ButtonXPos,10,500,50);
    QFont titleFont( "Arial", 32, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setAttribute(Qt::WA_TranslucentBackground);
    titleLabel->setStyleSheet("QLabel { color : red; }");
    enterGame = positionButton("Play",InitialButtonPosition);
    gameSettings = positionButton("Game Settings",InitialButtonPosition+ButtonHeight+ButtonSpacing);
    howToPlay = positionButton("How To Play",InitialButtonPosition+ButtonHeight*2+2*ButtonSpacing);
    exit = positionButton("Exit",InitialButtonPosition+ButtonHeight*3+3*ButtonSpacing);
    connect(enterGame, SIGNAL(clicked(bool)), this, SLOT(StartGame()));
    connect(exit, SIGNAL(clicked(bool)), this, SLOT(ExitGame()));
    connect(howToPlay, SIGNAL(clicked(bool)), this, SLOT(showHelp()));
}

QPushButton* ReversiView::positionButton(QString buttonText,int ypos){
    auto button = new QPushButton(buttonText,this);
    button->setObjectName(buttonText);
    button->setGeometry(QRect(ButtonXPos, ypos, ButtonWidth, ButtonHeight));
    return button;
}

void ReversiView::setGameScene(ReversiScene* scene){
    gameScene = scene;
    this->setScene(scene);
}

void ReversiView::StartGame(){
    titleLabel->hide();
    howToPlay->hide();
    exit->hide();
    gameSettings->hide();
    enterGame->hide();
    gameScene->StartGame();
}

void ReversiView::ExitGame(){
    emit gameExited();
}

void  ReversiView::MainMenu(){
    titleLabel->show();
    howToPlay->show();
    exit->show();
    gameSettings->show();
    enterGame->show();
    gameScene->MainMenu();
}


void ReversiView::resizeEvent(QResizeEvent *event){
    QGraphicsView::resizeEvent(event);
    fitInView(sceneRect(), Qt::IgnoreAspectRatio);
}


void  ReversiView::showHelp(){
    QMessageBox *messageBox = new QMessageBox();
    messageBox->setWindowTitle("Help");
    messageBox->setText("Press on the cell to place your stone, if the move is not valid a popup will show up. Your stone should outflank some of your"
                        " opponent stones, and if no move is valid, your turn is skipped. The game ends when the 2 players cant make a move, and the player with "
                        "the bigger number of stones wins. Enjoy!");
    messageBox->exec();
}
