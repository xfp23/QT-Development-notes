#include "m_thread.h"


M_Thread::M_Thread(QTcpSocket *Socket)
{
    socket = Socket;
}

M_Thread::~M_Thread()
{
    
}



void M_Thread::run()
{
    qDebug() << "run fuction Trigger";
    connect(socket,&QTcpSocket::readyRead,this,&M_Thread::ThreadRun);
//    connect(socket,&QTcpSocket::disconnected,[=](){
//        this->exit();
//    });

}

void M_Thread::ThreadRun()
{
    qDebug() << "thread read 'Trigger";
    QByteArray data = socket->readAll();
    if(data.isEmpty())
    {
        qDebug() << "message is empty";
        return;
    }
    QString message = QString::fromUtf8(data);

    socket->write("Server received: " + data);
    //qDebug() << message;
    emit sigTrigger(message); // 发送信号
}
