#include "mainwindow.h"


mainWindow::mainWindow(QWidget *parent) : QWidget(parent){

    vLayout = new QVBoxLayout();

    vLayout->addItem(new QSpacerItem(1, 32));

    titleLabel = new QLabel("Qaming Framework");
    titleLabel->setAlignment(Qt::AlignCenter);

    QFont titleFont( "Arial", 32, QFont::Bold);
    titleLabel->setFont(titleFont);

    vLayout->addWidget(titleLabel);

    vLayout->addItem(new QSpacerItem(1, 32));

    killCovidGameButton = new QPushButton("Play Kill Covid-19!");
    vLayout->addWidget(killCovidGameButton);

    reversiGameButton = new QPushButton("Play Reversi!");
    vLayout->addWidget(reversiGameButton);

    vLayout->addItem(new QSpacerItem(1, 48));

    logInButton = new QPushButton("Log in to an existing account");
    vLayout->addWidget(logInButton);

    registerButton = new QPushButton("New user? Register a new account!");
    vLayout->addWidget(registerButton);

    vLayout->addItem(new QSpacerItem(1, 64));

    creditsLabel = new QLabel("A Gaming platform written in Qt by Malek Itani and Khalil Baydoun");
    creditsLabel->setAlignment(Qt::AlignCenter);
    vLayout->addWidget(creditsLabel);

    setLayout(vLayout);

}
