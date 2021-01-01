#ifndef Leaderboard_H
#define Leaderboard_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include<accounts/user.h>


class Leaderboard : public QWidget{
    Q_OBJECT
public:
    explicit Leaderboard();
private:
    QVBoxLayout* layout;
    QVector<QPair<QString,QString>>highScores;

public slots:

signals:

};

#endif // Leaderboard_H
