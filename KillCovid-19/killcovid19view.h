#ifndef KillCovid_19Scene_H
#define KillCovid_19Scene_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QTimer>

class KillCovid_19View : public QGraphicsView
{
    Q_OBJECT
public:
    QPushButton*exit,*qPushButton2;
    KillCovid_19View();
public slots:

};

#endif // KillCovid_19Scene_H
