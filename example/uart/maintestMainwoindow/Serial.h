#ifndef SYSTEM_H
#define SYSTEM_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QString>
namespace pxf
{
    typedef QString COM_Class;
    class Serial
    {
        Q_OBJECT

    public:
         Serial();
         ~Serial();
        void begin();
        void begin(uint32_t baud);
        
        void close(COM_Class id); // 关闭端口
        void printf(std::string,...);
        void println(std::string,...);
        void Read(COM_Class id); //
        void print(std::string);
        QStringList getCOM();    // 获取当前电脑的所有端口
                                 // 此处是槽函数
    private slots:

    private:
        QSerialPort *serial;
        QMap<QString, QSerialPort *> openPorts;
        void open(COM_Class id);  // 打开串口
    };
}

#endif
