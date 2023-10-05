#ifndef HELLMODE_H
#define HELLMODE_H

#include <QWidget>
#include <QIcon>
#include <QPainter>
#include <QPixmap>
#include "mysnake.h"
#include "myapple.h"
#include <QTimer>
#include <QDebug>
#include <QSound>
#include <QKeyEvent>

namespace Ui {
class HellMode;
}

class HellMode : public QWidget
{
    Q_OBJECT

public:
    explicit HellMode(QWidget *parent = nullptr);
    ~HellMode();

    //paint event
    void paintEvent(QPaintEvent* event);

    //key event
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::HellMode *ui;

    MySnake* snake;

    MyApple* apple;
    MyApple* apple2;
    MyApple* apple3;
    MyApple* apple4;
    MyApple* apple5;
    MyApple* apple6;
    MyApple* papple;

    QTimer* timer;
    int time=50;

    //eat
    QSound* eat;

private slots:
    void timeOutFun();
};

#endif // HELLMODE_H
