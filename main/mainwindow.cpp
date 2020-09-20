#include "mainwindow.h"
#include <accounts/registeraccountwindow.h>
#include <accounts/loginwindow.h>
#include <accounts/user.h>

#include <iostream>

mainWindow::mainWindow(QWidget *parent) : QWidget(parent){

    buildRequestLoginLayout();
    buildDisplayGamesLayout();

    activeLayout = new QStackedLayout();
    activeLayout->addWidget(requestLoginPage);
    activeLayout->addWidget(displayGamesPage);

    setLayout(activeLayout);

    QObject::connect(this, SIGNAL(swapLayout(int)), activeLayout, SLOT(setCurrentIndex(int)));

    emit swapLayout(0);
}

// ================================================================================================================================
//                                                             LAYOUTS
// ================================================================================================================================

void mainWindow::buildRequestLoginLayout(){
    requestLoginLayout = new QVBoxLayout();

    requestLoginLayout->addItem(new QSpacerItem(1, 32));

    titleLabel = new QLabel("Qaming Framework");
    titleLabel->setAlignment(Qt::AlignCenter);

    QFont titleFont( "Arial", 32, QFont::Bold);
    titleLabel->setFont(titleFont);

    requestLoginLayout->addWidget(titleLabel);

    requestLoginLayout->addItem(new QSpacerItem(1, 48));

    loginButton = new QPushButton("Log in to an existing account");
    requestLoginLayout->addWidget(loginButton);

    registerButton = new QPushButton("New user? Register a new account!");
    requestLoginLayout->addWidget(registerButton);

    requestLoginLayout->addItem(new QSpacerItem(1, 64));

    creditsLabel = new QLabel("A Gaming platform written in Qt by Malek Itani and Khalil Baydoun");
    creditsLabel->setAlignment(Qt::AlignCenter);
    requestLoginLayout->addWidget(creditsLabel);

    requestLoginPage = new QWidget();
    requestLoginPage->setLayout(requestLoginLayout);

    QObject::connect(registerButton, SIGNAL(clicked(bool)), this, SLOT(openRegisterAccountForm()));
    QObject::connect(loginButton, SIGNAL(clicked(bool)), this, SLOT(openLoginForm()));
}


void mainWindow::buildDisplayGamesLayout(){
    displayGamesLayout = new QVBoxLayout();

    displayGamesLayout->addItem(new QSpacerItem(1, 32));

    titleLabel = new QLabel("Qaming Framework");
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont( "Arial", 32, QFont::Bold);
    titleLabel->setFont(titleFont);

    displayGamesLayout->addWidget(titleLabel);

    userProfilePicture = new QLabel();
    userProfilePicture->setAlignment(Qt::AlignCenter);
    displayGamesLayout->addWidget(userProfilePicture);

    usernameLabel = new QLabel();
    usernameLabel->setAlignment(Qt::AlignCenter);
    QFont usernameFont( "Arial", 18, QFont::Bold);
    usernameLabel->setFont(usernameFont);
    displayGamesLayout->addWidget(usernameLabel);

    displayGamesLayout->addItem(new QSpacerItem(1, 32));

    killCovidGameButton = new QPushButton("Play Kill Covid-19!");
    displayGamesLayout->addWidget(killCovidGameButton);

    reversiGameButton = new QPushButton("Play Reversi!");
    displayGamesLayout->addWidget(reversiGameButton);

    requestLoginLayout->addItem(new QSpacerItem(1, 48));

    logoutButton = new QPushButton("Log out");
    displayGamesLayout->addWidget(logoutButton);

    displayGamesLayout->addItem(new QSpacerItem(1, 64));

    creditsLabel = new QLabel("A Gaming platform written in Qt by Malek Itani and Khalil Baydoun");
    creditsLabel->setAlignment(Qt::AlignCenter);
    displayGamesLayout->addWidget(creditsLabel);

    displayGamesPage = new QWidget();
    displayGamesPage->setLayout(displayGamesLayout);

    QObject::connect(this, SIGNAL(updateUsernameLabel(const QString&)), usernameLabel, SLOT(setText(const QString&)));
    QObject::connect(this, SIGNAL(updateUserProfilePicture(const QPixmap&)), userProfilePicture, SLOT(setPixmap(const QPixmap&)));
    QObject::connect(logoutButton, SIGNAL(clicked(bool)), this, SLOT(executeLogout()));
}

// ================================================================================================================================
//                                                              SLOTS
// ================================================================================================================================
void mainWindow::openRegisterAccountForm(){
    registerAccountWindow *window = new registerAccountWindow();
    QObject::connect(window, SIGNAL(userApproved(User*)), this, SLOT(updateLayoutWithUserInfo(User*)));
    window->show();
}

void mainWindow::openLoginForm(){
    loginWindow *window = new loginWindow();
    QObject::connect(window, SIGNAL(userApproved(User*)), this, SLOT(updateLayoutWithUserInfo(User*)));
    window->show();
}

void mainWindow::updateLayoutWithUserInfo(User* user){
    if(user){
        QString username = user->getUsername();
        emit updateUsernameLabel(username);

        QPixmap pixmap("../QamingFramework/" + user->getProfilePicturePath());
        pixmap = pixmap.scaled(96, 96,Qt::KeepAspectRatio);
        userProfilePicture->setPixmap(pixmap);
        emit updateUserProfilePicture(pixmap);

        emit swapLayout(1);

        messageBox = new QMessageBox();
        messageBox->setWindowTitle("Greetings");
        if(user->getDateOfBirth().month() == QDate::currentDate().month() && user->getDateOfBirth().day() == user->getDateOfBirth().day()){
            messageBox->setText("Welcome back, " + user->getFirstName() + " " + user->getLastName() + "!");
        }else{
            messageBox->setText("Happy Birthday, " + user->getFirstName() + " " + user->getLastName() + "!");
        }
        messageBox->exec();
    }
}

void mainWindow::executeLogout(){
    emit swapLayout(0);
}
