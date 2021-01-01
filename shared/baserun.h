#ifndef BASERUN_H
#define BASERUN_H

#include <QString>
#include <QDateTime>

/**
* \file baserun.h
* \brief Header file for the base Run class
* A Run is just an abstract instance of any game. All games should extend
* this class to store additional game-specific characteristics.
* \author Malek Itani
*/

class BaseRun{
public:
    BaseRun();
    /**
    * \brief Initializes a run from its ID.
    * \param id Run ID.
    */
    BaseRun(int id);

    /**
    * \brief Initializes a run from its path in the game subsystem.
    * \param id Run path.
    */
    BaseRun(const QString &path);

    /**
    * \brief Returns run path.
    */
    QString getPath();

    /**
    * \brief Saves a run as a JSON file.
    * Must be overridden by game-specific runs to store game-specific
    * attributes.
    */
    virtual int toJson() = 0;

    /**
    * \brief Initializes a run from a JSON file.
    * Must be overridden by game-specific runs to load game-specific
    * attributes.
    */
    virtual int fromJson() = 0;

    /**
    * \brief Defines a way to evaluate two runs in order to place them on a leaderboard.
    * Must be overridden by game-specific runs to compare game-specific runs
    * that might weigh game attributes differently.
    * \param rhs The other run to compare it with.
    */
    virtual bool lessThan(const BaseRun* rhs) = 0;

    /**
    * \brief Defines how score for this type of Run is computed.
    * Must be overridden by game-specific runs to retrieve a score.
    */
    virtual int getScore() = 0;

    /**
    * \brief Returns the Run ID.
    */
    int getId();

    /**
    * \brief Sets the Run ID.
    * \param _id ID to set.
    */
    void setId(int _id);

    /**
    * \brief Sets the Run path.
    * \param newPath Path to set.
    */
    void setPath(const QString &newPath);

    /**
    * \brief Sets the player name who is associated with this run.
    * \param playerName The new player name.
    */
    void setPlayerName(const QString& playerName);

    /**
    * \brief Sets the datetime at which the run was played.
    * \param dt Datetime to set.
    */
    void setDateTime(const QDateTime& dt);

    /**
    * \brief Returns the player name
    */
    QString getPlayerName();
    /**
    * \brief Returns the datetime
    */
    QDateTime getDateTime();

protected:
    int id;
    QString path;
    QString playerName;
    unsigned long datetime;
};

#endif // BASERUN_H
