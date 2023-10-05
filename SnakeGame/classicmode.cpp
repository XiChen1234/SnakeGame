#include "classicmode.h"
#include "ui_classicmode.h"

ClassicMode::ClassicMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassicMode)
{
    ui->setupUi(this);

    //background icon title and so on
    this->setWindowIcon(QIcon(":/logo.ico"));
    this->setWindowTitle("Gluttonous Snake Game");
    this->setFixedSize(1020, 640);

    //init snake
    snake=new MySnake;
    snake->setParent(this);
    snake->show();

    //init apple
    apple=new MyApple;
    apple->setParent(this);
    apple->show();

    //init timer
    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ClassicMode::timeOutFun);

    //init eat
    eat=new QSound(":/split.wav");
    eat->setParent(this);
    eat->setLoops(1);
}

ClassicMode::~ClassicMode()
{
    delete ui;
}

//paint event
void ClassicMode::paintEvent(QPaintEvent *event)
{
    //background
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/backGround.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    if(snake->judgeSnakeBiteItself())
    {
        QFont font("方正舒体", 50, QFont::ExtraLight, false);
        font.setBold(true);
        painter.setFont(font);
        QString over="Game Over";
        QString score=QString::number(snake->snake.length()-3);
        painter.drawText(300, 200, over);
        painter.drawText(300, 350, QString("%1 %2").arg("Score:").arg(score));
        painter.drawText(100, 500, "按Esc键返回开始界面");
        snake->gameOver=true;
        timer->stop();
    }
}

//key event
void ClassicMode::keyPressEvent(QKeyEvent *event)
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
    case Qt::Key_Space:
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

void ClassicMode::timeOutFun()
{
    int count=1;
    if(snake->judgeSnakeBite(apple->getApple()))
    {
        count++;
        eat->play();
        apple->addApple();
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

    //update
    snake->update();
}
