# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。


# 启动新窗口

## 新建添加源文件

1. 右键`Forms`文件夹,选择添加新文件

2. 选择`QT`->`QT设计师界面类`

3. 选择自己要添加的类型，添加窗口根据项目选择`MainWindow`或者`Widget`

4. 合适的进行命名后就可以了，qt会自动添加文件到项目中，新的界面编辑ui在新出现的ui文件中

## 程序API

- 通过合理的传参，将自己在当前界面的对象传递到新窗口中进行操作,指针传递，例如:

```cpp
     chat = new newWin(socket); // 因为chat窗口中也要操作socket对象，所以在构造函数中创建堆内存的时候也传递了socket对象
     this->hide(); //此方法隐藏当前窗口
     chat->show(); //显示新窗口
     this->close(); // 关闭当前窗口，不销毁对象
     //如果想要销毁当前对象直接 delete,前提得是指针
     delete chat;
```

```cpp
    connect(socket, &QTcpSocket::disconnected, [this, socket]() {
        qDebug() << "Client disconnected:" << socket->peerAddress().toString();
        QMessageBox::critical(this, "连接提示", "客户端断开连接");
        socket->deleteLater(); // 清理资源
        delete chat; // 释放对象就是关闭了
        chat.close(); // 这样只关闭窗口不释放对象，根据具体场景来
        MainWindow::show();

    });
```
