#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    //background icon title and so on
    this->setWindowIcon(QIcon(":/logo.ico"));
    this->setWindowTitle("Gluttonous Snake Game");
    this->setFixedSize(1020, 640);

    //bgm
    bgm=new QSound(":/bgm2.wav");
    bgm->setParent(this);
    bgm->setLoops(-1);
    bgm->play();


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

    startButton=new MyPushButton(":/startButton.png", ":/startButton2.png");
    startButton->setParent(this);
    connect(startButton, &QPushButton::clicked, this, &MainWidget::startFun);
    //    //listening the signals from the choose mode window
    //    connect(chooseMode, &ChooseMode::backToMainWinFromChooseMode, this, &MainWidget::backFun);

    rulesButton=new MyPushButton(":/rulesButton.png", ":/rulesButton2.png");
    rulesButton->setParent(this);
    connect(rulesButton, &QPushButton::clicked, this, &MainWidget::rulesFun);

    exitButton=new MyPushButton(":/exitButton.png", ":/exitButton2.png");
    exitButton->setParent(this);
    connect(exitButton, &QPushButton::clicked, this, &MainWidget::exitFun);

    //lay out
    Vboxlayout=new QVBoxLayout(this);
    Vboxlayout->addWidget(imgLabel);
    Vboxlayout->addWidget(welcomeLabel);

    Hboxlayout=new QHBoxLayout(this);
    Hboxlayout->addWidget(startButton);
    Hboxlayout->addWidget(rulesButton);
    Hboxlayout->addWidget(exitButton);

    Vboxlayout->addItem(Hboxlayout);

    //windows
    chooseMode=new ChooseMode;
    ruleWin=new RulesWin;


}

MainWidget::~MainWidget()
{
    delete ui;
}

//paint event
void MainWidget::paintEvent(QPaintEvent *event)
{
    //background
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/backGround.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void MainWidget::startFun()
{
    //animation
    startButton->zoomDown();
    startButton->zoomUp();

    //delay
    QTimer::singleShot(200, this, [=]()
    {
        chooseMode->show();
    });
}

void MainWidget::rulesFun()
{
    //animation
    rulesButton->zoomDown();
    rulesButton->zoomUp();

    //delay
    QTimer::singleShot(200, this, [=]()
    {
        ruleWin->show();
    });
}

void MainWidget::exitFun()
{
    //animation
    exitButton->zoomDown();
    exitButton->zoomUp();

    //delay
    QTimer::singleShot(200, this, [=]()
    {
        QApplication* app;
        app->exit(0);
    });
}
