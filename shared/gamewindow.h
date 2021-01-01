#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QObject>
#include <QWidget>

#include "gameprofile.h"

/**
* \file gamewindow.h
* \brief Header file for the GameWindow base class
* A game window is the window each game will use to display the game scene, game
* stats, or other game-specific widgets
* \author Malek Itani
*/

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);

    GameProfile* gameProfile;

public slots:
    /**
    * \brief Closes the game safely after saving the current Game Profile
    * Emits a windowClosed() signal.
    */
    void exit();

signals:
    /**
    * \brief Signal taht is emitted whent he gameWindow is closed. It is used to update
    * the history tabs in the main window.
    */
    void windowClosed();

};

#endif // GAMEWINDOW_H
