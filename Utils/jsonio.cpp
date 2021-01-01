#include "jsonio.h"

#include <QDir>
#include <QFile>
#include <QJsonDocument>

#include <iostream>


/**
* \file jsonio.cpp
* \brief Definition of static methods that simplify writing and reading to and from JSON files.
* \author Malek Itani
*/

JsonIO::JsonIO(){

}

int JsonIO::writeObject(QJsonObject &object, const QString &path){
    QFile userFile(path);

    QDir dir;
    dir.mkpath(QFileInfo(userFile).dir().path());

    if (!userFile.open(QIODevice::WriteOnly)) return JSON_ERROR;

    QJsonDocument document(object);
    userFile.write(document.toJson());
    userFile.close();

    return JSON_SUCCESS;

}

int JsonIO::readObject(QJsonObject &object, const QString &path){
    QFile userFile(path);

    if (!userFile.open(QIODevice::ReadOnly)) {
        std::cerr << "[WARNING] Could not open file: " << path.toStdString() << std::endl;
        return JSON_ERROR;
    }

    QByteArray data = userFile.readAll();
    userFile.close();
    QJsonDocument loadDoc(QJsonDocument::fromJson(data));
    object = loadDoc.object();

    return JSON_SUCCESS;
}
