#ifndef CLASSICMODE_H
#define CLASSICMODE_H

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
class ClassicMode;
}

class ClassicMode : public QWidget
{
    Q_OBJECT

public:
    explicit ClassicMode(QWidget *parent = nullptr);
    ~ClassicMode();

    //paint event
    void paintEvent(QPaintEvent* event);

    //key event
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::ClassicMode *ui;

    MySnake* snake;
    MyApple* apple;

    QTimer* timer;
    int time=100;

    //eat
    QSound* eat;

private slots:
    void timeOutFun();
};

#endif // CLASSICMODE_H
