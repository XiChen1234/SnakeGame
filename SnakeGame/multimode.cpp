#include "multimode.h"
#include "ui_multimode.h"

MultiMode::MultiMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiMode)
{
    ui->setupUi(this);

    //background icon title and so on
    this->setWindowIcon(QIcon(":/logo.ico"));
    this->setWindowTitle("Gluttonous Snake Game");
    this->setFixedSize(1020, 640);

    //init snake
    //have the second snake
    snake=new MySnake(true, false);
    snake->setParent(this);
    snake->show();

    //init apple
    apple=new MyApple;
    apple->setParent(this);
    apple->show();

    apple2=new MyApple;
    apple2->setParent(this);
    apple2->show();

    apple3=new MyApple;
    apple3->setParent(this);
    apple3->show();

    apple4=new MyApple;
    apple4->setParent(this);
    apple4->show();

    apple5=new MyApple;
    apple5->setParent(this);
    apple5->show();

    apple6=new MyApple;
    apple6->setParent(this);
    apple6->show();

    papple=new MyApple(true);
    papple->setParent(this);
    papple->show();

    //init timer
    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MultiMode::judgeLiveFun);
    connect(timer, &QTimer::timeout, this, &MultiMode::timeOutFun);
    //    connect(timer, &QTimer::timeout, this, &MultiMode::timeOutFun2);

    //init eat
    eat=new QSound(":/split.wav");
    eat->setParent(this);
    eat->setLoops(1);
}

MultiMode::~MultiMode()
{
    delete ui;
}

void MultiMode::paintEvent(QPaintEvent *event)
{
    //background
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/backGround.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    if(snake->gameOver)
    {
//        qDebug()<<"do";
        QFont font("方正舒体", 50, QFont::ExtraLight, false);
        font.setBold(true);
        painter.setFont(font);
        QString over;
        if(snake->snake.length()>snake->snake2.length())
        {
            over="玩家1获胜！";
        }
        else if(snake->snake.length()<snake->snake2.length()){
            over="玩家2获胜！";
        }
        else {
            over="平局";
        }
        QString score1=QString::number(snake->snake.length()-3);
        painter.drawText(300, 100, over);
        painter.drawText(300, 200, QString("%1 %2").arg("Score one:").arg(score1));
        QString score2=QString::number(snake->snake2.length()-3);
        painter.drawText(300, 300, QString("%1 %2").arg("Score two:").arg(score2));
        painter.drawText(100, 400, "按Esc键返回开始界面");
        snake->gameOver=true;
        timer->stop();
    }


}

void MultiMode::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
        if(snake->moveFlag!=Dir_Down)
        {
            snake->moveFlag=Dir_Up;
        }
        break;
    case Qt::Key_S:
        if(snake->moveFlag!=Dir_Up)
        {
            snake->moveFlag=Dir_Down;
        }
        break;
    case Qt::Key_A:
        if(snake->moveFlag!=Dir_Right)
        {
            snake->moveFlag=Dir_Left;
        }
        break;
    case Qt::Key_D:
        if(snake->moveFlag!=Dir_Left)
        {
            snake->moveFlag=Dir_Right;
        }
        break;

        //the second snake
    case Qt::Key_Up:
        if(snake->moveFlag2!=Dir_Down)
        {
            snake->moveFlag2=Dir_Up;
        }
        break;
    case Qt::Key_Down:
        if(snake->moveFlag2!=Dir_Up)
        {
            snake->moveFlag2=Dir_Down;
        }
        break;
    case Qt::Key_Left:
        if(snake->moveFlag2!=Dir_Right)
        {
            snake->moveFlag2=Dir_Left;
        }
        break;
    case Qt::Key_Right:
        if(snake->moveFlag2!=Dir_Left)
        {
            snake->moveFlag2=Dir_Right;
        }
        break;

    case Qt::Key_Space:
        //        qDebug()<<"press space";//do
        if(!snake->gameOver)
        {
            if(snake->gameStart)
            {
                snake->gameStart=false;

                timer->stop();
            }
            else {
                snake->gameStart=true;

                timer->start(time);
            }
        }
        //        qDebug()<<snake->gameStart;//do

        break;
    case Qt::Key_Escape:
/**********************************************************************************
 * back to the main widget
 **********************************************************************************
 */
        this->close();
        break;
    default:
        break;
    }
}

void MultiMode::judgeLiveFun()
{
    if(snake->judgeSnakeBiteItself())
    {
        live=false;
        //        qDebug()<<"bite itself";
        //        qDebug()<<live;
        //        qDebug()<<live2;
    }

    if(snake->judgeSnakeBiteItself2())
    {
        live2=false;
        //        qDebug()<<"bite itself2";
        //        qDebug()<<live;
        //        qDebug()<<live2;
    }

    if(snake->judgeSnakeBite(papple->getApple()))
    {
        live=false;
        //        qDebug()<<"papple";//false
        //        qDebug()<<live;
        //        qDebug()<<live2;
    }

    if(snake->judgeSnakeBite2(papple->getApple()))
    {
        live2=false;
        //        qDebug()<<"papple";
        //        qDebug()<<live;
        //        qDebug()<<live2;
    }

    if(snake->judgeSnakeBiteAnother())
    {
        live=false;
        //        qDebug()<<"bite another";
        //        qDebug()<<live;//false
        //        qDebug()<<live2;
    }

    if(snake->judgeSnakeBiteAnother2())
    {
        live2=false;
        //        qDebug()<<"bite another";
        //        qDebug()<<live;
        //        qDebug()<<live2;
    }

    snake->gameOver=!(live||live2);
    //        qDebug()<<snake->gameOver;
}

void MultiMode::timeOutFun()
{
    if(live)
    {
        int count=1;
        if(snake->judgeSnakeBite(apple->getApple()))
        {
            count++;
            eat->play();
            apple->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite(apple2->getApple()))
        {
            count++;
            eat->play();
            apple2->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite(apple3->getApple()))
        {
            count++;
            eat->play();
            apple3->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite(apple4->getApple()))
        {
            count++;
            eat->play();
            apple4->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite(apple5->getApple()))
        {
            count++;
            eat->play();
            apple5->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite(apple6->getApple()))
        {
            count++;
            apple6->addApple();
            papple->addApple();
        }

        while(count--)
        {
            //add
            switch(snake->moveFlag)
            {
            case Dir_Up:
                snake->addUp();
                break;
            case Dir_Down:
                snake->addDown();
                break;
            case Dir_Left:
                snake->addLeft();
                break;
            case Dir_Right:
                snake->addRight();
                break;
            default:
                break;
            }
        }

        //delete
        snake->deleteList();
    }


    if(live2)
    {
        //the second snake
        int count2=1;
        if(snake->judgeSnakeBite2(apple->getApple()))
        {
            //            qDebug()<<snake->snake2.length();
            count2++;
            eat->play();
            apple->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite2(apple2->getApple()))
        {
            //        qDebug()<<snake->snake2.length();//do
            count2++;
            eat->play();
            apple2->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite2(apple3->getApple()))
        {
            //        qDebug()<<snake->snake2.length();//do
            count2++;
            eat->play();
            apple3->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite2(apple4->getApple()))
        {
            //        qDebug()<<snake->snake2.length();//do
            count2++;
            eat->play();
            apple4->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite2(apple5->getApple()))
        {
            //        qDebug()<<snake->snake2.length();//do
            count2++;
            eat->play();
            apple5->addApple();
            papple->addApple();
        }

        if(snake->judgeSnakeBite2(apple6->getApple()))
        {
            //        qDebug()<<snake->snake2.length();//do
            count2++;
            eat->play();
            apple6->addApple();
            papple->addApple();
        }

        while(count2--)
        {
            //add
            switch(snake->moveFlag2)
            {
            case Dir_Up:
                snake->addUp2();
                break;
            case Dir_Down:
                snake->addDown2();
                break;
            case Dir_Left:
                snake->addLeft2();
                break;
            case Dir_Right:
                snake->addRight2();
                break;
            default:
                break;
            }
        }

        //delete
        snake->deleteList2();
    }

    //update
    snake->update();
}

//void MultiMode::timeOutFun2()
//{
//    if(live2)
//    {
//        //the second snake
//        int count2=1;
//        if(snake->judgeSnakeBite2(apple->getApple()))
//        {
//            //qDebug()<<snake->snake2.length();
//            count2++;
//            apple->addApple();
//            papple->addApple();
//        }

//        if(snake->judgeSnakeBite2(apple2->getApple()))
//        {
//            //        qDebug()<<snake->snake2.length();//do
//            count2++;
//            apple2->addApple();
//            papple->addApple();
//        }

//        if(snake->judgeSnakeBite2(apple3->getApple()))
//        {
//            //        qDebug()<<snake->snake2.length();//do
//            count2++;
//            apple3->addApple();
//            papple->addApple();
//        }

//        if(snake->judgeSnakeBite2(apple4->getApple()))
//        {
//            //        qDebug()<<snake->snake2.length();//do
//            count2++;
//            apple4->addApple();
//            papple->addApple();
//        }

//        if(snake->judgeSnakeBite2(apple5->getApple()))
//        {
//            //        qDebug()<<snake->snake2.length();//do
//            count2++;
//            apple5->addApple();
//            papple->addApple();
//        }

//        if(snake->judgeSnakeBite2(apple6->getApple()))
//        {
//            //        qDebug()<<snake->snake2.length();//do
//            count2++;
//            apple6->addApple();
//            papple->addApple();
//        }

//        while(count2--)
//        {
//            //add
//            switch(snake->moveFlag2)
//            {
//            case Dir_Up:
//                snake->addUp2();
//                break;
//            case Dir_Down:
//                snake->addDown2();
//                break;
//            case Dir_Left:
//                snake->addLeft2();
//                break;
//            case Dir_Right:
//                snake->addRight2();
//                break;
//            default:
//                break;
//            }
//        }

//        //delete
//        snake->deleteList2();

//        //update
//        snake->update();
//    }
//}
