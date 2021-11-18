#include "mycoin.h"
#include "mypushbutton.h"
#include "playscene.h"
#include "dataconfig.h"
#include <QAction>
#include <QDebug>
#include <QFont>
#include <QLabel>
#include <QMenuBar>
#include <QPainter>
#include <QPixmap>


//PlayScene::PlayScene(QWidget *parent)
//    : QMainWindow{parent}
//{

//}

PlayScene::PlayScene(int levelNum)
{
    //存储游戏关数
    this->levelIndex=levelNum;
    QString str=QString("进入了%1关").arg(levelNum);
    qDebug()<<str;

    //初始化每个头卡的数组
    DataConfig* dataConfig=new DataConfig;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            gameArray[i][j]=dataConfig->mData[this->levelIndex][i][j];
        }
    }

    //初始化游戏场景
    //_设置固定大小
    this->setFixedSize(320,588);
    //_设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //_设置标题
    this->setWindowTitle("翻金币场景");

    //创建菜单栏
    //_初始化菜单栏
    QMenuBar* bar=menuBar();
    setMenuBar(bar);
    //_创建开始菜单
    QMenu* startMenu=bar->addMenu("开始");
    //_创建按钮菜单项
    QAction* quitAction=startMenu->addAction("退出");
    //点击退出 退出游戏
    connect(quitAction,&QAction::triggered,this,[=](){
        this->close();
    });

    //配置返回按钮
    //_返回按钮初始化
    MyPushButton* closeBtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());
    //_监听返回按钮
    connect(closeBtn,&MyPushButton::clicked,this,[=](){
        this->hide();
        //__触发自定义信号，关闭自身。
        emit this->chooseSceneBack();
    });

    //显示当前的关卡数
    //_初始化QLabel
    QLabel* label=new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString levelStr=QString("Leavel: %1").arg(this->levelIndex);
    label->setText(levelStr);
    label->setGeometry(QRect(30,this->height()-50,120,50));

    //显示金币背景图案
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            //_绘制背景图片
            QPixmap pix=QPixmap(":/res/BoardNode.png");
            QLabel* label=new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            //创建币
            QString img;
            if(gameArray[i][j]==1){
            //_连接金币资源
            img=":/res/Coin0001.png";
            }
            else{
            //_连接银币资源
            img=":/res/Coin0008.png";
            }
            MyCoin* coin=new MyCoin(img);
            coin->setParent(this);
            coin->move(59+i*50,204+j*50);
            //_记录当前币的值
            coin->posX=i;
            coin->posY=j;
            coin->flag=gameArray[i][j];
            //监听金币翻转动作
            connect(coin,&MyCoin::clicked,this,[=](){
                coin->changeFlag();
            });
        }
    }    
}

void PlayScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);

}
