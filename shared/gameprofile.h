#ifndef GAMEPROFILE_H
#define GAMEPROFILE_H

#include "leaderboard.h"
#include <memory>
#include <QJsonObject>
#include <Utils/jsonio.h>
#include <accounts/user.h>

/**
* \file gameprofile.h
* \brief Header file for the GameProfile class
* A game profile is a summary of the user's game history for the current
* game. It also contains a leaderboard for all runs.
* \author Malek Itani
*/


class GameProfile
{
public:
    GameProfile();

    /**
    * \brief Builds the game profile for the current user for a given game.
    * \param RunType The type of BaseRun that the profile should use.
    * This should be a Run class that inherits from BaseRun.
    * \param gameBasePath The path to where the specific game files are located.
    * \param user Pointer to the user whose profile should be built.
    */
    template <typename RunType>
    static GameProfile* build(const QString& gameBasePath, User *user){
        GameProfile* profile = new GameProfile();
        profile->leaderboard = Leaderboard::build<RunType>(gameBasePath, 20);
        profile->user = user;
        profile->path = gameBasePath + "/user_data/" + user->getUsername();
        profile->gamesPlayed = 0;
        profile->lastRun = NULL;
        profile->bestRun = NULL;
        profile->fromJSON<RunType>();
        return profile;
    }

    /**
    * \brief Inserts a run into the user's profile.
    * \param run Pointer to the run that should be added.
    */
    void addRun(BaseRun* run);

    /**
    * \brief Saves the user's current GameProfile to a JSON file.
    */
    void save();

    /**
    * \brief Returns the game's Leaderboard.
    */
    Leaderboard* getLeaderboard();

    /**
    * \brief Returns the current user's best Run.
    */
    BaseRun* getBestRun();

    /**
    * \brief Returns the current user's last Run.
    */
    BaseRun* getLastRun();

    /**
    * \brief Returns the number of games the user has played.
    */
    int getNumberOfGamesPlayed();

    /**
    * \brief Returns the user associated with this Game Profile.
    */
    User* getUser();

private:
    QString path;

    Leaderboard* leaderboard;

    int gamesPlayed;

    User* user;

    BaseRun* bestRun;
    BaseRun* lastRun;

    /**
    * \brief Writes the Game Profile to a JSON file.
    */
    int toJSON();

    /**
    * \brief Reads the Game Profile from a JSON file.
    */
    template <typename RunType>
    int fromJSON(){
        QJsonObject gameProfile;
        int errorCode = JsonIO::readObject(gameProfile, path + "/profile.json");

        this->gamesPlayed = gameProfile["games_played"].toInt();

        int lastRunId = gameProfile["last_run"].toInt();
        this->lastRun = new RunType(path + "/" + QString::number(lastRunId) + ".json");
        this->lastRun->setId(lastRunId);
        this->lastRun->fromJson();

        int bestRunId = gameProfile["best_run"].toInt();
        this->bestRun = new RunType(path + "/" + QString::number(bestRunId) + ".json");
        this->bestRun->setId(bestRunId);
        this->bestRun->fromJson();

        return errorCode;
    }
};

#endif // GAMEPROFILE_H
