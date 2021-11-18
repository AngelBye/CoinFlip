#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QPushButton *parent = nullptr);

    //重写构造函数 传入的金币路径 还是银币路径
    MyCoin(QString btnImg);


signals:

};

#endif // MYCOIN_H
