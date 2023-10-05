#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include "mypushbutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QSound>

//windows
#include "choosemode.h"
#include "ruleswin.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    //paint event
    void paintEvent(QPaintEvent* event);

private:
    Ui::MainWidget *ui;

    //control
    QLabel* creatorLabel;
    QLabel* imgLabel;
    QLabel* welcomeLabel;
    MyPushButton* startButton;
    MyPushButton* rulesButton;
    MyPushButton* exitButton;

    //layout
    QVBoxLayout* Vboxlayout;
    QHBoxLayout* Hboxlayout;

    //windows
    ChooseMode* chooseMode;
    RulesWin* ruleWin;

    //bgm
    QSound* bgm;

//slots
private slots:
    void startFun();
    void rulesFun();
    void exitFun();
};

#endif // MAINWIDGET_H
