# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

---

# QT自带常见信号

## 1. triggered
- **发出对象**：`QAction`
- **描述**：当用户触发动作（例如点击菜单项、工具栏按钮或使用快捷键）时发出此信号。
- **典型使用**：菜单项、工具栏按钮和快捷键绑定动作，触发对应的槽函数。
- **连接示例**：
  ```cpp
  QAction *action = new QAction("Open", this);
  connect(action, &QAction::triggered, this, &MainWindow::openFile);
  
  QMenu *fileMenu = menuBar()->addMenu("File");
  fileMenu->addAction(action);
  ```
  该示例中，当用户点击 "Open" 菜单项时，会触发 `openFile()` 槽函数。

## 2. clicked
- **发出对象**：`QPushButton`, `QToolButton`, `QRadioButton`, `QCheckBox`, 等
- **描述**：当按钮被点击时发出此信号。
- **典型使用**：响应按钮点击事件。
- **连接示例**：
  ```cpp
  QPushButton *button = new QPushButton("Click Me", this);
  connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
  ```

## 3. valueChanged
- **发出对象**：`QSlider`, `QSpinBox`, `QDial`, 等
- **描述**：当值发生变化时发出此信号。
- **典型使用**：响应控件的值变化。
- **连接示例**：
  ```cpp
  QSlider *slider = new QSlider(this);
  connect(slider, &QSlider::valueChanged, this, &MainWindow::onSliderValueChanged);
  ```

## 4. textChanged
- **发出对象**：`QLineEdit`, `QTextEdit`
- **描述**：当文本内容变化时发出此信号。
- **典型使用**：响应用户输入的文本变化。
- **连接示例**：
  ```cpp
  QLineEdit *lineEdit = new QLineEdit(this);
  connect(lineEdit, &QLineEdit::textChanged, this, &MainWindow::onTextChanged);
  ```

## 5. editingFinished
- **发出对象**：`QLineEdit`, `QTextEdit`
- **描述**：当编辑完成（例如，用户按下回车键或文本框失去焦点）时发出此信号。
- **典型使用**：当用户完成文本输入时进行处理。
- **连接示例**：
  ```cpp
  QLineEdit *lineEdit = new QLineEdit(this);
  connect(lineEdit, &QLineEdit::editingFinished, this, &MainWindow::onEditingFinished);
  ```

## 6. currentIndexChanged
- **发出对象**：`QComboBox`, `QListView`
- **描述**：当当前索引发生变化时发出此信号。
- **典型使用**：响应用户选择项变化。
- **连接示例**：
  ```cpp
  QComboBox *comboBox = new QComboBox(this);
  connect(comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::onIndexChanged);
  ```

## 7. activated
- **发出对象**：`QAction`, `QMenu`
- **描述**：当某个动作或菜单项被激活时发出此信号。
- **典型使用**：菜单项激活事件。
- **连接示例**：
  ```cpp
  QAction *action = new QAction("Open", this);
  connect(action, &QAction::activated, this, &MainWindow::onActionActivated);
  ```

## 8. destroyed
- **发出对象**：`QObject`
- **描述**：当对象被销毁时发出此信号。
- **典型使用**：响应对象销毁事件。
- **连接示例**：
  ```cpp
  connect(button, &QObject::destroyed, this, &MainWindow::onObjectDestroyed);
  ```

## 9. pressed
- **发出对象**：`QPushButton`, `QToolButton`
- **描述**：当按钮被按下时发出此信号。
- **典型使用**：响应按钮按下事件。
- **连接示例**：
  ```cpp
  QPushButton *button = new QPushButton("Press Me", this);
  connect(button, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
  ```

## 10. released
- **发出对象**：`QPushButton`, `QToolButton`
- **描述**：当按钮被释放时发出此信号。
- **典型使用**：响应按钮释放事件。
- **连接示例**：
  ```cpp
  QPushButton *button = new QPushButton("Release Me", this);
  connect(button, &QPushButton::released, this, &MainWindow::onButtonReleased);
  ```

## 11. timeout
- **发出对象**：`QTimer`
- **描述**：当计时器时间到达时发出此信号。
- **典型使用**：定时任务或定时更新。
- **连接示例**：
  ```cpp
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);
  ```

## 12. finished
- **发出对象**：`QProcess`
- **描述**：当进程执行完成时发出此信号。
- **典型使用**：进程结束时进行后续处理。
- **连接示例**：
  ```cpp
  QProcess *process = new QProcess(this);
  connect(process, &QProcess::finished, this, &MainWindow::onProcessFinished);
  ```

## 13. stateChanged
- **发出对象**：`QNetworkAccessManager`, `QNetworkReply`
- **描述**：当网络状态发生变化时发出此信号。
- **典型使用**：网络请求状态变化。
- **连接示例**：
  ```cpp
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
  connect(manager, &QNetworkAccessManager::stateChanged, this, &MainWindow::onNetworkStateChanged);
  ```

## 14. mousePressEvent
- **发出对象**：`QWidget`
- **描述**：当鼠标点击控件时发出此信号。
- **典型使用**：响应鼠标点击事件。
- **连接示例**：
  ```cpp
  connect(this, &QWidget::mousePressEvent, this, &MainWindow::onMousePressed);
  ```

## 15. keyPressEvent
- **发出对象**：`QWidget`
- **描述**：当键盘按键被按下时发出此信号。
- **典型使用**：响应键盘按键事件。
- **连接示例**：
  ```cpp
  connect(this, &QWidget::keyPressEvent, this, &MainWindow::onKeyPressed);
  ```

## 16. keyReleaseEvent
- **发出对象**：`QWidget`
- **描述**：当键盘按键被释放时发出此信号。
- **典型使用**：响应键盘释放事件。
- **连接示例**：
  ```cpp
  connect(this, &QWidget::keyReleaseEvent, this, &MainWindow::onKeyReleased);
  ```
----------------------------------------------------------------------------------------------------------------


---------------------------------------------------------------------------------------------------------------------

### 1. **QWidget 类的信号**
- `clicked()`：当按钮被点击时触发。
- `pressed()`：当按钮被按下时触发。
- `released()`：当按钮释放时触发。
- `closeEvent()`：当窗口关闭时触发。
- `resizeEvent()`：当窗口大小调整时触发。
- `moveEvent()`：当窗口位置变化时触发。
- `focusInEvent()`：当窗口获得焦点时触发。
- `focusOutEvent()`：当窗口失去焦点时触发。
- `keyPressEvent()`：当按下键盘按键时触发。
- `keyReleaseEvent()`：当松开键盘按键时触发。
  
### 2. **QPushButton 类的信号**
- `clicked()`：当按钮被点击时触发。
- `pressed()`：当按钮被按下时触发。
- `released()`：当按钮被释放时触发。

### 3. **QLineEdit 类的信号**
- `textChanged()`：当文本发生变化时触发。
- `editingFinished()`：当编辑完成时触发（通常在按下回车或离开文本框时）。
- `returnPressed()`：当按下回车键时触发。
- `selectionChanged()`：当文本选择发生变化时触发。

### 4. **QComboBox 类的信号**
- `currentIndexChanged()`：当选项的索引发生变化时触发。
- `activated()`：当选项被激活时触发。
- `currentTextChanged()`：当当前文本变化时触发。

### 5. **QTimer 类的信号**
- `timeout()`：当定时器超时时触发。

### 6. **QSlider 类的信号**
- `valueChanged()`：当滑块的值发生变化时触发。
- `sliderPressed()`：当滑块被按下时触发。
- `sliderReleased()`：当滑块被释放时触发。

### 7. **QCheckBox 类的信号**
- `toggled()`：当复选框状态（勾选与否）发生变化时触发。

### 8. **QRadioButton 类的信号**
- `toggled()`：当单选按钮状态发生变化时触发。

### 9. **QListView/QTreeView 类的信号**
- `clicked()`：当视图中的项被点击时触发。
- `doubleClicked()`：当视图中的项被双击时触发。
- `selectionModel()->selectionChanged()`：当视图的选项发生变化时触发。

### 10. **QSerialPort 类的信号**
- `readyRead()`：当串口接收到数据时触发。
- `errorOccurred()`：当串口发生错误时触发。

### 11. **QApplication 类的信号**
- `aboutToQuit()`：当应用程序即将退出时触发。

### 12. **QMainWindow 类的信号**
- `statusBar()`：当状态栏发生变化时触发。

### 13. **QCloseEvent 类的信号**
- `close()`：当窗口尝试关闭时触发。 

### 14. **QFile 类的信号**
- `readyRead()`：当文件准备好读取时触发。

