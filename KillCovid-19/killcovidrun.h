#ifndef KILLCOVIDRUN_H
#define KILLCOVIDRUN_H

#include <shared/baserun.h>
#include <QString>

/**
* \file killcovidrun.h
* \brief Header file for the KillCovid-specific Game Run.
* \author Malek Itani
*/


class KillCovidRun : public BaseRun{
public:
    KillCovidRun();

    /**
    * \brief Initializes the KillCovid run from the total score.
    */
    KillCovidRun(int score);
    KillCovidRun(const QString& path);

    /**
    * \brief Writes the KillCovid-specific run attributes to a JSON file.
    */
    int toJson() override;

    /**
    * \brief Reads the KillCovid-specific run attributes from a JSON file.
    */
    int fromJson() override;

    /**
    * \brief Compares two KillCovid-specific runs.
    */
    bool lessThan(const BaseRun* rhs) override;

    /**
    * \brief Retrieves the run's score.
    */
    int getScore() override;

private:
    int score;
};

#endif // KILLCOVIDRUN_H
