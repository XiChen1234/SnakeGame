#include "myapple.h"

//MyApple::MyApple(QWidget *parent) : QWidget(parent)
//{

//}

MyApple::MyApple(bool poisonous)
{
    this->poisonous=poisonous;

    this->setFixedSize(width, height);

    addApple();
}

//add an apple
void MyApple::addApple()
{
//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int randomX=qrand()%(width/20);
    int randomY=qrand()%(height/20);
    apple=QRectF(randomX*20, randomY*20, node, node);
}

//get the rectF of apple
QRectF MyApple::getApple()
{
     return QRectF(apple.x(), apple.y(), node, node);
}

void MyApple::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen pen;
    //clear the border
    pen.setColor(Qt::transparent);
    painter.setPen(pen);
    if(poisonous)
    {
        QImage img(":/papple.png");
        img.scaled(node, node);
        QBrush brush(img);
        painter.setBrush(brush);
        painter.drawRect(apple);
    }
    else{
        //drwa apple
        QImage img(":/appleS.png");
        img.scaled(node, node);
        QBrush brush(img);
        painter.setBrush(brush);
        painter.drawRect(apple);
    }
}
