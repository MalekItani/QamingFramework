#ifndef REVERSIPLAYERWIDGET_H
#define REVERSIPLAYERWIDGET_H

#include <accounts/user.h>
#include <shared/gameprofile.h>
#include <QObject>
#include <QWidget>
#include <QtWidgets>

/**
* \file reversiplayerwidget.h
* \brief Header file for the widget that displays username, profile picture and
* general records about the user's history for Reversi.
* \author Malek Itani
*/

class ReversiPlayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReversiPlayerWidget(GameProfile *profile);

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

#endif
