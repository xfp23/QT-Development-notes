# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

# QT自定义信号

- 只要是对象，就能发出信号

- QT自带的信号种类有限，不能满足某些场景需求

# 自定义信号步骤

1. 一定要记住，不论是哪个类，只要它是对象，他就能发出信号

- 这里我以`M_Thread`类为例


```cpp
class M_Thread : public QThread // 其它自己创建类继承QObject类
{
    Q_OBJECT // 必须包含这个宏定义
public:
    explicit M_Thread(QTcpSocket *Socket);
    ~M_Thread();// 析构函数
   
    void run(); // 重写run函数
signals: // 信号在此关键字下声明，本质上还是函数

void sigTrigger(QString data); // 信号触发，参数是要发送的数据

public slots:

void ThreadRun(); // 槽函数

private: 
 QTcpSocket *socket;
};


```

2. 完成信号函数的定义

- 这个函数是槽函数，然后自定义信号是通过槽函数的调用而实现的

```cpp

void M_Thread::ThreadRun()
{
    qDebug() << "thread read 'Trigger";
    QByteArray data = socket->readAll();
    if(data.isEmpty())
    {
        qDebug() << "message is empty";
        return;
    }
    QString message = QString::fromUtf8(data);

    socket->write("Server received: " + data);
    //qDebug() << message;
    emit sigTrigger(message); // 发送信号
}

```

3. 连接自己的信号

```cpp

     M_Thread * thread = new M_Thread(socket);
     connect(thread,&M_Thread::sigTrigger,chat,&newWin::sigsolt);

```

