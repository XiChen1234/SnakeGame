# Qt练手项目之——贪吃蛇
最近在整理我之前做过的项目，翻到了大一时制作的贪吃蛇小项目。时间一晃而过，已经两年了。那会儿的我还是一个天天赶实验报告的小白……  
这个项目实在学校实训的时候，匆匆制作的。还拿到了实训的“优”的评级，对于新手来说有一定的学习价值，对于大佬们来说就十分幼稚了。当时的我刚刚接触编程，对于C++还非常生疏，因此项目中有许多不符合软件开发规范的内容，还请诸位谅解。

未来如果有时间的话，我还会将这个项目进行重构优化。没有时间的话……就让它停留在这个最生涩的版本吧，毕竟这是我青春时鏖战了好几个晚上的成果，值得留恋。

如果本文对你有所帮助的话，请给我一个免费的赞，这会让更多的人看到这篇文章。  
有任何意见或建议，欢迎评论或私信！  
_我是希晨，希望给你带来快乐！_

> 关于作者：软件工程大学牲，喜欢尝试没有尝试过的事情，希望能永远行走在学习新知识的道路上！  
>   
> 有任何需求请添加本人微信，我会尽我所能帮助你，一起学习，共同进步！   
>   
> 微信号：`Xi_Chen66752878`，请备注`CSDN`
![微信二维码](https://img-blog.csdnimg.cn/7dafe66db89f4681bc268c829c11ab19.png#pic_center)

由于防盗外链图片的设置，README中部分图片将无法在Gitee中进行展示，可前往我的CSDN博客中进行详细的了解。
> CSDN博客：https://blog.csdn.net/Xi_Chen123/article/details/131928608

## 项目介绍
Qt实训时制作的小项目，贪吃蛇小游戏。很简单的练手，适合C++新手熟悉C++各种知识点与Qt编程。
![主页](https://img-blog.csdnimg.cn/89f532ec7e574088bc4bfa0f526de7c9.png#pic_center)



## 项目截图
![主页](https://img-blog.csdnimg.cn/89f532ec7e574088bc4bfa0f526de7c9.png#pic_center)
![模式选择](https://img-blog.csdnimg.cn/40ec6b1346b14a679309153723ca7aea.png#pic_center)
![游戏规则](https://img-blog.csdnimg.cn/354030a2fc1c4846ae2a1e22aedbe8c6.png#pic_center)
![经典模式](https://img-blog.csdnimg.cn/9f68fd21aecb4486a2c0dd1e785092d0.png#pic_center)
![双人模式](https://img-blog.csdnimg.cn/36c37c7a451e4d8181333a4b3125947c.png#pic_center)
![地狱模式](https://img-blog.csdnimg.cn/5bec53b1456c4ee28dd085cd0c3b3c3d.png#pic_center)


## 源码下载与发布版体验试玩
- 源码下载
    1. 如您是软件开发者，想要阅读源码或对本项目进行自定义配置或修改，请选择master分支下载最新源码，请确保你拥有Qt开发环境与Qt Creator，或使用其他拥有Qt开发环境的编译器；
    ![下载源码](https://img-blog.csdnimg.cn/49145a19af61447d82623ffd26b59209.png#pic_center)
    2. 解压下载好的zip包，或直接使用编译器插件进行clone；
    3. 这里以Qt Creator为例，进入Qt Creator，点击左侧**打开项目**按钮，在文件资源选择器中选择`SnakeGame.pro`文件打开项目；
    ![打开项目](https://img-blog.csdnimg.cn/47f586bb9de44320b3712739ce82670c.png#pic_center)
    ![选择项目](https://img-blog.csdnimg.cn/579e99d2976242f4b7074e1cf8aca8ec.png#pic_center)

    4. 待项目构建完成，控制台不输出相关错误时，点击项目左下角三角符号进行运行，或使用快捷键`Ctrl+R`，或右键项目父文件夹，在展开的选项卡中选择**运行**，即可在新增窗口中运行程序。
    ![运行项目](https://img-blog.csdnimg.cn/13f777ed16d7434bbb6fad84fc5ef2a8.png#pic_center)
    ![运行成功](https://img-blog.csdnimg.cn/bc9d1cb923124c9ab057222b2110293d.png#pic_center)


- 发布版体验试玩
    1. 如您是游客，仅想体验一下本项目，请选择发行版下载最新发布版压缩包。无需拥有Qt开发环境
    ![在gitee仓库下载](https://img-blog.csdnimg.cn/73161c07d60644bcb6f0b68529c70193.png#pic_center)
    ![下载压缩包](https://img-blog.csdnimg.cn/5ef712c8f31648f889a34a15dac15962.png#pic_center)
    2. 下载成功后，解压压缩包，点击文件夹中的`SnakeGame.exe`文件，即可进行游戏   ![运行程序](https://img-blog.csdnimg.cn/55fd6e37726649ff85b32560fc0e75d2.png#pic_center)

## 项目重点内容
- 按钮动画：
    - 鼠标在按钮上点击，按钮高亮，鼠标松开后，恢复正常；若正常点击按钮，按钮跳动，动画结束后，实行按钮功能
    ![点击动画](https://img-blog.csdnimg.cn/9d45d5d1984d41498f3ef046dd18fff0.gif#pic_center)

    - 实现过程：新建一个`MyPushButton`的类，继承`QPushButton`类。重写构造方法、鼠标点击事件、鼠标释放事件，并增添跳跃动画。
    - 代码详解：
    ```c
    // mypushbutton.h
    #ifndef MYPUSHBUTTON_H
    #define MYPUSHBUTTON_H

    #include <QWidget>
    #include <QPushButton>
    #include <QPixmap>
    #include <QPropertyAnimation>

    class MyPushButton : public QPushButton
    {
        Q_OBJECT
    public:
        //explicit MyPushButton(QWidget *parent = nullptr);

        //press image is empty path, if it is lack of the second path, there is no press animaltion
        MyPushButton(QString normalImg, QString pressImg="");

        QString normalImg;
        QString pressImg;

        void zoomDown();
        void zoomUp();

        //press event
        void mousePressEvent(QMouseEvent* event);

        //releaes event
        void mouseReleaseEvent(QMouseEvent* event);

    signals:

    public slots:
    };

    #endif // MYPUSHBUTTON_H

    ```

    ```c
    // mypushbutton.cpp
    #include "mypushbutton.h"

    //MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
    //{

    //}

    MyPushButton::MyPushButton(QString normalImg, QString pressImg)
    {
        //normal image path
        this->normalImg=normalImg;

        //press image path
        this->pressImg=pressImg;

        QPixmap pix;
        //loag normalImg
        pix.load(normalImg);

        //set fixed size
        this->setFixedSize(pix.width(), pix.height());

        //set style sheet
        this->setStyleSheet("QPushButton{border:0px;}");

        //set icon
        this->setIcon(pix);

        //set icon size
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    void MyPushButton::zoomDown()
    {
        //create animation
        QPropertyAnimation* animation=new QPropertyAnimation(this, "geometry");

        //set time gap
        animation->setDuration(200);

        //start
        animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        //end
        animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

        //set animation rules
        animation->setEasingCurve(QEasingCurve::OutBounce);

        animation->start();
    }

    void MyPushButton::zoomUp()
    {
        //create animation
        QPropertyAnimation* animation=new QPropertyAnimation(this, "geometry");

        //set time gap
        animation->setDuration(200);

        //start
        animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
        //end
        animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

        //set animation rules
        animation->setEasingCurve(QEasingCurve::OutBounce);

        animation->start();
    }

    void MyPushButton::mousePressEvent(QMouseEvent *event)
    {
        QPixmap pix;
        //load press img
        pix.load(pressImg);

        //set fixed size
        this->setFixedSize(pix.width(), pix.height());

        //set style sheet
        this->setStyleSheet("QPushButton{border:0px;}");

        //set icon
        this->setIcon(pix);

        //set icon size
        this->setIconSize(QSize(pix.width(), pix.height()));

        //let parent do other thing
        return QPushButton::mousePressEvent(event);
    }

    void MyPushButton::mouseReleaseEvent(QMouseEvent *event)
    {

        QPixmap pix;
        //load normal img
        pix.load(normalImg);

        //set fixed size
        this->setFixedSize(pix.width(), pix.height());

        //set style sheet
        this->setStyleSheet("QPushButton{border:0px;}");

        //set icon
        this->setIcon(pix);

        //set icon size
        this->setIconSize(QSize(pix.width(), pix.height()));


        //let parent do other thing
        return QPushButton::mouseReleaseEvent(event);
    }

    ```

- 蛇身绘制
    - 不同于互联网上普通的贪吃蛇教程，蛇身是由简单的小方块构成的。我的小蛇由三个部分组成：蛇头、蛇身、蛇尾，都有着不同运动方向的不同贴图。
    ![蛇身绘制](https://img-blog.csdnimg.cn/39afec2a3a8c4616b99b1e3aa11ab265.png#pic_center)

    - 创建`MySnake`类，继承`Qwidget`类，重写绘图事件，分别绘制头、身、尾。根据`MySnake`类中`moveFlag`成员变量判断蛇头方向、`MySnake`中`judgeSnakeTailDirection`成员函数判断蛇尾方向
    ![超出屏幕自动修改头部方向](https://img-blog.csdnimg.cn/bac50506afa140bb81be0968fa294f6d.png#pic_center)

    - 代码详解：
    ```c
    // mysnake.h
    #ifndef MYSNAKE_H
    #define MYSNAKE_H

    #include <QWidget>
    #include <QList>
    #include <QRectF>
    #include <QPoint>
    #include <QPainter>
    #include <QPen>
    #include <QtDebug>

    enum Direction
    {
        Dir_Up,
        Dir_Down,
        Dir_Left,
        Dir_Right
    };

    class MySnake : public QWidget
    {
        Q_OBJECT
    public:
    //    explicit MySnake(QWidget *parent = nullptr);

        MySnake(bool secondSnake=false, bool hellSnake=false);

        bool secondSnake;
        bool hellSnake;//creat the wall

        QList <QRectF> snake;
        QList <QRectF> snake2;
        QList <QRectF> snake3;
        int node=20;

        int moveFlag=Dir_Up;
        int moveFlag2=Dir_Up;
        bool gameStart=false;
        bool gameOver=false;

        //move
        void addUp();
        void addDown();
        void addLeft();
        void addRight();

        void deleteList();

        void addUp2();
        void addDown2();
        void addLeft2();
        void addRight2();

        void deleteList2();

        //judge snake tail direction
        int judgeSnakeTailDirection();
        int judgeSnakeTailDirection2();

        //judge snake bite something
        bool judgeSnakeBite(QRectF rec);
        bool judgeSnakeBite2(QRectF rec);

        //judge snake bite itself
        bool judgeSnakeBiteItself();
        bool judgeSnakeBiteItself2();

        //judge snake bite another snake
        bool judgeSnakeBiteAnother();
        bool judgeSnakeBiteAnother2();
        bool judgeSnakeBiteWall();

        //paint event
        void paintEvent(QPaintEvent* event);

    signals:

    public slots:
    };

    #endif // MYSNAKE_H

    ```
    
    ```c
    // mysnake.cpp
    // 代码过多，放在文章里太过繁冗，且观感十分不友好。请下载源码后进行详细查看
    ```
- 双人模式
    - 由前段时间另一款小游戏产生的灵感，两位玩家分别控制一条小蛇进行吃苹果，当咬到自己、吃到毒苹果、撞到对手的蛇身/蛇尾上则死亡，最后较长者胜利
    ![双人模式](https://img-blog.csdnimg.cn/42c3231ad65b4feaa7a187683177af87.png#pic_center)

    - 在`MySnake`类，加入一成员变量`bool secondSnake`，用于判断当前页面是否为多人模式页面。若为`true`，则构建`snake2`，并进行绘图事件的重写。在`MultiMode`类中重写键盘事件，加入小方向键更改`snake2`的运动方向。在`timeOutFun()`中对蛇的运动状态进行更新，即可实现多人模式的编写
    - 代码详解：由于该功能实现的过于复杂，在整个项目多出均进行了增加代码段，因此无法在这里简单演示。请下载**项目源码**后参考整个项目进行理解。在涉及双人模式代码段均有相关注释辅助理解


## 作者的话
鸣谢：[bilibili](https://www.bilibili.com/)——[@C语言实战大全](https://space.bilibili.com/1397938832)  
学习视频地址：[【QT项目】QT项目实战：贪吃蛇项目丨完整详细视频教程，小白就业捷径](https://www.bilibili.com/video/BV1kW4y1b7ub/?share_source=copy_web&vd_source=bf979150bdfe2a86a0c2871b8e19d452)  
我的项目仓库：[跳转项目gitee仓库](https://gitee.com/zhang-lechen123/snake-game)

这个项目虽说是简单的练手项目，但对于当时的我，初学C++，不会指针不会Qt的我来说，还是较为困难的。但是这个老师的讲解深入浅出，分析明确，逐步开发的视频风格也帮助了我很多，更是让我在学校的实训中拿到了“优”的等级。我也仅仅是在老师的基础上增添了一些页面跳转，改了一些UI控件，如果你喜欢我的项目分享，也请给这位老师一个大大的三连。



如果本文对你有所帮助的话，请给我一个免费的赞，这会让更多的人看到这篇文章。  
有任何意见或建议，欢迎评论或私信！  
_我是希晨，希望给你带来快乐！_

> 关于作者：软件工程大学牲，喜欢尝试没有尝试过的事情，希望能永远行走在学习新知识的道路上！  
>   
> 有任何需求请添加本人微信，我会尽我所能帮助你，一起学习，共同进步！   
>   
> 微信号：`Xi_Chen66752878`，请备注`CSDN`
![微信二维码](https://img-blog.csdnimg.cn/7dafe66db89f4681bc268c829c11ab19.png#pic_center)
