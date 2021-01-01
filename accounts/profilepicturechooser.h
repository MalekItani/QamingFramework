#ifndef PROFILEPICTURECHOOSER_H
#define PROFILEPICTURECHOOSER_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

/**
* \file profilepicturechooser.h
* \brief A widget that lets users choose their profile picture from their local storage.
* The picture will also be copied and stored within the game files in case the original
* image is later deleted or moved.
* \author Malek Itani
*/

class ProfilePictureChooser : public QWidget
{
    Q_OBJECT
public:
    explicit ProfilePictureChooser(QWidget *parent = nullptr);
    /**
    * \brief Retrieves path of selected picture.
    * \return Empty string if nothing was chosen.
    */
    QString text();
private:
    QHBoxLayout* profilePictureChooserLayout;

    QLabel* profilePictureLabel;
    QLineEdit *profilePictureSelectionLineEdit;

    QPushButton* choosePictureButton;

public slots:
    /**
    * \brief Opens a file chooser to extract the picture's path
    */
    void browsePictures();
signals:
    /**
    * \brief Updates the indicator text once a picture is selected.
    */
    void profilePictureSelected(const QString&);

};

#endif // PROFILEPICTURECHOOSER_H
