#include "killcovid19scene.h"

KillCovid_19Scene::KillCovid_19Scene()
{
    this->setBackgroundBrush(QBrush(QImage(":media/killCovidGamePics/coronavirus-blue.jpg").scaledToHeight(500).scaledToWidth(850)));
    this->setSceneRect(0, 0, 850, 500);
}
