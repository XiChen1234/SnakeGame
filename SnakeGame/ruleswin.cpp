#include "ruleswin.h"
#include "ui_ruleswin.h"

RulesWin::RulesWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RulesWin)
{
    ui->setupUi(this);

    //background icon title and so on
    this->setWindowIcon(QIcon(":/logo.ico"));
    this->setWindowTitle("Gluttonous Snake Game");
    this->setFixedSize(1020, 640);

    //control
    ruleLabel1=new QLabel(this);
    ruleLabel1->setPixmap(QPixmap(":/rules1.png"));

    ruleLabel2=new QLabel(this);
    ruleLabel2->setPixmap(QPixmap(":/rules2.png"));

    ruleLabel3=new QLabel(this);
    ruleLabel3->setPixmap(QPixmap(":/rules3.png"));

    backButton=new MyPushButton(":/backButton.png", ":/backButton2.png");
    backButton->setParent(this);
    connect(backButton, &QPushButton::clicked, this, &RulesWin::backFun);

    //lay out
    Hboxlayout=new QHBoxLayout(this);
    Hboxlayout->addWidget(ruleLabel1);
    Hboxlayout->addWidget(ruleLabel2);
    Hboxlayout->addWidget(ruleLabel3);

    this->setLayout(Hboxlayout);
}

RulesWin::~RulesWin()
{
    delete ui;
}

//paint event
void RulesWin::paintEvent(QPaintEvent *event)
{
    //background
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/backGround.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void RulesWin::backFun()
{
    //animation
    backButton->zoomDown();
    backButton->zoomUp();

    //delay
    QTimer::singleShot(200, this, [=]()
    {
/*
 * ******************************************************************
 * back to the main window
 * ******************************************************************
 */
        this->close();
    });
}
