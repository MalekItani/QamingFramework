#include "profilepicturechooser.h"

/**
* \file profilepicturechooser.cpp
* \brief The implementation of the ProfilePictureChooser
* \author Malek Itani
*/

ProfilePictureChooser::ProfilePictureChooser(QWidget *parent) : QWidget(parent){

    profilePictureChooserLayout = new QHBoxLayout();

    profilePictureLabel = new QLabel("Profile Picture (Optional)");
    profilePictureChooserLayout->addWidget(profilePictureLabel);

    profilePictureChooserLayout->addItem(new QSpacerItem(8, 1));
    profilePictureSelectionLineEdit = new QLineEdit();
    profilePictureSelectionLineEdit->setFixedSize(QSize(256, 32));
    profilePictureSelectionLineEdit->setReadOnly(true);
    profilePictureChooserLayout->addWidget(profilePictureSelectionLineEdit);

    profilePictureChooserLayout->addItem(new QSpacerItem(8, 1));

    choosePictureButton = new QPushButton("Choose...");
    profilePictureChooserLayout->addWidget(choosePictureButton);

    setLayout(profilePictureChooserLayout);

    QObject::connect(choosePictureButton, SIGNAL(clicked(bool)), this, SLOT(browsePictures()));
    QObject::connect(this, SIGNAL(profilePictureSelected(const QString&)), profilePictureSelectionLineEdit, SLOT(setText(const QString&)));
}

void ProfilePictureChooser::browsePictures(){
    QString fileName = QFileDialog::getOpenFileName(this,"Select Image", QDir::home().path(), "Image Files (*.png *.jpg *.bmp)");
    emit profilePictureSelected(fileName);
}

QString ProfilePictureChooser::text(){
    return profilePictureSelectionLineEdit->text();
}
