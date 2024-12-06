# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

- [多线程扩展](./RTOS_EX.MD)

**在多线程操作中我们不建议把其它资源如`ui`当作指针传递到线程中，因为此类操作可能触发资源竞争**
- 如何解决? 可以使用新的信号，自己自定义一个信号，可查看此文档
[自定义信号解决资源竞争问题](/DIY_SIG/DIY_SIGNAL.MD)

# QT多线程

## 环境准备

- 创建多线程，需要在自己的项目中写一个线程类，继承自`QObject`类

- 选择添加新文件，选择添加`c++ class`

- 选择继承自`QObject`类

- `QT`会自动帮我们生成文件

- 添加头文件

```cpp

#include <QObject>
#include <QThread>

```

## 编辑头文件

1. 自己的线程类除了要继承`QObject`类之外还需要继承`QThread`类

- 更改类

```cpp
class M_Thread : public QThread
{
    Q_OBJECT
public:
    explicit M_Thread();

signals:

public slots:
};

```


2. 重写`run()`函数

- 1. run()函数是个虚函数，在此处被重写，我们程序中不需要调用它，它是线程启动后自动被执行的
```cpp

void M_Thread::run()
{
    qDebug() << "run fuction Trigger";
    connect(socket,&QTcpSocket::readyRead,this,&M_Thread::ThreadRun); // 连接合适的槽函数
//    connect(socket,&QTcpSocket::disconnected,[=](){
//        this->exit();
//    });

}

```

- 3. 启动线程

- 设定合理的逻辑来启动自己的线程

```cpp

M_Thtrad  * = new M_Thtrad(/*填写自己写的需要传递的参数*/);
this->start();

```
