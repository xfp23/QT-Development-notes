#ifndef NEWWIN_H
#define NEWWIN_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class newWin;
}

class newWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit newWin(QTcpSocket *s,QWidget *parent = 0);
    ~newWin();

public slots:
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);
    void sigsolt(QString data);
private:
    Ui::newWin *ui;
    QTcpSocket * server;
};

#endif // NEWWIN_H
