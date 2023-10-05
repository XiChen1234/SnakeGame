#ifndef MULTIMODE_H
#define MULTIMODE_H

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
class MultiMode;
}

class MultiMode : public QWidget
{
    Q_OBJECT

public:
    explicit MultiMode(QWidget *parent = nullptr);
    ~MultiMode();

    //paint event
    void paintEvent(QPaintEvent* event);

    //key event
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::MultiMode *ui;

    MySnake* snake;
    MyApple* apple;
    MyApple* apple2;
    MyApple* apple3;
    MyApple* apple4;
    MyApple* apple5;
    MyApple* apple6;
    MyApple* papple;

    bool live=true;
    bool live2=true;

    QTimer* timer;
    int time=100;

    //eat
    QSound* eat;

private slots:
    void judgeLiveFun();
    void timeOutFun();

};

#endif // MULTIMODE_H
