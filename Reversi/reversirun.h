#ifndef REVERSIRUN_H
#define REVERSIRUN_H

#include <shared/baserun.h>

/**
* \file reversirun.h
* \brief Header file for the Reversi-specific Game Run.
* \author Malek Itani
*/

class ReversiRun : public BaseRun
{
public:
    ReversiRun();

    /**
    * \brief Initializes the Reversi run from the # of black stones & # of white stones.
    */
    ReversiRun(int black, int white);
    ReversiRun(const QString& path);

    /**
    * \brief Defines the way to write the run attributes to JSON.
    */
    int toJson() override;

    /**
    * \brief Defines the way to read the run attributes to JSON.
    */
    int fromJson() override;

    /**
    * \brief Defines the way to compare to Reversi-specific runs.
    */
    bool lessThan(const BaseRun* rhs) override;

    /**
    * \brief Retrieves the number of black stones.
    */
    int getBlackScore();

    /**
    * \brief Retrieves the number of white stones.
    */
    int getWhiteScore();

    /**
    * \brief Retrieves the time taken for player one (blacks) to finish.
    */
    long getTimeTaken();

    /**
    * \brief Retrieves the run score.
    */
    int getScore() override;

private:
    int numBlacks, numWhites;
    long timeTaken;
};

#endif // REVERSIRUN_H
