#include "mycoin.h"

#include <QPixmap>
#include <QtDebug>

//MyCoin::MyCoin(QPushButton *parent)
//    : QPushButton{parent}
//{

//}

MyCoin::MyCoin(QString btnImg)
{
    //初始化按钮
    //_加载背景图片
    QPixmap pix;
    bool ret=pix.load(btnImg);
    if(!ret){
        QString str =QString("图片 %1 加载失败").arg(btnImg);
        qDebug()<<"str";
        return;
    }
    //_配置按钮属性
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}
