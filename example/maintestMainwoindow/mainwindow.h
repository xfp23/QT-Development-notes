#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QSerialPort>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);

private slots:
    void on_pushButton_clicked();
    void OpenFileEvent(); // 打开
    void CreateFileEvent(); // 新建
private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTimer *timer;
    QTimer * heart;
};

#endif // MAINWINDOW_H
