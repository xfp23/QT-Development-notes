# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

# QT定时器

## QObject

- `QObject`是`QT`里面的基本类的父类，然后它提供了一个成员方法叫`startTimer()`,在构造函数里可以直接用`this`指针访问

```cpp
/**
*@brief 启动定时器
*@param 触发周期,几秒触发一次
*@return 定时器编号
*/
this->startTimer(1000);

/**
*@brief 结束定时器
*@param 定时器ID
*/
this->killTimer(timerId);
```

- 重写定时器回调函数

- 回调函数为一个虚函数，可以在任何地方重写它，需要在MainWindow里重新声明它，并在.cpp里重写它的定义
```cpp
class Mainwindow {

public : 
virtual void timerEvent(QTimerEvent *event);
private: 
int myid; // 需要将定时器编号列为私有成员，因为它只在主类成员内部访问
}
// 他的定义
void Mainwindow::timerEvent(QTimerEvent *event)
{
    // 判断是不是想要触发的事件计时到了
    if(event->timerId() == myid)
    {
        // 触发中断函数
    }
}


```

## QTimer

```cpp
#include <QTimer>

class MainWindow: public QMainwindow
{
    // 构造函数
    MainWindow()
    {
        timer = new QTimer ;

        // 连接信号
        /***
        *@brief 连接信号
        *@param 连接哪一个信号
        *@param 连接什么信号
        *@param 谁来处理
        *@param 怎么处理?(回调函数)
        */
        connect(timer,&QTimer::timeout,this,&MainWindow::Timercallback);
    }
    private:
    QTimer *timer;
     private slots:
     void Timercallback();

}


/**
*@brief 启动定时器
*@param 触发ms数
*/
timer->start(1000);
```