#include "killcovid19view.h"

KillCovid_19View::KillCovid_19View()
{
    QGraphicsScene *scene1=new QGraphicsScene();
    scene1->setBackgroundBrush(QBrush(QImage(":media/killCovidGamePics/coronavirus-blue.jpg").scaledToHeight(500).scaledToWidth(850)));
    scene1->setSceneRect(0, 0, 850, 500);
    this->setScene(scene1);
    this->setScene(scene1);
    this->setFixedSize(750,500);
    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    exit = new QPushButton(exit);
    exit->setObjectName(QString::fromUtf8("exit"));
    exit->setGeometry(QRect(280, 140, 115, 32));
}
