#ifndef PlayerDetails_H
#define PlayerDetails_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

#include <accounts/user.h>
#include <shared/gameprofile.h>

/**
* \file killcovid19playerwidget.h
* \brief Header file for the widget that displays username, profile picture and
* general records about the user's history for KillCovid19.
* \author Malek Itani
*/

class KillCovid19PlayerWidget : public QWidget{
    Q_OBJECT
public:
    explicit KillCovid19PlayerWidget(GameProfile *profile);

    GameProfile* gameProfile;

    QLabel *usernameLabel;
    QLabel *previousScoreLabel;
    QLabel *highScoreLabel;

    QGridLayout* layout;

    /**
    * \brief Updates the widget with new user summary changes after a game.
    */
    void update();

};

#endif // PlayerDetails_H
