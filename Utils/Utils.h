#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <QString>
#include <QtWidgets>
/**
* \file Utils.h
* \brief Utils header file
* Contains helper functions that are freequently used
* \author Khalil Baydoun
*/
class Utils
{
public:
    Utils();
    /**
    * \param password the password to be validated
    * \brief validates that the password satisfies the requirements
    */
    static bool IsValidPassword(QString password);
    /**
    * \param name the name to be validated
    * \brief Checks if the name is valid (latin)
    */
    static bool IsValidName(QString name);
    /**
    * \param password the password to be hashed
    * \brief hashes the password using pbdkf1 hashing algorithm
    */
    static QString HashPbdkf1(QString password);
    /**
    * \param path the file path to be checked
    * \brief checks if a file with the sent path if it exists
    */
    static bool fileExists(QString path);
    /**
    * \param errorTitle the title of the error popup
    * \param errorMessage the error message to be shown in the error popup
    * \brief shows an error popup
    */
    static void Popup(QString errorTitle, QString errorMessage);
    /**
    * \param milliSeconds the number of milli seconds to be delayed
    * \brief delays the app for a certain amount of time
    */
    static void delay(int milliSeconds);
};

#endif // USER_H
