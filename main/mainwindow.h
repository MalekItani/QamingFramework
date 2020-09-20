#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>

#include <accounts/user.h>


class mainWindow : public QWidget{
    Q_OBJECT
public:
    explicit mainWindow(QWidget *parent = nullptr);
private:
    QStackedLayout* activeLayout;

    QWidget* requestLoginPage;
    QWidget* displayGamesPage;

    QVBoxLayout* requestLoginLayout;
    QVBoxLayout* displayGamesLayout;

    QLabel* titleLabel;
    QLabel* creditsLabel;
    QLabel* usernameLabel;
    QLabel* userProfilePicture;

    QPushButton* loginButton;
    QPushButton* logoutButton;
    QPushButton* registerButton;
    QPushButton* killCovidGameButton;
    QPushButton* reversiGameButton;

    QMessageBox* messageBox;

    void buildRequestLoginLayout();
    void buildDisplayGamesLayout();

public slots:
    void openRegisterAccountForm();
    void openLoginForm();
    void updateLayoutWithUserInfo(User*);
    void executeLogout();

signals:
    void swapLayout(int);
    void updateUsernameLabel(const QString&);
    void updateUserProfilePicture(const QPixmap&);
};

#endif // MAINWINDOW_H
