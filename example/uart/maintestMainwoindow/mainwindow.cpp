#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Serial.h"

using namespace pxf;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
