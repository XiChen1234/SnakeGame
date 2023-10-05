#include "choosemode.h"
#include "ui_choosemode.h"

ChooseMode::ChooseMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseMode)
{
    ui->setupUi(this);

    //background icon title and so on
    this->setWindowIcon(QIcon(":/logo.ico"));
    this->setWindowTitle("Gluttonous Snake Game");
    this->setFixedSize(1020, 640);

    //control
    creatorLabel=new QLabel(this);
    creatorLabel->setText("The game is created bt @Zhang Lechen");
    creatorLabel->setGeometry(0,0,350, 20);

    imgLabel=new QLabel(this);
    imgLabel->setPixmap(QPixmap(":/start.png"));
    imgLabel->setAlignment(Qt::AlignCenter);

    welcomeLabel=new QLabel(this);
    welcomeLabel->setText("Welcome to Gluttonous Snake Game!\n"
                          "Have a good time!");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    QFont font("Microsft YaHei", 20, 500);
    welcomeLabel->setFont(font);
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::red );
    welcomeLabel->setPalette(palette);

    classicButton=new MyPushButton(":/classicMode.png", ":/classicMode2.png");
    classicButton->setParent(this);
    connect(classicButton, &QPushButton::clicked, this, &ChooseMode::classicFun);

    multiButton=new MyPushButton(":/multiMode.png", ":/multiMode2.png");
    multiButton->setParent(this);
    connect(multiButton, &QPushButton::clicked, this, &ChooseMode::multiFun);

    hellButton=new MyPushButton(":/hellMode.png", ":/hellMode2.png");
    hellButton->setParent(this);
    connect(hellButton, &QPushButton::clicked, this, &ChooseMode::hellFun);

    backButton=new MyPushButton(":/backButton.png", ":/backButton2.png");
    backButton->setParent(this);
    connect(backButton, &QPushButton::clicked, this, &ChooseMode::backFun);

    //lay out
    Vboxlayout=new QVBoxLayout(this);
    Vboxlayout->addWidget(imgLabel);
    Vboxlayout->addWidget(welcomeLabel);

    Hboxlayout=new QHBoxLayout(this);
    Hboxlayout->addWidget(classicButton);
    Hboxlayout->addWidget(multiButton);
    Hboxlayout->addWidget(hellButton);

    Vboxlayout->addItem(Hboxlayout);

    //windows
    classicMode=new ClassicMode;
    hellMode=new HellMode;
    multiMode=new MultiMode;
}

ChooseMode::~ChooseMode()
{
    delete ui;
}

void ChooseMode::paintEvent(QPaintEvent *event)
{
    //background
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/backGround.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void ChooseMode::classicFun()
{
    classicButton->zoomDown();
    classicButton->zoomUp();

    //delay
    QTimer::singleShot(200, this, [=]()
    {
        this->close();
        classicMode->show();
    });
}

void ChooseMode::multiFun()
{
    multiButton->zoomDown();
    multiButton->zoomUp();

    //delay
    QTimer::singleShot(200, this, [=]()
    {
//        qDebug()<<"do show multiMode";//do
        this->close();
//        qDebug()<<"do show multiMode";//do
        multiMode->show();
//        qDebug()<<"do show multiMode";//don't
    });
}

void ChooseMode::hellFun()
{
    hellButton->zoomDown();
    hellButton->zoomUp();

    //delay
    QTimer::singleShot(200, this, [=]()
    {
        this->close();
        hellMode->show();
    });
}

void ChooseMode::backFun()
{
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
