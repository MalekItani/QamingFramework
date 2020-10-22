#ifndef PlayerDetails_H
#define PlayerDetails_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include<accounts/user.h>
#include "killcoviduser.h"

class PlayerDetails : public QWidget{
    Q_OBJECT
public:
    explicit PlayerDetails(KillCovidUser *user);
    KillCovidUser *gameUser;


public slots:

signals:

};

#endif // PlayerDetails_H
