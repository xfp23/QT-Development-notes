#ifndef M_THREAD_H
#define M_THREAD_H

#include <QMainWindow>
#include <QObject>
#include <QThread>
#include <QTcpSocket>


class M_Thread : public QThread
{
    Q_OBJECT
public:
    explicit M_Thread(QTcpSocket *Socket);
    ~M_Thread();// 析构函数
   
    void run(); // 重写run函数
signals:

void sigTrigger(QString data); // 信号触发

public slots:

void ThreadRun(); // 槽函数

private: 
 QTcpSocket *socket;
};

#endif // M_THREAD_H
