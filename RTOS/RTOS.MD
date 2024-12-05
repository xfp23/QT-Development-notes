# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

- [多线程扩展](./RTOS_EX.MD)

# QT多线程

## 环境准备

- 创建多线程，需要在自己的项目中写一个线程类，继承自`QObject`类

- 选择添加新文件，选择添加`c++ class`

- 选择继承自`QObject`类

- `QT`会自动帮我们生成文件

- 添加头文件

```cpp

#include <QObject>
#include <QThread>

```

## 编辑头文件

1. 自己的线程类除了要继承`QObject`类之外还需要继承`QThread`类

- 更改类

```cpp
class M_Thread : public QObject,public QThread
{
    Q_OBJECT
public:
    explicit M_Thread(QObject *parent = nullptr);

signals:

public slots:
};

```

