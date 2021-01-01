#include <QApplication>
#include <main/mainwindow.h>
#include <exception>

/**
* \file main.cpp
* \brief QamingFramework entry point. Creates, shows, and ultimately destroys
* the main window.
* \author Malek Itani
*/

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    mainWindow* window = new mainWindow();
    QFile File("../stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    qApp->setStyleSheet(StyleSheet);
    window->show();
    int exitCode= app.exec();
    return exitCode;
};

