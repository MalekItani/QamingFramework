#include <QApplication>
#include <QPushButton>
#include <main/mainwindow.h>

int main(int argc, char** argv){
    QApplication app(argc, argv);
    mainWindow* window = new mainWindow();
    window->show();
    return app.exec();
};
