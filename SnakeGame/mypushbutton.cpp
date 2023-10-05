#include "mypushbutton.h"

//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    //normal image path
    this->normalImg=normalImg;

    //press image path
    this->pressImg=pressImg;

    QPixmap pix;
    //loag normalImg
    pix.load(normalImg);

    //set fixed size
    this->setFixedSize(pix.width(), pix.height());

    //set style sheet
    this->setStyleSheet("QPushButton{border:0px;}");

    //set icon
    this->setIcon(pix);

    //set icon size
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyPushButton::zoomDown()
{
    //create animation
    QPropertyAnimation* animation=new QPropertyAnimation(this, "geometry");

    //set time gap
    animation->setDuration(200);

    //start
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //end
    animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

    //set animation rules
    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

void MyPushButton::zoomUp()
{
    //create animation
    QPropertyAnimation* animation=new QPropertyAnimation(this, "geometry");

    //set time gap
    animation->setDuration(200);

    //start
    animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //end
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //set animation rules
    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *event)
{
    QPixmap pix;
    //load press img
    pix.load(pressImg);

    //set fixed size
    this->setFixedSize(pix.width(), pix.height());

    //set style sheet
    this->setStyleSheet("QPushButton{border:0px;}");

    //set icon
    this->setIcon(pix);

    //set icon size
    this->setIconSize(QSize(pix.width(), pix.height()));

    //let parent do other thing
    return QPushButton::mousePressEvent(event);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *event)
{

    QPixmap pix;
    //load normal img
    pix.load(normalImg);

    //set fixed size
    this->setFixedSize(pix.width(), pix.height());

    //set style sheet
    this->setStyleSheet("QPushButton{border:0px;}");

    //set icon
    this->setIcon(pix);

    //set icon size
    this->setIconSize(QSize(pix.width(), pix.height()));


    //let parent do other thing
    return QPushButton::mouseReleaseEvent(event);
}
