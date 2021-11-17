#include "chooselevelscene.h"

#include <QMenuBar>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    //配置窗口
    //_配置选择关卡场景
    this->setFixedSize(320,588);
    //_设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //_设置标题
    this->setWindowTitle("选择关卡场景");

    //配置菜单
    //_创建菜单栏
    QMenuBar* bar=menuBar();
    setMenuBar(bar);
    //_创建开始菜单
    QMenu* startMenu=bar->addMenu("开始");
    //_创建退出菜单项
    QAction* quitAction=startMenu->addAction("退出");
    //_点击退出 实现退出游戏
    connect(quitAction,&QAction::triggered,this,[=](){
        this->close();
    });

}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{

}
