#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    //自定义构造函数
    PlayScene(int levelNum);

    //内部记录所选关卡的成员变量
    int levelIndex;

    //重写绘图事件
    void paintEvent(QPaintEvent*);

    //二维数组，维护每关卡的具体数据
    int gameArray[4][4];

    //维护每个关卡的具体数组
    MyCoin * coinBtn[4][4];

    //判断是否胜利
    bool isWin=false;

signals:
    void chooseSceneBack();

};

#endif // PLAYSCENE_H
