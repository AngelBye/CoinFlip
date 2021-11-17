#include "mainscene.h"
#include "mypushbutton.h"
#include "ui_mainscene.h"
#include <QAction>
#include <QPainter>
#include <QTimer>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景
    //_设置固定大小
    setFixedSize(320,588);
    //_设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //_设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionQuit,&QAction::triggered,this,[=](){
        this->close();
    });

    //创建选择场景对象
    chooseScene=new ChooseLevelScene;

    //开始按钮
    MyPushButton* startBtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7-startBtn->height()*0.7);
    connect(startBtn,&MyPushButton::clicked,[=](){
        //按钮弹跳特效
        startBtn->zoomUp();
        startBtn->zoomDown();

        //延时进入到选择关卡场景中

        QTimer::singleShot(500,this,[=](){
            //_自身隐藏
            this->hide();
            //_显示选择关卡场景
            chooseScene->show();
        });


    });
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *)
{
    //画背景图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
}

