QT += widgets
QT += network
SOURCES += \
    KillCovid-19/killcovid-19window.cpp \
    KillCovid-19/killcovid19scene.cpp \
    KillCovid-19/killcovid19view.cpp \
    KillCovid-19/killcoviduser.cpp \
    KillCovid-19/leaderboard.cpp \
    KillCovid-19/playerdetails.cpp \
    accounts/loginwindow.cpp \
    accounts/profilepicturechooser.cpp \
    accounts/registeraccountwindow.cpp \
    Utils/Utils.cpp \
    accounts/user.cpp \
    main/main.cpp \
    main/mainwindow.cpp

HEADERS += \
    KillCovid-19/killcovid-19window.h \
    KillCovid-19/killcovid19scene.h \
    KillCovid-19/killcovid19view.h \
    KillCovid-19/killcoviduser.h \
    KillCovid-19/leaderboard.h \
    KillCovid-19/playerdetails.h \
    accounts/loginwindow.h \
    accounts/profilepicturechooser.h \
    accounts/registeraccountwindow.h \
    Utils/Utils.h \
    accounts/user.h \
    main/mainwindow.h

RESOURCES += \
    res.qrc
