# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

# 信号与槽机制

Qt 的 **信号与槽机制** 是一种实现对象间通信的核心特性，用于在事件触发时调用特定的响应函数。

## 槽函数

- **定义**：槽函数是当信号被触发时自动调用的函数。
- **作用**：实现对信号触发事件的响应。
- **定义规则**：
  - 槽函数的定义需要在类的声明中添加关键字 `slots:`。
  - 槽函数可以定义为 `private`、`protected` 或 `public`，根据访问权限的需求决定。
  
### 定义槽函数的语法：
```cpp
class MyClass : public QObject {
    Q_OBJECT  // 使用信号与槽必须包含
public:
    MyClass(QObject *parent = nullptr);
    ~MyClass();

private slots:  // 槽函数区域
    void onButtonClicked();  // 响应按钮点击的槽函数
};
```

## 信号

- **定义**：信号是对象状态发生变化时发出的通知。
- **特点**：
  - 信号由 `signals:` 关键字定义。
  - 信号本身没有具体实现，只是一个声明，类似于函数原型。
  - 信号是类的接口，用于通知外部状态的改变。

### 定义信号的语法：
```cpp
signals:
    void valueChanged(int newValue);  // 定义一个信号
```

## 连接信号与槽

- **现代语法**（推荐，C++11 起支持）：
```cpp
connect(sender, &SenderClass::signal, receiver, &ReceiverClass::slot);
```

### 例子：
```cpp
connect(button, &QPushButton::clicked, this, &MyClass::onButtonClicked);
```

### 绑定定时器例子:

```cpp
timer = 

connect();
```

## 使用注意事项

1. **`Q_OBJECT` 宏**：
   - 类中需要定义信号或槽时，必须包含 `Q_OBJECT` 宏。
   - 该宏用于支持 Qt 的元对象系统（MOC）。

2. **信号与槽参数**：
   - 信号的参数可以是任何类型，但槽函数的参数必须与信号匹配，或者参数更少。

3. **线程安全**：
   - Qt 的信号与槽机制是线程安全的，当信号和槽位于不同线程时，默认会使用队列连接模式。

## 信号与槽的常见用途

1. **按钮点击事件**：
   连接 `QPushButton` 的 `clicked` 信号到自定义槽函数。

2. **数据更新通知**：
   通过 `valueChanged` 信号通知界面或其他模块数据发生变化。

3. **进度条更新**：
   通过信号和槽更新 `QProgressBar` 的显示值。

## 总结

Qt 的信号与槽机制是一种松耦合的设计模式，非常适合处理 GUI 编程中的事件驱动场景。通过定义信号和槽并将它们连接，可以实现灵活的对象间通信。

