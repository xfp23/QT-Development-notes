#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    socket(new QTcpSocket(this))
{
    ui->setupUi(this);

    // 绑定信号槽
    setupSocketConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupSocketConnections()
{
    // 连接成功提示
    connect(socket, &QTcpSocket::connected, this, &MainWindow::onConnected);

    // 断开连接提示
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::onDisconnected);

    // 错误处理
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error),
            this, &MainWindow::onError);

}

void MainWindow::on_pushButton_clicked()
{

    static bool flag = false;

    flag = !flag;
    if (!flag)
    {
        socket->disconnectFromHost(); // 正确的断开连接方法
        if (socket->state() != QAbstractSocket::UnconnectedState) {
            // 等待确保连接已断开
            socket->waitForDisconnected();
        }
         ui->pushButton->setStyleSheet("background-color: rgb(0, 255, 0);");
        return;
    }
 ui->pushButton->setStyleSheet("background-color: rgb(0, 255, 0);");
    // 获取 IP 和端口
    QString IP = ui->lineEdit->text();
    QString Port = ui->lineEdit_2->text();

    // 校验输入
    if (IP.isEmpty() || Port.isEmpty()) {
        showMessage("输入错误", "请输入有效的 IP 和端口号");
        return;
    }

    // 尝试连接服务器
    socket->connectToHost(QHostAddress(IP), Port.toUShort());
}

void MainWindow::on_pushButton_2_clicked()
{
    // 获取用户输入并发送数据
    QString sendText = ui->lineEdit_3->text();

    if (sendText.isEmpty()) {
        showMessage("输入错误", "发送内容不能为空");
        return;
    }

    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(sendText.toUtf8());
    } else {
        showMessage("发送失败", "未连接到服务器");
    }
}

void MainWindow::onConnected()
{
    showMessage("连接提示", "连接服务器成功");
}

void MainWindow::onDisconnected()
{
    showMessage("连接提示", "与服务器断开连接");
}

void MainWindow::onError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    showMessage("连接错误", socket->errorString());
}


void MainWindow::showMessage(const QString &title, const QString &message)
{
    QMessageBox::information(this, title, message);
}
