# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

---

# QT 串口的读写

## 环境配置

1. 打开工程中的 `.pro` 文件，在 `QT` 变量中添加 `serialport` 模块。
   ```pro
   QT += serialport
   ```

2. 确保你的 Qt 环境支持 `QSerialPort` 模块。如果没有安装，你需要使用 Qt Creator 的工具管理器来添加该模块。

## 串口配置

在使用 `QSerialPort` 之前，需要进行一些基本的串口配置，设置串口的波特率、数据位、停止位等。

```cpp
#include <QSerialPort>
#include <QSerialPortInfo>

QSerialPort *serialPort = new QSerialPort(this); // 创建串口对象

// 设置串口名称，获取可用串口列表
serialPort->setPortName("COM1"); // 使用 COM1 串口，根据实际情况设置

// 设置波特率、数据位、停止位等
serialPort->setBaudRate(QSerialPort::Baud9600); // 波特率
serialPort->setDataBits(QSerialPort::Data8);    // 数据位
serialPort->setParity(QSerialPort::NoParity);   // 校验位
serialPort->setStopBits(QSerialPort::OneStop);  // 停止位
serialPort->setFlowControl(QSerialPort::NoFlowControl); // 流控制
```

## 打开串口

在进行串口操作之前，必须打开串口。可以选择读取或写入模式。

```cpp
if (serialPort->open(QIODevice::ReadWrite)) {
    qDebug() << "串口已成功打开！";
} else {
    qDebug() << "串口打开失败: " << serialPort->errorString();
}
```

## 连接信号

使用 Qt 的信号与槽机制，连接串口数据读取的信号。每当串口有数据可读取时，`readyRead` 信号会被触发。

```cpp
// 此信号用来触发串口读取信号
connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
```

## 读取串口数据

通过 `readyRead` 信号触发的槽函数来读取串口数据：

```cpp
void MainWindow::readSerialData()
{
    QByteArray data = serialPort->readAll(); // 读取所有可用的数据
    qDebug() << "收到数据: " << data;

    // 可以根据需要处理数据，例如显示在界面上
    ui->textEdit->append(data);
}
```

在这个例子中，读取到的数据会显示在一个文本编辑框 `textEdit` 中。你也可以根据需求对数据进行其他处理。

## 写入串口数据

通过 `QSerialPort` 提供的 `write` 方法，可以将数据写入串口。

```cpp
void MainWindow::sendData()
{
    QByteArray data = "Hello, Serial Port!"; // 要发送的数据
    serialPort->write(data); // 发送数据
}
```

调用 `write` 后，数据会被发送到串口设备。

## 关闭串口

当串口操作完成后，可以关闭串口。

```cpp
serialPort->close();
qDebug() << "串口已关闭";
```

关闭串口是一个好习惯，可以确保串口资源得到释放。

## 错误处理

在串口操作中，可能会遇到一些错误。可以通过 `error()` 方法来获取详细的错误信息：

```cpp
connect(serialPort, &QSerialPort::errorOccurred, this, &MainWindow::handleError);

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        qDebug() << "串口错误: " << serialPort->errorString();
    }
}
```

## 完整示例代码

```cpp
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent)
    {
        serialPort = new QSerialPort(this);
        
        // 配置串口
        serialPort->setPortName("COM1");
        serialPort->setBaudRate(QSerialPort::Baud9600);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);

        // 连接信号
        connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
        connect(serialPort, &QSerialPort::errorOccurred, this, &MainWindow::handleError);

        // 打开串口
        if (serialPort->open(QIODevice::ReadWrite)) {
            qDebug() << "串口已成功打开！";
        } else {
            qDebug() << "串口打开失败: " << serialPort->errorString();
        }
    }

    ~MainWindow()
    {
        if (serialPort->isOpen()) {
            serialPort->close();
        }
        delete serialPort;
    }

private slots:
    void readSerialData()
    {
        QByteArray data = serialPort->readAll();
        qDebug() << "收到数据: " << data;
        ui->textEdit->append(data);
    }

    void sendData()
    {
        QByteArray data = "Hello, Serial Port!";
        serialPort->write(data);
    }

    void handleError(QSerialPort::SerialPortError error)
    {
        if (error != QSerialPort::NoError) {
            qDebug() << "串口错误: " << serialPort->errorString();
        }
    }

private:
    QSerialPort *serialPort;
};
```


通过配置 `QSerialPort`，你可以方便地进行串口的读写操作。使用 `readyRead` 信号触发数据读取，`write` 方法发送数据。`QSerialPort` 提供了错误处理机制，确保串口操作的稳定性。