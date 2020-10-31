#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <QString>
#include <QtWidgets>

class Utils
{
public:
    Utils();
    static bool IsValidPassword(QString password);
    static bool IsValidName(QString name);
    static QString HashPbdkf1(QString password);
    static bool fileExists(QString path);
    static void Popup(QString errorTitle, QString errorMessage);
    static void delay(int milliSeconds);
};

#endif // USER_H
