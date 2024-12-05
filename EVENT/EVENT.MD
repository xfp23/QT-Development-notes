# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。


# QT 事件触发机制



## QT 事件触发机制

QT 常用的事件：

| 事件类型           | 描述                                         |
|------------------|--------------------------------------------|
| **键盘事件**         | 键盘的松开和按下。主要包括 `keyPressEvent()` 和 `keyReleaseEvent()`。               |
| **鼠标事件**         | 鼠标的移动，鼠标按键的按下与松开。主要包括 `mousePressEvent()`、`mouseReleaseEvent()` 和 `mouseMoveEvent()`。 |
| **拖放事件**         | 处理拖放操作。主要包括 `dragEnterEvent()`、`dragMoveEvent()`、`dragLeaveEvent()` 和 `dropEvent()`。  |
| **绘屏事件**         | 用于绘制控件。主要包括 `paintEvent()`，在控件内容需要更新时调用。                 |
| **定时器事件**        | 定时器触发的事件，主要通过 `timerEvent()` 实现。                                   |
| **焦点事件**         | 控件获得或失去焦点时的事件。包括 `focusInEvent()` 和 `focusOutEvent()`。        |
| **大小改变事件**      | 控件大小发生变化时触发的事件。主要包括 `resizeEvent()`。                         |
| **显示和隐藏事件**    | 控件显示和隐藏时触发的事件。包括 `showEvent()` 和 `hideEvent()`。               |
| **窗口事件**         | 主要涉及窗口操作，如关闭、最大化、最小化等。包括 `closeEvent()`、`showEvent()` 和 `resizeEvent()`。 |
| **鼠标滚轮事件**       | 鼠标滚轮滚动时触发的事件。包括 `wheelEvent()`。                                   |
| **键盘快捷键事件**     | 与特定的键盘快捷键相关的事件。包括 `shortcutEvent()`（一般通过 QAction 来实现）。       |
| **多点触控事件**       | 触摸屏多点触控时触发的事件。包括 `touchEvent()`。                                |
| **窗口激活/去激活事件**| 窗口激活或去激活时的事件。包括 `windowActivationChangeEvent()`。                |

---

- 更多事件请查看 [事件枚举一览表](./EVENT_EX.MD)


- 事件是写虚函数event来实现的

- 实例：创建一个键盘按键事件
```cpp

class MainWindow {
    public:
    void keyPressEvent(QKEvent *);// 重写此虚函数

};

void MainWindow::keyPressEvent(QKeyEvent *key)
{
    // 获取热键                                      获取普通按键
    if(key->modifiers() == Qt::ControlModifier &&  key->key() == Qt::Key_S)
    {

    }
}
```
