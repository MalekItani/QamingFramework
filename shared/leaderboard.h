#ifndef Leaderboard_H
#define Leaderboard_H

#include "baserun.h"
#include<Utils/jsonio.h>
#include <QJsonObject>
#include <QJsonArray>

#include <set>

/**
* \file leaderboard.h
* \brief Header file for the Leaderboard class
* A Leaderboard is an ordered datastructure that maintains an ordering
* among all runs for some specific game.
* \author Malek Itani
*/


class comparator{
public:
    bool operator()(BaseRun* run1, BaseRun* run2) const;
};

class Leaderboard : public std::set<BaseRun*, comparator>{

public:
    Leaderboard();

    /**
    * \brief Builds the leaderboard of a certain type of run.
    * \param RunType The type of BaseRun that the profile should use.
    * This should be a Run class that inherits from BaseRun.
    * \param gameBasePath The path to where the specific game files are located.
    * \param size Maximum size of the leaderboard.
    */
    template<typename RunType>
    static Leaderboard* build(const QString &gameBasePath, int size){
        Leaderboard* leaderboard = new Leaderboard(gameBasePath, size);
        leaderboard->fromJson<RunType>();
        return leaderboard;
    }


    /**
    * \brief Attempts to add a Run to the Leaderboard.
    * \param run The Run to add.
    * \return true if the Run is good enough to place on the Leaderboard.
    */
    bool addRun(BaseRun* run);

    /**
    * \brief Saves a Leaderboard to the framework subsystem
    */
    void save();

private:
    /**
    * \brief Writes Leaderboard to a JSON file.
    */
    int toJson();
    Leaderboard(const QString &gameBasePath, int size);

    /**
    * \brief Reads Leaderboard from a JSON file.
    */
    template<typename RunType>
    int fromJson(){
        QJsonObject leaderboardObject;
        int errorCode = JsonIO::readObject(leaderboardObject, path);

        if(errorCode != JsonIO::JSON_SUCCESS) return errorCode;

        QJsonArray array = leaderboardObject["leaderboard"].toArray();

        foreach (const QJsonValue & v, array){
            if((int) this->size() == maxSize) break;
            RunType *run = new RunType(v.toString());
            run->fromJson();
            insert((BaseRun*) run);
        }

        return JsonIO::JSON_SUCCESS;
    }

    QString path;
    int maxSize;
};

#endif // Leaderboard_H
