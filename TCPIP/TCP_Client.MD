# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

# 客户端(Server)

## 1. 环境准备

- 配置qmake,新增这样一句话

```qmake
QT       += network
```

- 添加头文件

```c
#include <QTcpServer>
#include <QTcpSocket>

```

## 2. 编写代码

- 绑定槽函数
```cpp

    // 连接成功提示
    connect(socket, &QTcpSocket::connected, this, &MainWindow::onConnected); // 绑定连接成功的槽函数

    // 断开连接提示
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::onDisconnected); // 绑定意外断开连接的槽函数

    // 错误处理
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error),
            this, &MainWindow::onError);// 绑定错误处理槽函数 ，是c++ dynamic_cast 语法的扩展

```

- 常用API的调用

```cpp

```


- 槽函数的实现

```cpp

// 显示弹窗函数
void MainWindow::showMessage(const QString &title, const QString &message)
{
    QMessageBox::information(this, title, message);
}
// 连接成功的回调
void MainWindow::onConnected()
{
    showMessage("连接提示", "连接服务器成功");
}
// 断开连接的回调
void MainWindow::onDisconnected()
{
    showMessage("连接提示", "与服务器断开连接");
}

// 显示出错函数回调，
void MainWindow::onError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError); // 将弹窗设为报错
    showMessage("连接错误", socket->errorString());
}
```

- 连接至服务器

```cpp

    QString IP = ui->lineEdit->text();
    QString Port = ui->lineEdit_2->text();

    // 校验输入
    if (IP.isEmpty() || Port.isEmpty()) {
        showMessage("输入错误", "请输入有效的 IP 和端口号");
        return;
    }

    // 尝试连接服务器
    socket->connectToHost(QHostAddress(IP), Port.toUShort()); // 连接成功会触发绑定的槽函数
}


```

- 主动断开连接

```cpp
        socket->disconnectFromHost(); // 正确的断开连接方法
        if (socket->state() != QAbstractSocket::UnconnectedState) {
            // 等待确保连接已断开
            socket->waitForDisconnected();

```