#include "M_Timer.h"
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

// static bool heart_flag = false; // 心跳开启与否标志

heart_Class Heart;


M_Timer::M_Timer()
{
   timer = new QTimer(this);
   connect(timer, &QTimer::timeout, this, &M_Timer::TimerCallback);
   // heart = nullptr;
   // if(!heart_flag)
   // {
   // heart = new QTimer(this);
   // connect(heart,&QTimer::timeout,this,M_Timer::heartCallback);
   // heart->start(1);// 开始心跳
   // heart_flag = true;
   // }
}

M_Timer::~M_Timer()
{
   delete timer;
   // delete heart;
}

void M_Timer::start(uint64_t ms)
{
   if (ms > UINT64_MAX)
   {
       qDebug() << "Out of range failed";
       return;
   }
   timer->start(ms);
}

void M_Timer::close()
{
   timer->stop();
}


// 心跳回调
// void M_Timer::heartCallback()
// {
//     //qDebug() << "heart counts : ";
//     heartCounts++;
// }

// 定时器回调函数
void M_Timer::TimerCallback()
{
   if(callback_ptr != nullptr)
   {
      callback_ptr();
   }
}

void M_Timer::AttachUi(Ui::MainWindow *UI)
{
   ui = UI;
}

void M_Timer::registerCallback(void (*callback)(void))
{
   callback_ptr = callback;
}

// uint32_t M_Timer::getHeart()
// {
//    return heartCounts;
// }


heart_Class::heart_Class()
{
   //heartCounts++;
}

void heart_Class::begin()
{
   heart = new QTimer(this);
   heartCounts = 0;
      heart->start(1); // 开始心跳
   connect(heart,QTimer::timeout,[=](){
      heartCounts++;
      //qDebug() << "heart Tigger : " << millis();
   });
}

heart_Class::~heart_Class()
{
   delete heart;
}

uint64_t heart_Class::getHeart()
{
   static uint64_t time;
   time = heartCounts;
   return time;
}
