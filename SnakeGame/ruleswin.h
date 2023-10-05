#ifndef RULESWIN_H
#define RULESWIN_H

#include <QWidget>
#include <QIcon>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include "mypushbutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>

namespace Ui {
class RulesWin;
}

class RulesWin : public QWidget
{
    Q_OBJECT

public:
    explicit RulesWin(QWidget *parent = nullptr);
    ~RulesWin();

    //paint event
    void paintEvent(QPaintEvent* event);

    //control
    QLabel* ruleLabel1;
    QLabel* ruleLabel2;
    QLabel* ruleLabel3;
    MyPushButton* backButton;
    //lay out
    QHBoxLayout* Hboxlayout;

private:
    Ui::RulesWin *ui;

private slots:
    void backFun();
};

#endif // RULESWIN_H
