#ifndef CHOOSEMODE_H
#define CHOOSEMODE_H

#include <QWidget>
#include <QLabel>
#include "mypushbutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QIcon>
#include <QPainter>
#include <QTimer>
#include <QDebug>

//windows
#include "classicmode.h"
#include "hellmode.h"
#include "multimode.h"

namespace Ui {
class ChooseMode;
}

class ChooseMode : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseMode(QWidget *parent = nullptr);
    ~ChooseMode();

    //paint event
    void paintEvent(QPaintEvent* event);

private:
    Ui::ChooseMode *ui;

    //control
    QLabel* creatorLabel;
    QLabel* imgLabel;
    QLabel* welcomeLabel;
    MyPushButton* classicButton;
    MyPushButton* multiButton;
    MyPushButton* hellButton;
    MyPushButton* backButton;

    //layout
    QVBoxLayout* Vboxlayout;
    QHBoxLayout* Hboxlayout;

    //windows
    ClassicMode* classicMode;
    HellMode* hellMode;
    MultiMode* multiMode;

private slots:
    void classicFun();
    void multiFun();
    void hellFun();
    void backFun();
};

#endif // CHOOSEMODE_H
