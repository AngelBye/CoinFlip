#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>
#include <QEvent>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QPushButton *parent = nullptr);

    //重写构造函数 传入的金币路径 还是银币路径
    MyCoin(QString btnImg);

    //记录币的位置
    int posX;
    int posY;
    bool flag;

    //翻转特效
    //_改变标志，执行翻转效果
    void changeFlag();
    //_正面翻反面定时器
    QTimer* timerToReverse;
    //_反面翻正面定时器
    QTimer* timerToFront;
    //_动画最小画面
    int min=1;
    //_动画最大画面
    int max=8;    
    //_执行动画的标志
    bool isAnimation=false;

    //重写按下事件
    void mousePressEvent(QMouseEvent* e);

    //胜利标志
    bool isWinFlag=false;

signals:

};

#endif // MYCOIN_H
