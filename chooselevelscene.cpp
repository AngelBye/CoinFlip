#include "chooselevelscene.h"
#include "mypushbutton.h"

#include <QLabel>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <playscene.h>

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

    //配置返回按钮
    //_按钮初始化
    MyPushButton* backBtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    //_监听返回按钮
    connect(backBtn,&MyPushButton::clicked,this,[=](){
       emit this->chooseSceneBack();
    });

    //创建选择关卡的按钮
    for(int i=0;i<20;i++){
        MyPushButton * menuBtn=new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,130+i/4*70);
        menuBtn->setParent(this);
        QLabel* label=new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+i%4*70,130+i/4*70);

        //设置label上的文字对齐方式
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //设置让鼠标进行穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);



        //监听每个按钮的点击事件
        connect(menuBtn,&MyPushButton::clicked,this,[=](){
            QString str=QString("您选择的是第%1关").arg(i+1);
            qDebug()<<str;
            playScene=new PlayScene(i+1);
            //进入到游戏场景
            QTimer::singleShot(500,this,[=]()
            {
                //_设置游戏场景初始位置
                playScene->setGeometry(this->geometry());
                //_隐藏自身
                this->hide();
                //_自身游戏场景
                playScene->show();
                //监听游戏场景的返回信号
                connect(playScene,&PlayScene::chooseSceneBack,this,[=](){
                    //延时进入到选择场景中
                    QTimer::singleShot(500,this,[=]()
                    {
                        //_选择关卡位置初始化
                        this->setGeometry(playScene->geometry());
                        //_隐藏选择关卡场景
                        playScene->hide();
                        //_自身显示
                        this->show();
                        //清除游戏场景
                        delete playScene;
                        playScene=NULL;
                    });

                });
            });


        });



    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);


}
