#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //重写paintEvent事件 画背景图
    void paintEvent(QPaintEvent *);

    //游戏场景的对象
    PlayScene* playScene=NULL;

signals:
    //写一个自定义的信号，告诉主场景，点击了返回
    void chooseSceneBack();

};

#endif // CHOOSELEVELSCENE_H
