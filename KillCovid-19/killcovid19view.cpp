#include "killcovid19view.h"
#include <Utils/jsonio.h>
/**
* \file killcovid_19view.cpp
* \brief kill covid_19 view class defintion
*
* Contains the iniatialization of the killCovid-19 game view and the implementation of its functions.
* \author Khalil Baydoun
*/

#define ButtonHeight 40
#define ButtonWidth 160
#define ButtonSpacing 30
#define ButtonXPos 300
#define InitialButtonPosition 100

#include <iostream>

KillCovid_19View::KillCovid_19View(){
    this->setFixedSize(750,500);
    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    titleLabel = new QLabel("KILL COVID-19",this);
    titleLabel->setGeometry(ButtonXPos-65,10,500,50);

    QFont titleFont( "Arial", 32, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setAttribute(Qt::WA_TranslucentBackground);
    titleLabel->setStyleSheet("QLabel { color : red; }");

    enterGame = positionButton("Play",InitialButtonPosition);
    gameSettings = positionButton("Game Settings",InitialButtonPosition+ButtonHeight+ButtonSpacing);
    loadMap = positionButton("Load Map",InitialButtonPosition+ButtonHeight*2+2*ButtonSpacing);
    howToPlay = positionButton("How To Play",InitialButtonPosition+ButtonHeight*3+3*ButtonSpacing);
    exit = positionButton("Exit",InitialButtonPosition+ButtonHeight*4+4*ButtonSpacing);

    connect(enterGame, SIGNAL(clicked(bool)), this, SLOT(StartGame()));
    connect(loadMap, SIGNAL(clicked(bool)), this, SLOT(SelectMap()));
    connect(exit, SIGNAL(clicked(bool)), this, SLOT(ExitGame()));
    connect(howToPlay, SIGNAL(clicked(bool)), this, SLOT(showHelp()));
}

QPushButton* KillCovid_19View::positionButton(QString buttonText,int ypos){
    auto button = new QPushButton(buttonText,this);
    button->setObjectName(buttonText);
    button->setGeometry(QRect(ButtonXPos, ypos, ButtonWidth, ButtonHeight));
    return button;
}

void KillCovid_19View::setGameScene(KillCovid_19Scene* scene){
    gameScene = scene;
    this->setScene(scene);
}

void  KillCovid_19View::StartGame(){
    titleLabel->hide();
    howToPlay->hide();
    exit->hide();
    loadMap->hide();
    gameSettings->hide();
    enterGame->hide();
    gameScene->StartGame(virusDescriptors);
}

void KillCovid_19View::ExitGame(){
    emit gameExited();
}

void  KillCovid_19View::MainMenu(){
    titleLabel->show();
    howToPlay->show();
    exit->show();
    loadMap->show();
    gameSettings->show();
    enterGame->show();
    virusDescriptors.clear();
    gameScene->MainMenu();
}


void KillCovid_19View::resizeEvent(QResizeEvent *event){
    QGraphicsView::resizeEvent(event);
    fitInView(sceneRect(), Qt::IgnoreAspectRatio);
}

void  KillCovid_19View::SelectMap(){
    QString fileName = QFileDialog::getOpenFileName(this,"Select Map File", QDir::home().path(), "JSON Files (*.json)");
    QJsonObject map;

    int error_code = JsonIO::readObject(map, fileName);

    virusDescriptors.clear();

    if(error_code == JsonIO::JSON_SUCCESS){
        QJsonArray virusesList = map["viruses_list"].toArray();

        for(auto virusObject : virusesList){
            virusDescriptors.emplace_back(std::vector<int>({virusObject.toObject()["type"].toInt(),
                                                            virusObject.toObject()["x"].toInt(),
                                                            virusObject.toObject()["y"].toInt()}));
        }
        std::cout << "You have successfully loaded map: " << fileName.toStdString() << std::endl;
    }
}

void  KillCovid_19View::showHelp(){
    QMessageBox *messageBox = new QMessageBox();
    messageBox->setWindowTitle("Help");
    messageBox->setText("There are three types of viruses: the small one with a score of three, \n\n \
the medium one with a score of 5 and the large one with a score of 7. \n\n \
You should reach exactly 150 points in order to win the game, and you \n\n \
lose when you miss three shots. Every five viruses killed, the rolling \n\n \
speed of the viruses will get doubled. Shoot the arrow with the space bar\n\n\
key. Enjoy!!");
    messageBox->exec();
}
