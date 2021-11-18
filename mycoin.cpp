#include "mycoin.h"

#include <QPixmap>
#include <QTimer>
#include <QtDebug>

//MyCoin::MyCoin(QPushButton *parent)
//    : QPushButton{parent}
//{

//}

MyCoin::MyCoin(QString btnImg)
{
    //初始化按钮.

    //_加载背景图片
    QPixmap pix;
    bool ret=pix.load(btnImg);
    if(!ret)
    {
        QString str =QString("图片 %1 加载失败").arg(btnImg);
        qDebug()<<str;
        return;
    }
    //_配置按钮属性
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //监听翻转特效
    //_初始化定时器对象
    timerToReverse=new QTimer(this);
    timerToFront=new QTimer(this);
    //_监听正面翻反面的信号，并翻转金币
    connect(timerToReverse,&QTimer::timeout,this,[=](){
        //__给按钮添加资源
        QPixmap pixAnimation;
        QString str=QString(":/res/Coin000%1.png").arg(this->min++);
        pixAnimation.load(str);
        //__按钮属性初始化
        this->setFixedSize(pixAnimation.width(),pixAnimation.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixAnimation);
        this->setIconSize(QSize(pixAnimation.width(),pixAnimation.height()));
        //__判断翻完了，将min重置为1
        if(this->min>this->max)
        {
            this->min=1;
            timerToReverse->stop();
        }
    });
    //_监听反面翻正面的信号，并翻转金币
    connect(timerToFront,&QTimer::timeout,this,[=](){
        //__给按钮添加资源
        QPixmap pixAnimation;
        QString str=QString(":/res/Coin000%1.png").arg(this->max--);
        pixAnimation.load(str);
        //__按钮属性初始化
        this->setFixedSize(pixAnimation.width(),pixAnimation.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixAnimation);
        this->setIconSize(QSize(pixAnimation.width(),pixAnimation.height()));
        //__判断翻完了，将min重置为1
        if(this->max<this->min)
        {
            this->max=8;
            timerToFront->stop();
        }
    });

}

void MyCoin::changeFlag()
{
    //如果是正面，执行下列代码
    if(this->flag)
    {
        timerToReverse->start(30);
        this->flag=false;
    }
    //如果是反面执行下列代码
    else
    {
        timerToFront->start(30);
        this->flag=true;
    }
}
