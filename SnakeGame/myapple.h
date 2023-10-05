#ifndef MYAPPLE_H
#define MYAPPLE_H

#include <QWidget>
#include <QRectF>
#include <QPainter>
#include <QPen>
#include <QTime>

class MyApple : public QWidget
{
    Q_OBJECT
public:
//    explicit MyApple(QWidget *parent = nullptr);

    //if the apple is a poisonous apple
    MyApple(bool poisonous=false);

    bool poisonous;

    QRectF apple;
    int node=20;
    int width=1020;
    int height=640;

    //add an apple
    void addApple();

    //get the rectF of apple
    QRectF getApple();

    void paintEvent(QPaintEvent* event);

signals:

public slots:
};

#endif // MYAPPLE_H
