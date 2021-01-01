#ifndef GAMEHISTORYWIDGET_H
#define GAMEHISTORYWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>

#include <accounts/user.h>

/**
* \file gamehistorywidget.h
* \brief Header file for a scrollable, tabbed widget that displays the
* history of the users runs for all games, as well as the best
* performance over all users for all games.
* \author Malek Itani
*/

class GameHistoryWidget : public QScrollArea
{
    Q_OBJECT
public:
    explicit GameHistoryWidget(QWidget *parent = nullptr);
    /**
    * \brief Fills the widget with the user's game history.
    * \param user Pointer to the user whose game history should be filled.
    */
    void fill(User *user);
private:
    QTabWidget *tabWidget;
    std::vector<QString> games;

};

#endif // GAMEHISTORYWIDGET_H
