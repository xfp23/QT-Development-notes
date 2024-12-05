# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

# 服务端(Server)

- 本文档演示如何创建一个TCP/IP的服务端

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

- 构造函数:

```cpp
    server = new QTcpServer(this);

    /**
     *@brief 指定监听端口
     *@param 选择网卡，这里是监听IPV4网卡的ip地址
     *@param 8000端口
     * 
     */
    server->listen(QHostAddress::ConvertV4CompatToIPv4,8000); // 指定监听网卡和端口
        if (!server->listen(QHostAddress::AnyIPv4, 8000)) {
        qDebug() << "Server failed to start:" << server->errorString();
        QMessageBox::critical(this, "Server Error", "Unable to start the server: " + server->errorString());// 获取服务器错误信息
        return;
    }
    /**
     *@brief 绑定槽函数
     *@param 对象
     *@param 新的连接触发事件
     *@param this
     *@param 槽函数,服务器建立连接的时候触发
     */
    connect(server,&QTcpServer::newConnection,this,&MainWindow::serverCallback); 
```

- 回调函数的实现

```cpp
void MainWindow::serverCallback()
{
    // 获取新的客户端连接
    QTcpSocket *socket = server->nextPendingConnection();

    // 显示客户端地址和端口
    ui->label_3->setText(socket->peerAddress().toString());
    ui->label_5->setText(QString::number(socket->peerPort()));

    // 绑定接收数据和断开连接的信号槽
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readData); // 此处绑定槽函数实现接收逻辑
    connect(socket, &QTcpSocket::disconnected, [this, socket]() {   // 此处是断开服务器连接的回调
        qDebug() << "Client disconnected:" << socket->peerAddress().toString(); // 弹出信息
        QMessageBox::critical(this, "连接提示", "客户端断开连接");
        socket->deleteLater(); // 清理资源
    });
```


- 接收槽函数的实现

```cpp
void MainWindow::readData()
{
    // 获取信号发送者（对应客户端）
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (!socket) return; // 无客户端，退出函数

    // 读取数据
    QByteArray data = socket->readAll();
    if (data.isEmpty()) return; // 数据为空退出函数

    // 转换为字符串并显示
    QString message = QString::fromUtf8(data);
    qDebug() << "Received data from" << socket->peerAddress().toString() << ":" << message;
    ui->textBrowser->append("Client: " + message);

    // 可在此处理协议逻辑，比如回显数据
     socket->write("Server received: " + data); // 这里是给客户端发数据
     
}
```

