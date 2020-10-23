#include <QApplication>
#include <main/mainwindow.h>
#include <exception>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    mainWindow* window = new mainWindow();
    QFile File("../QamingFramework/stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    qApp->setStyleSheet(StyleSheet);
    window->show();
    int exitCode= app.exec();
    return exitCode;
};

