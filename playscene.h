#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPaintEvent>

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

    //记录币的位置
    int posX;
    int posY;
    bool flag;

signals:
    void chooseSceneBack();

};

#endif // PLAYSCENE_H
