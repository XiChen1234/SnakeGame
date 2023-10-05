#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QPropertyAnimation>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);

    //press image is empty path, if it is lack of the second path, there is no press animaltion
    MyPushButton(QString normalImg, QString pressImg="");

    QString normalImg;
    QString pressImg;

    void zoomDown();
    void zoomUp();

    //press event
    void mousePressEvent(QMouseEvent* event);

    //releaes event
    void mouseReleaseEvent(QMouseEvent* event);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
