#include <QApplication>
#include <main/mainwindow.h>
#include <exception>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    mainWindow* window = new mainWindow();

    window->show();
    int exitCode= app.exec();
    return exitCode;
};

