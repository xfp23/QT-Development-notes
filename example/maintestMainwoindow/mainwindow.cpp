#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Serial.h"
#include <QKeyEvent>
#include "M_Timer.h"
#include <QImage>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextEdit>


QImage HAIBARA;
Serial port;
M_Timer timer1;

void timer1_callback()
{
    static bool flage = false;
    if (flage)
    {


        qDebug() << "1";
        /*显示第一张图片*/
        timer1.ui->label_new->setStyleSheet("border-image: url(:/new/prefix1/pic/HAIBARA1.jpg);");
        timer1.ui->text->setStyleSheet("border-image: url(:/new/prefix1/pic/HAIBARA 2.jpg);"); // 显示
    }
    else {

        qDebug() << "2";
        timer1.ui->label_new->setStyleSheet("border-image: url(:/new/prefix1/pic/HAIBARA 2.jpg);"); // 显示
        timer1.ui->text->setStyleSheet("border-image: url(:/new/prefix1/pic/HAIBARA1.jpg);"); // 显示
    }


    flage = !flage;
    static uint8_t count = 0;
    QByteArray logBuffer;
    logBuffer = "hearts dump : counts " + QByteArray::number(millis());

    // 构建文件路径
    QString filePath = QString("C:/Users/xfp57/Desktop/qttest/qtfile/%1.txt").arg(count);

    // 打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(nullptr, "错误", "无法打开日志文件进行保存！");
        qDebug() << "file error !";
        return;
    }

    // 写入日志
    QTextStream out(&file);
    out << QString::fromUtf8(logBuffer) << "\n";

    file.close(); // 确保关闭文件
    count++;
}

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    __ENABLE_HEART();
    ui->setupUi(this);
    port.AttachUi(ui);
    connect(ui->OpenFile,&QAction::triggered,this,&MainWindow::OpenFileEvent);
    connect(ui->CreateFile,&QAction::triggered,this,&MainWindow::CreateFileEvent);
    timer1.AttachUi(ui);
    timer1.registerCallback(timer1_callback);
    timer1.start(2000);


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{

}
// 串口回调
void Serial::ReciveCallback()
{
    QByteArray readbyte = port.ReadaAll();
    ui->text->append(readbyte);
}

// ctrl + s 快捷键
void MainWindow::keyPressEvent(QKeyEvent* key)
{
    // 获取热键                                      获取普通按键
    if (key->modifiers() == Qt::ControlModifier && key->key() == Qt::Key_S)
    {

    }
}


void MainWindow::OpenFileEvent()
{
    qDebug() << "OPen a file";
    QString fileName = QFileDialog::getOpenFileName(this, "选择一个文件", QCoreApplication::applicationFilePath(), "*.*");
    // 检查文件名是否为空
    if (fileName.isEmpty()) {
        // 弹出警告信息
        QMessageBox::warning(this, "警告", "请选择一个文件");
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite)) {
        // 如果打开失败，弹出错误提示
        QMessageBox::warning(this, "错误", "无法打开文件！");
        return;
    }
    QByteArray fileCountent = file.readAll();
    ui->textEdit->setText(fileCountent);
    file.close();
}

void MainWindow::CreateFileEvent()
{
    qDebug() << "Create a file";
QString fileName = QFileDialog::getSaveFileName(this, "保存文件", QCoreApplication::applicationFilePath(), "*.*");
QFile file(fileName);
if (!file.open(QIODevice::ReadWrite)) {
    // 如果打开失败，弹出错误提示
    QMessageBox::warning(this, "错误", "无法写入文件！");
    return;
}
QString textContent = ui->textEdit->toPlainText();
file.write(textContent.toUtf8());
file.close();
}
