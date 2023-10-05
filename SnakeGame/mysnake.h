#ifndef MYSNAKE_H
#define MYSNAKE_H

#include <QWidget>
#include <QList>
#include <QRectF>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QtDebug>

enum Direction
{
    Dir_Up,
    Dir_Down,
    Dir_Left,
    Dir_Right
};

class MySnake : public QWidget
{
    Q_OBJECT
public:
//    explicit MySnake(QWidget *parent = nullptr);

    MySnake(bool secondSnake=false, bool hellSnake=false);

    bool secondSnake;
    bool hellSnake;//creat the wall

    QList <QRectF> snake;
    QList <QRectF> snake2;
    QList <QRectF> snake3;
    int node=20;

    int moveFlag=Dir_Up;
    int moveFlag2=Dir_Up;
    bool gameStart=false;
    bool gameOver=false;

    //move
    void addUp();
    void addDown();
    void addLeft();
    void addRight();

    void deleteList();

    void addUp2();
    void addDown2();
    void addLeft2();
    void addRight2();

    void deleteList2();

    //judge snake tail direction
    int judgeSnakeTailDirection();
    int judgeSnakeTailDirection2();

    //judge snake bite something
    bool judgeSnakeBite(QRectF rec);
    bool judgeSnakeBite2(QRectF rec);

    //judge snake bite itself
    bool judgeSnakeBiteItself();
    bool judgeSnakeBiteItself2();

    //judge snake bite another snake
    bool judgeSnakeBiteAnother();
    bool judgeSnakeBiteAnother2();
    bool judgeSnakeBiteWall();

    //paint event
    void paintEvent(QPaintEvent* event);

signals:

public slots:
};

#endif // MYSNAKE_H
