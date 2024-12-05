#-------------------------------------------------
#
# Project created by QtCreator 2024-11-29T17:48:24
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = maintestMainwoindow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        Serial.cpp \
        system.cpp \
        M_Timer.cpp

HEADERS += \
        mainwindow.h \
        Serial.h \
        system.h \
        M_Timer.h

FORMS += \
        mainwindow.ui
 #include (./QXlsx\QXlsx.pri)

# QXlsx code for Application Qt project

QXLSX_PARENTPATH=./         # current QXlsx path is . (. 表示当前目录)

QXLSX_HEADERPATH=./header/  # 当前目录下的header子目录

QXLSX_SOURCEPATH=./source/  # 当前目录下的source子目录

include(./QXlsx.pri) #.pri文件应该包含了QXlsx库的配置信息

RESOURCES += \
    image.qrc
