#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newwin.h"
#include "m_thread.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化服务器
    server = new QTcpServer(this);


    // 尝试监听所有网卡上的端口 8000
    if (!server->listen(QHostAddress::AnyIPv4, 8000)) {
        qDebug() << "Server failed to start:" << server->errorString();
        QMessageBox::critical(this, "Server Error", "Unable to start the server: " + server->errorString());
        return;
    }

    qDebug() << "Server is listening on port" << server->serverPort();

    // 绑定新连接的信号槽
    connect(server, &QTcpServer::newConnection, this, &MainWindow::serverCallback);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serverCallback()
{
    // 获取新的客户端连接
    QTcpSocket *socket = server->nextPendingConnection();

    // 显示客户端地址和端口
    ui->label_3->setText(socket->peerAddress().toString());
    ui->label_5->setText(QString::number(socket->peerPort()));

    // 绑定接收数据和断开连接的信号槽
    //connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readData);
    connect(socket, &QTcpSocket::disconnected, [this, socket]() {
        qDebug() << "Client disconnected:" << socket->peerAddress().toString();
        QMessageBox::critical(this, "连接提示", "客户端断开连接");
        socket->deleteLater(); // 清理资源
         chat->close();
        MainWindow::show();

    });
     chat = new newWin(socket);
     this->hide();
     chat->show();
     
    qDebug() << "New client connected:" << socket->peerAddress().toString() << ":" << socket->peerPort();
     M_Thread * thread = new M_Thread(socket);
     connect(thread,&M_Thread::sigTrigger,chat,&newWin::sigsolt);
     //thread->AttachUi(dynamic_cast<Ui::newWin *>(chat));
     //thread->run();
     thread->start();
}

void MainWindow::readData()
{
    
    // // 获取信号发送者（对应客户端）
//    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
//     if (!socket) return;

    // // 读取数据
    // QByteArray data = socket->readAll();
    // if (data.isEmpty()) return;

    // // 转换为字符串并显示
    // QString message = QString::fromUtf8(data);
    // qDebug() << "Received data from" << socket->peerAddress().toString() << ":" << message;
    // ui->textBrowser->append("Client: " + message);

    // // 可在此处理协议逻辑，比如回显数据
    // socket->write("Server received: " + data);

//    M_Thread * thread = new M_Thread(socket);
//    thread->AttachUi(dynamic_cast<Ui_newWin *>(chat));
//    thread->run();
//    thread->start();
     qDebug() << "newwindow read 'Trigger";
}
