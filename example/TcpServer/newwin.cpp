#include "newwin.h"
#include "ui_newwin.h"

newWin::newWin(QTcpSocket *s, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newWin)
{
    ui->setupUi(this);
    server = s;
}

newWin::~newWin()
{
    delete ui;
}
