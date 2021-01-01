#include "reversiscene.h"
/**
* \file reversiscene.cpp
* \brief Reversi Scene class defintion
*
* Contains the iniatialization of the reversi game scene and and the implementation of its functions.
* \author Khalil Baydoun
*/


#define X0 25
#define Y0 3
#define Xdif 95
#define Ydif 49

ReversiScene::ReversiScene()
{
    this->setSceneRect(0, 0, 750, 400);
    MainMenu();
    stones.resize(8, std::vector<Stone*>(8,nullptr));
    timeUpdateTimer = new QTimer();
}

void ReversiScene::MainMenu(){
    this->setBackgroundBrush(QBrush(QImage(":Reversi/res/mainMenu.jpeg").scaledToHeight(500).scaledToWidth(750)));
}

void ReversiScene::inializeTextItem(QGraphicsTextItem * &item,int x,int y){
    item=new QGraphicsTextItem();
    this->addItem(item);
    item->setPos(x,y);
    item->setFont(QFont( "Arial", 34, QFont::Bold));
    item->hide();
}

void ReversiScene::StartGame(){
    emit scoreUpdate(2, 2);
    gameEnded = false;
    this->setBackgroundBrush(QBrush(QImage(":Reversi/res/board.jpg").scaled(755,393)));
    CreateStone(true,3,3);
    CreateStone(true,4,4);
    CreateStone(false,3,4);
    CreateStone(false,4,3);
    gameEnded=false, turn=false;
    blackCnt=2, whiteCnt=2;
    blackPlayerTimeRemaining=300, whitePlayerTimeRemaining=300;
    inializeTextItem(blackTurn, 270,150);
    blackTurn->setPlainText("Black Turn");
    blackTurn->setDefaultTextColor(QColor(0,0,0));
    inializeTextItem(whiteTurn, 270,150);
    whiteTurn->setPlainText("White Turn");
    whiteTurn->setDefaultTextColor(QColor(255,255,255));
    PrintTurn();
    gameStarted = true;
    timeUpdateTimer =new QTimer();
    connect(timeUpdateTimer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timeUpdateTimer->start(1000);
}

void ReversiScene::UpdateTime(){
    if(gameStarted){
        if(turn){
            whitePlayerTimeRemaining--;
        }
        else blackPlayerTimeRemaining--;
        emit timeUpdate(blackPlayerTimeRemaining,whitePlayerTimeRemaining);
        if(whitePlayerTimeRemaining<=0){
            whiteCnt=-1;
            EndGame();
        }
        if(blackPlayerTimeRemaining<=0){
            blackCnt=-1;
            EndGame();
        }
    }
}

void ReversiScene::CreateStone(bool stoneColor, int xcor, int ycor)//0 black 1 white
{
    if(stones[ycor][xcor]==nullptr){
        stones[ycor][xcor] = new Stone(stoneColor,this);
        stones[ycor][xcor]->setPos(X0+xcor*Xdif, Y0+ycor*Ydif);
        this->addItem(stones[ycor][xcor]);
    }
}

void ReversiScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!gameStarted)return;
    int x=(event->scenePos().x())/Xdif;
    int y=(event->scenePos().y())/Ydif;
    PlayMove(x,y);
}

void ReversiScene::PrintTurn(){
    if(turn){
        whiteTurn->show();
    }
    else {
        blackTurn->show();
    }
    Utils::delay(500);
    whiteTurn->hide();
    blackTurn->hide();
}

void ReversiScene::EndGame(){
    gameEnded = true;
    gameStarted=false;
    QGraphicsTextItem *gameEndText;
    inializeTextItem(gameEndText,200,150);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(stones[i][j]!=nullptr){
                this->removeItem(stones[i][j]);
                delete stones[i][j];
                stones[i][j]=nullptr;
            }
        }
    }
    gameEndText->setDefaultTextColor(QColor(255,255,255));
    if(blackCnt>whiteCnt){
        gameEndText->setPlainText("Black Player Wins!");
    }
    else if (whiteCnt>blackCnt){
        gameEndText->setPlainText("White Player Wins!");
    }
    else {
        gameEndText->setPlainText("Draw!");
    }
    gameEndText->show();
    Utils::delay(3000);
    this->removeItem(gameEndText);
    delete gameEndText;
    delete timeUpdateTimer;
    emit gameOver(new ReversiRun(whiteCnt, blackCnt));
}

bool ReversiScene::CheckVal(int x,int y, bool value){
    if(x<0||y<0||x>7||y>7||stones[y][x]==nullptr)return false;
    return stones[y][x]->_stoneType==value;
}

bool ReversiScene::CheckIfValidMove(int x, int y, bool value){
    if(stones[y][x]!=nullptr)return false;
    bool ans=false;
    for(int k:{-1,0,1}){
        for(int z:{-1,0,1}){
            if(k==0&&z==0)continue;
            ans=ans||(CheckPath(x+k,y+z,k,z,value)>0);
        }
    }
    return ans;
}

int ReversiScene::CheckPath(int xcur, int ycur, int xInc, int yInc, bool value){
    int cnt=0;
    while(xcur>=0&&xcur<8&&ycur>=0&&ycur<8 &&CheckVal(xcur,ycur,!value)){
        xcur+=xInc;
        ycur+=yInc;
        cnt++;
    }
    if(CheckVal(xcur,ycur,value) && cnt>0){
        return cnt;
    }
    else return 0;
}

void ReversiScene::FlipPath(int xcur, int ycur, int xInc, int yInc, bool value){
    while(xcur>=0&&xcur<8&&ycur>=0&&ycur<8 &&CheckVal(xcur,ycur,!value)){
        stones[ycur][xcur]->FlipColor();
        xcur+=xInc;
        ycur+=yInc;
    }
}

bool  ReversiScene::CheckIfThereIsPossibleMove(bool stoneType){
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            if(stones[y][x]==nullptr && CheckIfValidMove(x,y,stoneType)){
                return true;
            }
        }
    }
    return false;
}

void ReversiScene::PlayMove(int x, int y){
    if(!CheckIfValidMove(x,y,turn)){
        Utils::Popup("Invalid Move","This move is invalid, try another position");
        return;
    }
    int totalFlipped=0;
    for(int k:{-1,0,1}){
        for(int z:{-1,0,1}){
            if(k==0&&z==0)continue;
            int flipped=CheckPath(x+k,y+z,k,z,turn);
            totalFlipped +=flipped;
            if (flipped>0){
                FlipPath(x+k,y+z,k,z,turn);
            }
        }
    }
    if(turn){
        whiteCnt+=1+totalFlipped;
        blackCnt-=totalFlipped;
    }
    else {
        blackCnt+=1+totalFlipped;
        whiteCnt-=totalFlipped;
    }
    emit scoreUpdate(blackCnt, whiteCnt);
    CreateStone(turn,x,y);
    turn=!turn;
    if(!CheckIfThereIsPossibleMove(false)&&!CheckIfThereIsPossibleMove(true)){
        EndGame();
        return;
    }
    if(!CheckIfThereIsPossibleMove(turn)){
        Utils::Popup("No possible move", "Turn skipped");
        turn=!turn;
    }
    PrintTurn();
}
