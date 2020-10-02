QT += widgets
QT += network
SOURCES += \
    accounts/loginwindow.cpp \
    accounts/profilepicturechooser.cpp \
    accounts/registeraccountwindow.cpp \
    Utils/Utils.cpp \
    accounts/user.cpp \
    main/main.cpp \
    main/mainwindow.cpp

HEADERS += \
    accounts/loginwindow.h \
    accounts/profilepicturechooser.h \
    accounts/registeraccountwindow.h \
    Utils/Utils.h \
    accounts/user.h \
    main/mainwindow.h

RESOURCES += \
    res.qrc
