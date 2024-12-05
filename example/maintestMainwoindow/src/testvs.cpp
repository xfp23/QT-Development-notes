#include "testvs.h"

testvs::testvs(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_testvs)
{
    ui->setupUi(this);
}

testvs::~testvs()
{
    delete ui; 
}