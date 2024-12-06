#include "newwin.h"
#include "ui_newwin.h"

newWin::newWin(QTcpSocket *s, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newWin)
{
    ui->setupUi(this);
    server = s;
//ui->lineEdit();
}

newWin::~newWin()
{
    delete ui;
}



void newWin::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}


void newWin::sigsolt(QString data )
{
    ui->lineEdit->setText(data);
}