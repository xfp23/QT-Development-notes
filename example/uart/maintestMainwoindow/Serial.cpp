#include "System.h"
using namespace pxf;

Serial::Serial()
{
    serial = new QSerialPort(this);
    openPorts = new QMap<QString, QSerialPort *>();
}

void Serial::~Serial()
{
    delete serial;
    delete openPorts;
}

void Serial::begin(COM_Class id)
{
    open(id);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}

void Serial::begin(COM_Class id, uint32_t baud)
{
        open(id);
    serial->setBaudRate((BaudRate)baud);
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
    if (openPorts.contains(id))
    {
        openPorts[id]->close();
        openPorts.remove(id);
    }
}

void Serial::open(COM_Class id)
{
    // 检查串口是否已经打开
    if (serial->isOpen())
    {
        qDebug() << "串口已经打开，无法重新打开";
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


void Serial::printf(std::string str,...)
{

}

void Serial::println(std::string str,...)
{

}

void Serial::print(std::string str)
{

}
