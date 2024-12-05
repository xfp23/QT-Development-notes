#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QMap>
#include <cstdarg>  // 用于处理可变参数
#include <cstdio>   // 用于 vsnprintf
#include "mainwindow.h"

#define UART_TIMEOUT 100  // 串口超时时间 单位：ms
#define BUFFER_SIZE 1024  // 缓冲区大小


    typedef QString COM_Class;  // 定义 COM_Class 为 QString 类型，表示串口名称

    class Serial : public QObject
    {
        Q_OBJECT

    public:
        Serial();  // 构造函数
        ~Serial();  // 析构函数

        // 串口初始化函数
        void begin(COM_Class id, uint32_t baud = 115200);
        void begin(COM_Class id);

        // UI 绑定函数
        void AttachUi(Ui::MainWindow *UI);
        // 串口控制函数
        void close(COM_Class id);  // 关闭串口
        void printf(std::string str, ...);  // 发送格式化数据
        void println(std::string str, ...);  // 发送格式化数据并换行
        void print(std::string str);  // 发送普通数据
        QByteArray ReadaAll(); // 全部读取
        QByteArray Read();  // 单字节读取
        QByteArray readBytes(int byteCount);  // 指定字节读取
        // 串口配置和信息
        QStringList getCOM();  // 获取当前电脑的所有端口
        bool writeBytes(const QByteArray &data);  // 写字节数组
        bool writeByte(uint8_t byte);  // 写单个字节

        // UI 更新槽函数
       // void update_ui();  // 更新 UI 的槽函数

    private slots:

        /**
         * @brief 收到串口数据的回调函数
         **/
        virtual void ReciveCallback();

    private:
        QSerialPort *serial;
        QMap<QString, QSerialPort *> *openPorts;

        Ui::MainWindow *ui;

        void open(COM_Class id);
    };

#endif
