#pragma once
#include "ui_testvs.h"
#include <QMainWindow>

class testvs : public QMainWindow {
    Q_OBJECT
    
public:
    testvs(QWidget* parent = nullptr);
    ~testvs();

private:
    Ui_testvs* ui;
};