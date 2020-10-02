#ifndef PROFILEPICTURECHOOSER_H
#define PROFILEPICTURECHOOSER_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class ProfilePictureChooser : public QWidget
{
    Q_OBJECT
public:
    explicit ProfilePictureChooser(QWidget *parent = nullptr);
    QString text();
private:
    QHBoxLayout* profilePictureChooserLayout;

    QLabel* profilePictureLabel;
    QLineEdit *profilePictureSelectionLineEdit;

    QPushButton* choosePictureButton;

public slots:
    void browsePictures();
signals:
    void profilePictureSelected(const QString&);

};

#endif // PROFILEPICTURECHOOSER_H
