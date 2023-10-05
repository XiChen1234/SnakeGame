#include "hellmode.h"
#include "ui_hellmode.h"

HellMode::HellMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HellMode)
{
    ui->setupUi(this);

    //background icon title and so on
    this->setWindowIcon(QIcon(":/logo.ico"));
    this->setWindowTitle("Gluttonous Snake Game");
    this->setFixedSize(1020, 640);

    //init snake
    snake=new MySnake(false, true);
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

    //poisonous
    papple=new MyApple(true);
    papple->setParent(this);
    papple->show();

    //init timer
    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &HellMode::timeOutFun);

    //init eat
    eat=new QSound(":/split.wav");
    eat->setParent(this);
    eat->setLoops(1);

}

HellMode::~HellMode()
{
    delete ui;
}

void HellMode::paintEvent(QPaintEvent *event)
{
    //background
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/backGround.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    if(snake->judgeSnakeBiteItself()||snake->judgeSnakeBite(papple->getApple())||
            snake->judgeSnakeBiteWall())
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
void HellMode::keyPressEvent(QKeyEvent *event)
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

void HellMode::timeOutFun()
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
        eat->play();
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

    //update
    snake->update();
}
