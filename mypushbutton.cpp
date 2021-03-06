#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

//MyPushButton::MyPushButton(QPushButton *parent)
//    : QPushButton{parent}
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;

    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret){
        qDebug()<<"图片加载失败" ;
        return;
    }

    //设置图片
    //_设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //_设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //_设置图标
    this->setIcon(pix);
    //_设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

//向上弹跳特效
void MyPushButton::zoomUp()
{
    //创建动态对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");

    //设置时间间隔
    animation->setDuration(200);
    //_起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //_结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //_设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //_执行动画
    animation->start();
}

//向下弹跳特效
void MyPushButton::zoomDown()
{
    //创建动态对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");

    //设置时间间隔
    animation->setDuration(200);
    //_起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //_结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //_设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //_执行动画
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    //切换按下时的图片
    if(this->pressImgPath!=""){

        QPixmap pix;
        bool ret=pix.load(this->pressImgPath);
        if(!ret){
            qDebug()<<"图片加载失败" ;
            return;
        }

        //设置图片
        //_设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //_设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //_设置图标
        this->setIcon(pix);
        //_设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
        //让父类执行其他的内容
        return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    //切换释放时的图片
    if(this->pressImgPath!=""){

        QPixmap pix;
        bool ret=pix.load(this->normalImgPath);
        if(!ret){
            qDebug()<<"图片加载失败" ;
            return;
        }

        //设置图片
        //_设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //_设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //_设置图标
        this->setIcon(pix);
        //_设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
        //让父类执行其他的内容
        return QPushButton::mouseReleaseEvent(e);
}
