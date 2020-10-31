#ifndef KillCovid_19View_H
#define KillCovid_19View_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QTimer>
#include "killcovid19scene.h"

class KillCovid_19View : public QGraphicsView
{
    Q_OBJECT
public:
    QPushButton*exit,*enterGame,*gameSettings,*history,*howToPlay;
    QLabel *titleLabel;
    KillCovid_19Scene * gameScene;
    KillCovid_19View();
    void resizeEvent(QResizeEvent *event);
    //void keyPressEvent(QKeyEvent *event);
private:
    QPushButton* positionButton(QString buttonText,int ypos);
public slots:
    void StartGame();
    void MainMenu();
};

#endif // KillCovid_19View_H
