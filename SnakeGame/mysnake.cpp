#include "mysnake.h"

//MySnake::MySnake(QWidget *parent) : QWidget(parent)
//{

//}

//程序发生未知错误，蛇在屏幕中只能在一小块区域中运动
//将头文件的width和height注释掉后，cpp文件中全部替换成this->width和this->height，蛇依旧只能在这里运动
//但是
//和刚才不同的是，蛇在区域以外的区域中不再继续隐式运动
//而是直接从区域外跳转到区域内
//应当与this指针有关

//通过QDebug调试发现，this->height()的值为480，this->width()的值为640
//也就是说，是snake中继承QWidget的大小为480和640，所以需要重新调用setFixedSize()函数

MySnake::MySnake(bool secondSnake, bool hellSnake)
{
    //multi mode
    this->secondSnake=secondSnake;

    //hell mode
    this->hellSnake=hellSnake;

    this->setFixedSize(1020, 640);

    //init the snale position
    snake.append(QRectF(QPoint(500, 300), QPoint(500+node, 300+node)));
    snake.append(QRectF(QPoint(500, 320), QPoint(500+node, 320+node)));
    snake.append(QRectF(QPoint(500, 340), QPoint(500+node, 340+node)));

    //if have the second snake, init the second snake position
    if(secondSnake)
    {
        snake2.append(QRectF(QPoint(540, 300), QPoint(540+node, 300+node)));
        snake2.append(QRectF(QPoint(540, 320), QPoint(540+node, 320+node)));
        snake2.append(QRectF(QPoint(540, 340), QPoint(540+node, 340+node)));
    }

    //if it is hell mode, init the wall
    if(hellSnake)
    {
        for(int i=0; i<height()/node;i++)
        {
            if(i==0||i==height()/node-1)
            {
                for(int j=0; j<width()-1; j++)
                {
                    snake3.append(QRectF(QPoint(j*node, i*node), QPoint(j*node+node, i*node+node)));
                }
            }
            else {
                snake3.append(QRectF(QPoint(0, i*node), QPoint(node, i*node+node)));
                snake3.append(QRectF(QPoint(width()-node, i*node), QPoint(width(), i*node+node)));
            }
        }
    }
}

//move
void MySnake::addUp()
{
    QPoint leftTop;
    // qDebug()<<"addUp";
    if(snake[0].y()-node>=0)
    {
        //if snake isn't out of bound
        leftTop=QPoint(snake[0].x(), snake[0].y()-node);
    }
    else{
        //snake out of bound
        leftTop=QPoint(snake[0].x(), this->height()-node);
        //        qDebug()<<this->height();
        //        leftTop=QPoint(snake[0].x(), height-node);
    }
    snake.insert(0,QRectF(leftTop, QPoint(leftTop.x()+node, leftTop.y()+node)));
}

void MySnake::addDown()
{
    QPoint leftTop;
    if(snake[0].y()+node<=this->height())
        //    if(snake[0].y()+node<=height)
    {
        //if snake isn't out of bound
        leftTop=QPoint(snake[0].x(), snake[0].y()+node);
    }
    else{
        //snake out of bound
        leftTop=QPoint(snake[0].x(), 0);
    }
    snake.insert(0,QRectF(leftTop, QPoint(leftTop.x()+node, leftTop.y()+node)));
}

void MySnake::addLeft()
{
    QPoint leftTop;
    if(snake[0].x()-node>=0)
    {
        //if snake isn't out of bound
        leftTop=QPoint(snake[0].x()-node, snake[0].y());
    }
    else{
        //snake out of bound
        leftTop=QPoint(this->width()-node, snake[0].y());
        //        qDebug()<<this->width();
        //        leftTop=QPoint(width-node, snake[0].y());
    }
    snake.insert(0,QRectF(leftTop, QPoint(leftTop.x()+node, leftTop.y()+node)));
}

void MySnake::addRight()
{
    QPoint leftTop;
    if(snake[0].x()+node<=this->width())
        //    if(snake[0].x()+node<=width)
    {
        //if snake isn't out of bound
        leftTop=QPoint(snake[0].x()+node, snake[0].y());
    }
    else{
        //snake out of bound
        leftTop=QPoint(0, snake[0].y());
    }
    snake.insert(0,QRectF(leftTop, QPoint(leftTop.x()+node, leftTop.y()+node)));
}

void MySnake::deleteList()
{
    snake.removeLast();
}

void MySnake::addUp2()
{
    QPoint leftTop;
//     qDebug()<<"addUp";
    if(snake2[0].y()-node>=0)
    {
        //if snake isn't out of bound
        leftTop=QPoint(snake2[0].x(), snake2[0].y()-node);
    }
    else{
        //snake out of bound
        leftTop=QPoint(snake2[0].x(), this->height()-node);
        //        qDebug()<<this->height();
        //        leftTop=QPoint(snake[0].x(), height-node);
    }
    snake2.insert(0,QRectF(leftTop, QPoint(leftTop.x()+node, leftTop.y()+node)));
}

void MySnake::addDown2()
{
    QPoint leftTop;
    if(snake2[0].y()+node<=this->height())
        //    if(snake[0].y()+node<=height)
    {
        //if snake isn't out of bound
        leftTop=QPoint(snake2[0].x(), snake2[0].y()+node);
    }
    else{
        //snake out of bound
        leftTop=QPoint(snake2[0].x(), 0);
    }
    snake2.insert(0,QRectF(leftTop, QPoint(leftTop.x()+node, leftTop.y()+node)));
}

void MySnake::addLeft2()
{
    QPoint leftTop;
    if(snake2[0].x()-node>=0)
    {
        //if snake isn't out of bound
        leftTop=QPoint(snake2[0].x()-node, snake2[0].y());
    }
    else{
        //snake out of bound
        leftTop=QPoint(this->width()-node, snake2[0].y());
        //        qDebug()<<this->width();
        //        leftTop=QPoint(width-node, snake[0].y());
    }
    snake2.insert(0,QRectF(leftTop, QPoint(leftTop.x()+node, leftTop.y()+node)));
}

void MySnake::addRight2()
{
    QPoint leftTop;
    if(snake2[0].x()+node<=this->width())
        //    if(snake[0].x()+node<=width)
    {
        //if snake isn't out of bound
        leftTop=QPoint(snake2[0].x()+node, snake2[0].y());
    }
    else{
        //snake out of bound
        leftTop=QPoint(0, snake2[0].y());
    }
    snake2.insert(0,QRectF(leftTop, QPoint(leftTop.x()+node, leftTop.y()+node)));
}

void MySnake::deleteList2()
{
    snake2.removeLast();
}

//judge snake tail direction
int MySnake::judgeSnakeTailDirection()
{
    int length=snake.length();
    //the point of ths tail of the snake
    QPoint lastPoint(snake[length-1].x(), snake[length-1].y());
    QPoint lastSecondPoint(snake[length-2].x(), snake[length-2].y());
    //directions of the snake tail
    QPoint up(lastPoint.x(), lastPoint.y()-node);
    QPoint down(lastPoint.x(), lastPoint.y()+node);
    QPoint left(lastPoint.x()-node, lastPoint.y());
    QPoint right(lastPoint.x()+node, lastPoint.y());
    //out of bound
    QPoint outUp(lastPoint.x(), 640-node);
    QPoint outDown(lastPoint.x(), 0);
    QPoint outLeft(1020-node, lastPoint.y());
    QPoint outRight(0, lastPoint.y());
    if(lastSecondPoint==up||lastSecondPoint==outUp)
    {
        return Dir_Down;
    }
    else if(lastSecondPoint==down||lastSecondPoint==outDown)
    {
        return Dir_Up;
    }
    else if(lastSecondPoint==left||lastSecondPoint==outLeft)
    {
        return Dir_Right;
    }
    else if(lastSecondPoint==right||lastSecondPoint==outRight)
    {
        return Dir_Left;
    }
}

int MySnake::judgeSnakeTailDirection2()
{
    int length=snake2.length();
    //the point of ths tail of the snake
    QPoint lastPoint(snake2[length-1].x(), snake2[length-1].y());
    QPoint lastSecondPoint(snake2[length-2].x(), snake2[length-2].y());
    //directions of the snake tail
    QPoint up(lastPoint.x(), lastPoint.y()-node);
    QPoint down(lastPoint.x(), lastPoint.y()+node);
    QPoint left(lastPoint.x()-node, lastPoint.y());
    QPoint right(lastPoint.x()+node, lastPoint.y());
    //out of bound
    QPoint outUp(lastPoint.x(), 640-node);
    QPoint outDown(lastPoint.x(), 0);
    QPoint outLeft(1020-node, lastPoint.y());
    QPoint outRight(0, lastPoint.y());
    if(lastSecondPoint==up||lastSecondPoint==outUp)
    {
        return Dir_Down;
    }
    else if(lastSecondPoint==down||lastSecondPoint==outDown)
    {
        return Dir_Up;
    }
    else if(lastSecondPoint==left||lastSecondPoint==outLeft)
    {
        return Dir_Right;
    }
    else if(lastSecondPoint==right||lastSecondPoint==outRight)
    {
        return Dir_Left;
    }
}

//judge snake bite something
bool MySnake::judgeSnakeBite(QRectF rec)
{
    if(snake[0]==rec)
    {
        return true;
    }
    else {
        return false;
    }
}

bool MySnake::judgeSnakeBite2(QRectF rec)
{
    if(snake2[0]==rec)
    {
        return true;
    }
    else {
        return false;
    }
}

//judge snake bite itself
bool MySnake::judgeSnakeBiteItself()
{
    for(int i=1; i<snake.length(); i++)
    {
        if(snake[0]==snake[i])
        {
            return true;
        }
    }

    return false;
}

bool MySnake::judgeSnakeBiteItself2()
{
    for(int i=1; i<snake2.length(); i++)
    {
        if(snake2[0]==snake2[i])
        {
            return true;
        }
    }

    return false;
}

//judge snake bite another snake
bool MySnake::judgeSnakeBiteAnother()
{
    for(int i=1; i<snake2.length(); i++)
    {
        if(judgeSnakeBite(snake2[i]))
        {
            return true;
        }
    }

    return false;
}

bool MySnake::judgeSnakeBiteAnother2()
{
    for(int i=1; i<snake.length(); i++)
    {
        if(judgeSnakeBite2(snake[i]))
        {
            return true;
        }
    }

    return false;
}

bool MySnake::judgeSnakeBiteWall()
{
    for(int i=0; i<snake3.length(); i++)
    {
        if(judgeSnakeBite(snake3[i]))
        {
            return true;
        }
    }

    return false;
}

//paint event
void MySnake::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen pen;

    //clear the border
    pen.setColor(Qt::transparent);
    painter.setPen(pen);

    if(!gameOver)
    {
        //paint snake
        //paint snake head

        switch(moveFlag)
        {
        case Dir_Up:
        {
            QImage img(":/snakeHeadUpS.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake[0]);
            break;
        }
        case Dir_Down:
        {
            QImage img(":/snakeHeadDownS.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake[0]);
            break;
        }
        case Dir_Left:
        {
            QImage img(":/snakeHeadLeftS.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake[0]);
            break;
        }
        case Dir_Right:
        {
            QImage img(":/snakeHeadRightS.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake[0]);
            break;
        }
        }

        //paint snake tail
        int index=snake.length()-1;
        switch(judgeSnakeTailDirection())
        {
        case Dir_Up:
        {
            QImage img(":/snakeTailUpS.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake[index]);
            break;
        }
        case Dir_Down:
        {
            QImage img(":/snakeTailDownS.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake[index]);
            break;
        }
        case Dir_Left:
        {
            QImage img(":/snakeTailLeftS.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake[index]);
            break;
        }
        case Dir_Right:
        {
            QImage img(":/snakeTailRightS.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake[index]);
            break;
        }
        }

        //paint snake body
        QImage img(":/snakeBodyS.png");
        img=img.scaled(node, node);
        QBrush brush(img);
        painter.setBrush(brush);
        for(int i=1;i<index;i++)
        {
            painter.drawRect(snake[i]);
        }



        //paint the second snake
        if(secondSnake)
        {
            //paint snake
            //paint snake head
            switch(moveFlag2)
            {
            case Dir_Up:
            {
                QImage img(":/snakeHeadUp2S.png");
                img=img.scaled(node, node);
                QBrush brush(img);
                painter.setBrush(brush);
                painter.drawRect(snake2[0]);
                break;
            }
            case Dir_Down:
            {
                QImage img(":/snakeHeadDown2S.png");
                img=img.scaled(node, node);
                QBrush brush(img);
                painter.setBrush(brush);
                painter.drawRect(snake2[0]);
                break;
            }
            case Dir_Left:
            {
                QImage img(":/snakeHeadLeft2S.png");
                img=img.scaled(node, node);
                QBrush brush(img);
                painter.setBrush(brush);
                painter.drawRect(snake2[0]);
                break;
            }
            case Dir_Right:
            {
                QImage img(":/snakeHeadRight2S.png");
                img=img.scaled(node, node);
                QBrush brush(img);
                painter.setBrush(brush);
                painter.drawRect(snake2[0]);
                break;
            }
            }

            //paint snake tail
            int index=snake2.length()-1;
            switch(judgeSnakeTailDirection2())
            {
            case Dir_Up:
            {
                QImage img(":/snakeTailUp2S.png");
                img=img.scaled(node, node);
                QBrush brush(img);
                painter.setBrush(brush);
                painter.drawRect(snake2[index]);
                break;
            }
            case Dir_Down:
            {
                QImage img(":/snakeTailDown2S.png");
                img=img.scaled(node, node);
                QBrush brush(img);
                painter.setBrush(brush);
                painter.drawRect(snake2[index]);
                break;
            }
            case Dir_Left:
            {
                QImage img(":/snakeTailLeft2S.png");
                img=img.scaled(node, node);
                QBrush brush(img);
                painter.setBrush(brush);
                painter.drawRect(snake2[index]);
                break;
            }
            case Dir_Right:
            {
                QImage img(":/snakeTailRight2S.png");
                img=img.scaled(node, node);
                QBrush brush(img);
                painter.setBrush(brush);
                painter.drawRect(snake2[index]);
                break;
            }
            }

            //paint snake body
            QImage img(":/snakeBody2S.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            for(int i=1;i<index;i++)
            {
                painter.drawRect(snake2[i]);
            }
        }
    }


    //hell game wall
    if(hellSnake)
    {
        for(int i=0; i<snake3.length(); i++)
        {
            QImage img(":/tree.png");
            img=img.scaled(node, node);
            QBrush brush(img);
            painter.setBrush(brush);
            painter.drawRect(snake3[i]);
        }
    }
}
