#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

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

    //改变标志，执行翻转效果
    void changeFlag();

    //正面翻反面定时器
    QTimer* timerToReverse;

    //反面翻正面定时器
    QTimer* timerToFront;

    //动画最小画面
    int min=1;

    //动画最大画面
    int max=8;

signals:

};

#endif // MYCOIN_H
