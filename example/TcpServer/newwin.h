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

private:
    Ui::newWin *ui;
    QTcpSocket * server;
};

#endif // NEWWIN_H
