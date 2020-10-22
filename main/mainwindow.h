#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>

#include <accounts/user.h>
#include "KillCovid-19/killcovid-19window.h"

class mainWindow : public QWidget{
    Q_OBJECT
public:
    explicit mainWindow(QWidget *parent = nullptr);
private:
    QStackedLayout* activeLayout;
    User*activeUser;
    QWidget* requestLoginPage;
    KillCovid_19Window* KillCovidGameWindow;
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
    QPushButton* editAccountButton;

    QMessageBox* messageBox;

    void buildRequestLoginLayout();
    void buildDisplayGamesLayout();

public slots:
    void openRegisterAccountForm();
    void openLoginForm();
    void updateLayoutWithUserInfo(User*);
    void executeLogout();
    void loginAsGuest();
    void StartKillCovidGame();
    void ShowLayout();

signals:
    void swapLayout(int);
    void updateUsernameLabel(const QString&);
    void updateUserProfilePicture(const QPixmap&);
};

#endif // MAINWINDOW_H
