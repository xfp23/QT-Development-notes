# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

# QT框架 ：

## MainWindow 类

1. QT不同于单片机或者其它，他的程序运行框架并不在`main()`函数中实现，操作UI逻辑需要在`MainWindow`创建一个方法，然后写此方法可以实现逻辑。

2. 如果自己新建了一个类，建议放进`ManWindow`的`private`成员中当指针，并为它分配内存。

3. `MainWindow`可以调用任何类与方法，但是其它类与方法不得调用`MainWindow`类。

4. 程序并不是在调用，而是在写`MainWindow`的成员函数时进行程序逻辑的实现。

5. `MainWindow`类的构造函数通常用于初始化UI组件、连接信号与槽、初始化其他子类等。

6. 在`MainWindow`中使用信号和槽机制来更新UI或处理事件，避免直接在非UI类中操作界面。

7. `MainWindow`的析构函数应该释放动态分配的内存，确保没有内存泄漏。

8. Qt应用程序通过`QApplication`对象启动并运行事件循环，`MainWindow`作为主窗口进行管理。

9. UI更新通常通过信号通知`MainWindow`，然后由`MainWindow`的槽函数来处理。

10. 在Qt中，`MainWindow`类不仅是UI窗口的容器，还负责应用的主逻辑部分，因此需要合理组织各个模块之间的关系。

在这行代码中：

```cpp
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
```

- `QMainWindow` 是 **基类**（父类），
- `MainWindow` 是 **派生类**（子类）。

`MainWindow` 类继承自 `QMainWindow` 类，因此 `QMainWindow` 是 `MainWindow` 的基类。`QMainWindow` 提供了主窗口的基本功能，而 `MainWindow` 扩展了这些功能，通常用来实现特定应用程序的界面。

`QWidget` 是 `QMainWindow` 的父类，`QMainWindow` 继承了 `QWidget`，因此它也具备了 `QWidget` 的功能。在构造函数的初始化列表中，`parent` 参数被传递给了 `QMainWindow` 的构造函数。


## 使用其他类或者自定义类

1. 不允许直接创建自己的实例对象去`MainWindow`中调用

2. 将自己的类或要用到的其他类当作 `MainWindow`的私有成员，便于他们可以互相访问，在类中

3. 在`MainWindow`里添加的私有成员必须为指针然后给它new动态内存