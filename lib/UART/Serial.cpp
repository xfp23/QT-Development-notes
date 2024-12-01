#include "Serial.h"
#include <QDebug>
#include "ui_mainwindow.h"
Serial::Serial()
{
    serial = new QSerialPort(this);
    openPorts = new QMap<QString, QSerialPort *>();
    ui = nullptr; // 默认为空，防止程序崩溃
    connect(serial,&QSerialPort::readyRead,this,&Serial::ReciveCallback);
}

Serial::~Serial()
{
    delete serial;
    delete openPorts;
}


void Serial::begin(COM_Class id)
{
    begin(id, 115200);  // 使用默认波特率
}

void Serial::begin(COM_Class id, uint32_t baud)
{
    open(id);
    serial->setBaudRate(static_cast<QSerialPort::BaudRate>(baud));
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}

QStringList Serial::getCOM()
{
    QStringList portNames;
    for (const QSerialPortInfo &port : QSerialPortInfo::availablePorts())
    {
        portNames.append(port.portName());
    }
    return portNames;
}

void Serial::close(COM_Class id)
{
    if (openPorts->contains(id))
    {
        openPorts->value(id)->close();  // 使用 value() 来获取对应的 QSerialPort

        openPorts->remove(id);
    }
}

void Serial::open(COM_Class id)
{
    // 检查串口是否已经打开
    if (serial->isOpen())
    {
        //qDebug() << "串口已经打开，无法重新打开";
        return;
    }

    serial->setPortName(id);

    // 尝试打开串口
    if (serial->open(QIODevice::ReadWrite))
    {
        qDebug() << "串口" << id << "打开成功";
    }
    else
    {
        qDebug() << "无法打开串口" << id << ": " << serial->errorString();
    }
}

void Serial::printf(std::string str, ...)
{
    if (!serial->isOpen())
    {
        return;
    }
    char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, str);
    vsnprintf(buffer, sizeof(buffer), str.c_str(), args);
    va_end(args);
    QByteArray data = QByteArray::fromStdString(buffer);
    serial->write(data);
}

void Serial::println(std::string str, ...)
{
    if (!serial->isOpen())
    {
        qDebug() << "串口未打开，无法发送数据";
        return;
    }
    char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, str);
    vsnprintf(buffer, sizeof(buffer), str.c_str(), args);
    va_end(args);
    QString formattedData = QString::fromStdString(buffer) + "\n";
    QByteArray data = formattedData.toUtf8();
    serial->write(data);
}

void Serial::print(std::string str)
{
    if (!serial->isOpen())
    {
        qDebug() << "串口未打开，无法发送数据";
        return;
    }
    QString data = QString::fromStdString(str);
    QByteArray byteData = data.toUtf8();
    qDebug() << byteData;
    serial->write(byteData);
}

// 写字节
bool Serial::writeBytes(const QByteArray &data)
{
    if (!serial->isOpen())
    {
        qDebug() << "串口未打开，无法发送数据";
        return false;
    }

    serial->write(data);
    qDebug() << "发送字节数组：" << data.toHex().toUpper();
    return true;
}

bool Serial::writeByte(uint8_t byte)
{
    return writeBytes(QByteArray(1, static_cast<char>(byte)));  // 使用公共函数
}

void Serial::update_ui()
{
    static bool color = true;
    if(ui == nullptr)
    {
        return;
    }
    if(color == true)
    {
        ui->text->setStyleSheet("background-color:rgb(255,0,0);");
    } else if(color == false)
    {
       ui->text->setStyleSheet("background-color:rgb(0,255,0);");
    }
    color = !color;
    ui->text->append("发送成功");
}

QByteArray Serial::ReadaAll()
{
    if (!serial->isOpen())  // 检查串口是否已打开
    {
        return QByteArray();  // 如果串口没有打开，返回空字节数组
    }

    QByteArray data = serial->readAll();  // 读取所有可用数据
    while (serial->bytesAvailable())  // 如果有更多数据可读
    {
        data.append(serial->readAll());  // 继续读取并追加到数据中
    }

    return data;  // 返回读取到的所有数据
}

// 单字节读取串口信息
QByteArray Serial::Read()
{
    QByteArray buffer; // 单字节
    if (!serial->isOpen())
    {
        return buffer;
    }
    if (serial->waitForReadyRead(UART_TIMEOUT))
    {
        buffer = serial->read(1);
    }
    return buffer;
}

void Serial::AttachUi(Ui::MainWindow *UI)
{
    if(UI == nullptr)
    {
        return;
    }
    ui = UI;
}

QByteArray Serial::readBytes(int byteCount)
{
    if (!serial->isOpen())  // 检查串口是否已打开
    {
        return QByteArray();  // 如果串口没有打开，返回空字节数组
    }

    QByteArray data;  // 存储接收到的数据
    int remainingBytes = byteCount;  // 需要读取的字节数

    while (remainingBytes > 0)  // 如果还有字节未读取
    {
        // 尝试读取剩余的字节数
        QByteArray chunk = serial->read(remainingBytes);
        data.append(chunk);  // 将读取到的数据追加到 data 中
        remainingBytes -= chunk.size();  // 减少剩余字节数

        // 如果已经读取到预期字节数或超时，则退出循环
        if (remainingBytes <= 0) {
            break;
        }

        // 如果数据不足，则等待更多的数据准备好
        if (!serial->waitForReadyRead(UART_TIMEOUT)) {
            // 等待超时，返回已接收到的数据
            break;
        }
    }

    return data;  // 返回读取到的字节数据
}
