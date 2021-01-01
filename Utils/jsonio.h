#ifndef JSONIO_H
#define JSONIO_H

#include <QJsonObject>

/**
* \file jsonio.h
* \brief A collection of JSON utils to make reading/writing to JSON easier
* \author Malek Itani
*/

class JsonIO
{
public:
    JsonIO();

    /**
    * \brief Writes a JSON object to the desired path.
    * \param object Object to write.
    * \param path Path to write this object to.
    * \return JsonIO::JSON_SUCCESS in case of successful write or JsonIO::JSON_ERROR on failure.
    */
    static int writeObject(QJsonObject &object, const QString& path);

    /**
    * \brief Reads a JSON object from the desired path.
    * \param object Object to read.
    * \param path Path to read this object to.
    * \return JsonIO::JSON_SUCCESS in case of successful write or JsonIO::JSON_ERROR on failure.
    */
    static int readObject(QJsonObject &object, const QString& path);

    const static int JSON_ERROR = 0;
    const static int JSON_SUCCESS = 1;
};

#endif // JSONIO_H
