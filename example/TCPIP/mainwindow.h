#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void setupSocketConnections();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError error);
    void showMessage(const QString &title, const QString &message);
    void onConnected();
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
