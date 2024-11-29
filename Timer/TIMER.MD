
---

# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

---

# QT 定时器

Qt 提供了两种常见的定时器机制：`QObject::startTimer()` 和 `QTimer`。这两者的功能相似，但实现方式有所不同，下面将详细讲解它们的使用方式。

## 1. `QObject` 定时器

`QObject` 类是 Qt 的基础类，它为应用程序提供了与对象之间的信号和槽机制。`QObject` 提供了 `startTimer()` 和 `killTimer()` 方法来启动和停止定时器。

### 启动定时器

```cpp
/**
 * @brief 启动定时器
 * @param 触发周期, 毫秒为单位 (如：1000表示每秒触发一次)
 * @return 定时器编号
 */
this->startTimer(1000);  // 启动定时器，每1000ms触发一次
```

### 停止定时器

```cpp
/**
 * @brief 结束定时器
 * @param 定时器ID
 */
this->killTimer(timerId);  // 停止定时器，根据定时器编号
```

### 定时器事件回调

`QObject` 的定时器基于事件机制，定时器触发时，会调用 `timerEvent` 函数。你需要重写该函数来处理定时器触发的逻辑。

```cpp
class MainWindow : public QObject {
public:
    virtual void timerEvent(QTimerEvent *event);  // 重写定时器事件函数
private:
    int myid;  // 定时器ID，作为标识符
};

// 定义 timerEvent 函数
void MainWindow::timerEvent(QTimerEvent *event) {
    // 判断是否为指定的定时器
    if(event->timerId() == myid) {
        // 触发相关操作
        // 比如执行某个函数或更新界面
    }
}
```

### 说明：
- `startTimer()`：会返回定时器的 ID，在事件触发时，可以通过这个 ID 来判断是哪一个定时器触发。
- `killTimer(timerId)`：通过定时器的 ID 来停止定时器。

---

## 2. `QTimer` 定时器

`QTimer` 是 Qt 提供的一个更为方便和常用的定时器类，它是一个对象，可以通过连接信号和槽的方式来使用。

### 创建 `QTimer` 对象

```cpp
#include <QTimer>

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        timer = new QTimer(this);  // 创建 QTimer 对象

        // 连接信号与槽
        connect(timer, &QTimer::timeout, this, &MainWindow::Timercallback);
    }

private:
    QTimer *timer;

private slots:
    void Timercallback();  // 定义槽函数，用于处理定时器触发
};
```

### 启动定时器

```cpp
/**
 * @brief 启动定时器，循环触发
 * @param 触发间隔，单位为毫秒
 */
timer->start(1000);  // 启动定时器，每1000ms触发一次
```

### 停止定时器

```cpp
// 停止定时器
timer->stop();
```

### 单次定时器

`QTimer::singleShot()` 用于设置一个定时器，它只会触发一次。适用于单次延时操作。

```cpp
/**
 * @brief 设置单次定时器
 * @param 定时器时长，单位为毫秒
 * @param 谁来处理（QObject的子类）
 * @param 回调槽函数
 */
QTimer::singleShot(1000, this, SLOT(callback()));
```

### 定时器信号和槽

`QTimer` 的工作机制是通过信号和槽来实现的。定时器会在每个时间间隔（如 1000ms）发出 `timeout()` 信号，你可以将该信号连接到一个槽函数中，以便每次定时器触发时执行相关操作。

### 代码示例

```cpp
#include <QMainWindow>
#include <QTimer>
#include <QDebug>

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        timer = new QTimer(this);  // 创建 QTimer 对象

        // 连接定时器的 timeout 信号到槽函数
        connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);

        // 启动定时器，每1000ms触发一次
        timer->start(1000);
    }

private:
    QTimer *timer;

private slots:
    void onTimeout() {
        qDebug() << "Timer triggered!";
    }
};
```

### 说明：
- `timer->start(1000)`：每 1000 毫秒（1 秒）触发一次定时器。
- `timer->stop()`：停止定时器。
- `QTimer::singleShot(1000, this, SLOT(callback()))`：设定一个单次触发的定时器，1000 毫秒后触发一次。

---

## 3. 区别总结

### `QObject::startTimer()` 与 `QTimer` 的区别：

- **`QObject::startTimer()`**：
  - 适用于继承自 `QObject` 的对象。
  - 定时器通过事件机制触发，较为底层。
  - 每次定时触发都需要通过 `timerEvent` 来处理。
  - 可以通过 `killTimer()` 停止定时器。
  
- **`QTimer`**：
  - 是一个封装好的定时器对象，更易于使用。
  - 通过信号和槽机制处理定时器触发，便于与其他功能模块集成。
  - 支持单次定时器和周期定时器。
  - 更符合 Qt 的信号槽机制。

---
