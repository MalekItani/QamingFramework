#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <accounts/user.h>
#include <KillCovid-19/killcovid-19window.h>
#include "gamehistorywidget.h"
#include "Reversi/reversiwindow.h"

/**
* \file mainwindow.h
* \brief The main window that will be used by the user to login, logout, register or play games.
* The user can also browse his/her history and scores for all the games.
* \author Malek Itani
*/

class mainWindow : public QWidget{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);

private:
    QStackedLayout* activeLayout;
    User*activeUser;
    QWidget* requestLoginPage;
    KillCovid_19Window* KillCovidGameWindow;
    ReversiWindow* ReversiGameWindow;
    QWidget* displayGamesPage;

    QVBoxLayout* requestLoginLayout;
    QVBoxLayout* displayGamesLayout;
    QHBoxLayout* userDisplayLayout;

    QLabel* titleLabel;
    QLabel* creditsLabel;
    QLabel* usernameLabel;
    QLabel* userProfilePicture;

    QPushButton* playAsGuestButton;
    QPushButton* loginButton;
    QPushButton* logoutButton;
    QPushButton* registerButton;
    QPushButton* killCovidGameButton;
    QPushButton* reversiGameButton;

    QMessageBox* messageBox;

    GameHistoryWidget* gameHistoryWidget;

    /**
    * \brief Builds the layout for the login page of the main window.
    */
    void buildRequestLoginLayout();
    /**
    * \brief Builds the layout for the games display page of the main window.
    */
    void buildDisplayGamesLayout();

public slots:
    /**
    * \brief Opens the registration window for new users to create accounts.
    */
    void openRegisterAccountForm();

    /**
    * \brief Opens the login window for returning users to login to their accounts.
    */
    void openLoginForm();

    /**
    * \brief Updates the layout with a specific user's info once they have logged in.
    * \param user Pointer to the user to update the layout with.
    */
    void updateLayoutWithUserInfo(User* user);

    /**
    * \brief Logs the user out.
    */
    void executeLogout();

    /**
    * \brief Logs the user as the default (Guest) user.
    */
    void loginAsGuest();

    /**
    * \brief Launches the KillCovid19 game.
    */
    void StartKillCovidGame();

    /**
    * \brief Launches the Reversie game.
    */
    void StartReversiGame();

    /**
    * \brief Performs post-game functionality for KillCovid19.
    */
    void onKillCovid19Finish();

    /**
    * \brief Performs post-game functionality for Reversi.
    */
    void onReversiFinish();

signals:
    /**
    * \brief Swaps between login layout and games display layout.
    */
    void swapLayout(int);

    /**
    * \brief Updates the username label.
    * \param username Username to place on the label.
    */
    void updateUsernameLabel(const QString& username);

    /**
    * \brief Updates the displayed picture for the user.
    * \param pixmap The pixmap for the user's picture.
    */
    void updateUserProfilePicture(const QPixmap& pixmap);
};

#endif // MAINWINDOW_H
