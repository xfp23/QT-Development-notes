#ifndef M_TIMER_H
#define M_TIMER_H
#include <QObject>
#include <QTimer>
#include <QMainWindow>
#include <QMap>
#include "mainwindow.h"

/**
 * @file 定时器 提供心跳和定时动作触发功能
 * @note 通过millis() 获取心跳
 * @note 你可以通过方法registerCallback()注册一个回调触发事件
 */

 // 获取心跳
#define millis() Heart.getHeart()
#define __ENABLE_HEART() Heart.begin() // 使能心跳

class M_Timer : public QObject
{
    Q_OBJECT

public:
    M_Timer(); // 构造函数
    ~M_Timer(); // 析构函数
    void start(uint64_t);
    void registerCallback(void (*)(void)); // 注册回调
    void close();
    void AttachUi(Ui::MainWindow *);

    friend void timer1_callback(); // 友元
private slots:
    void TimerCallback(); // 回调函数
    // void heartCallback(); // 心跳

private:
    QTimer* timer; // 普通定时器
    // QTimer* heart; // 心脏
    // volatile uint32_t heartCounts = 0; // 心跳次数
    void (*callback_ptr)(void) = nullptr; // 默认为空
    Ui::MainWindow* ui; // ui 接口

};

class heart_Class : public QObject {
    Q_OBJECT
public:
    heart_Class();
    ~heart_Class();
    uint64_t getHeart();
    void begin();
private:
    volatile uint64_t heartCounts = 0;
    QTimer* heart;
};

extern heart_Class Heart;



#endif
