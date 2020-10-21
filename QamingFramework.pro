QT += widgets
QT += network
SOURCES += \
    KillCovid-19/killcovid-19scene.cpp \
    accounts/loginwindow.cpp \
    accounts/profilepicturechooser.cpp \
    accounts/registeraccountwindow.cpp \
    Utils/Utils.cpp \
    accounts/user.cpp \
    main/main.cpp \
    main/mainwindow.cpp

HEADERS += \
    KillCovid-19/killcovid-19scene.h \
    accounts/loginwindow.h \
    accounts/profilepicturechooser.h \
    accounts/registeraccountwindow.h \
    Utils/Utils.h \
    accounts/user.h \
    main/mainwindow.h

RESOURCES += \
    res.qrc
