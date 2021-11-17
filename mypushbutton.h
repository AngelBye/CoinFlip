#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QPushButton *parent = nullptr);

    //成员属性 保存用户传的默认显示路径 以及按下后显示的图片
    QString normalImgPath;
    QString pressImgPath;

    //构造函数 参数1 正常显示的图片路径 参数2 按下后显示的图片路径
    MyPushButton(QString normalImg,QString pressImg="");

    //弹跳特效
    void zoomUp();//向上跳
    void zoomDown();//向下跳

signals:

};

#endif // MYPUSHBUTTON_H
