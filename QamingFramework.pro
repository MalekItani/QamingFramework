QT += widgets
QT += network
QT += multimedia

SOURCES += \
    KillCovid-19/killcovidrun.cpp \
    KillCovid-19/cursor.cpp \
    KillCovid-19/killcovid-19window.cpp \
    KillCovid-19/killcovid19scene.cpp \
    KillCovid-19/killcovid19view.cpp \
    KillCovid-19/killcovid19leaderboardwidget.cpp\
    KillCovid-19/killcovid19playerwidget.cpp\
    KillCovid-19/virus.cpp \
    Reversi/reversiplayerwidget.cpp \
    Reversi/reversirun.cpp \
    Reversi/reversiscene.cpp \
    Reversi/reversistatswidget.cpp \
    Reversi/reversiview.cpp \
    Reversi/reversiwindow.cpp \
    Reversi/stone.cpp \
    Utils/jsonio.cpp \
    accounts/loginwindow.cpp\
    accounts/profilepicturechooser.cpp \
    accounts/registeraccountwindow.cpp \
    Utils/Utils.cpp \
    accounts/user.cpp \
    main/gamehistorywidget.cpp \
    main/main.cpp \
    main/mainwindow.cpp \
    shared/baserun.cpp \
    shared/gameprofile.cpp \
    shared/gamewindow.cpp \
    shared/leaderboard.cpp

HEADERS += \
    KillCovid-19/cursor.h \
    KillCovid-19/killcovid-19window.h \
    KillCovid-19/killcovid19scene.h \
    KillCovid-19/killcovid19view.h \
    KillCovid-19/killcovid19leaderboardwidget.h\
    KillCovid-19/killcovid19playerwidget.h\
    KillCovid-19/virus.h \
    KillCovid-19/killcovidrun.h \
    Reversi/reversiplayerwidget.h \
    Reversi/reversirun.h \
    Reversi/reversiscene.h \
    Reversi/reversistatswidget.h \
    Reversi/reversiview.h \
    Reversi/reversiwindow.h \
    Reversi/stone.h \
    Utils/jsonio.h \
    accounts/loginwindow.h \
    accounts/profilepicturechooser.h \
    accounts/registeraccountwindow.h \
    Utils/Utils.h \
    accounts/user.h \
    main/gamehistorywidget.h \
    main/mainwindow.h \
    shared/baserun.h \
    shared/gameprofile.h \
    shared/gamewindow.h \
    shared/leaderboard.h

RESOURCES += \
    res.qrc

DESTDIR = $$PWD/build
OBJECTS_DIR = $$PWD/build
MOC_DIR = $$PWD/build
QMAKE_MAKEFILE = Makefile2

