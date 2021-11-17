#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //重写paintEvent事件 画背景图
    void paintEvent(QPaintEvent *);

signals:

};

#endif // CHOOSELEVELSCENE_H
