
---

# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

---

# QT 文件操作

## 包含的头文件

```cpp
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextEdit> // 如果涉及 UI 控件，如 QTextEdit
```

---

## 打开文本文件

### 1. 打开文件选择对话框

#### 使用说明

```cpp
/**
 * @brief 打开一个文件选择对话框
 * @param parent 当前操作的对象指针（通常是父窗口）
 * @param title 对话框的标题
 * @param directory 默认打开的文件路径
 * @param filter 可选择的文件类型过滤器
 * @return 返回用户选择的文件路径，如果未选择文件则返回空字符串
 */
QString fileName = QFileDialog::getOpenFileName(this, "选择一个文件", QCoreApplication::applicationFilePath(), "*.cpp");
```

#### 检查用户是否选择文件

```cpp
// 检查文件名是否为空
if (fileName.isEmpty()) {
    // 弹出一个警告信息
    QMessageBox::warning(this, "警告", "请选择一个文件");
    return;
}
```

---

### 2. 打开文件并读取内容

#### 使用说明

```cpp
// 创建一个 QFile 对象，传递要打开的文件路径
QFile file(fileName);

// 打开文件（只读模式）
if (!file.open(QIODevice::ReadOnly)) {
    // 如果打开失败，弹出错误提示
    QMessageBox::warning(this, "错误", "无法打开文件！");
    return;
}

// 读取文件内容
QByteArray fileContent = file.readAll();

// 在 UI 控件（例如 QTextEdit）中显示文件内容
ui->textEdit->setText(QString(fileContent));

// 关闭文件
file.close();
```

---

## 保存文件

### 1. 打开文件保存对话框

#### 使用说明

```cpp
/**
 * @brief 打开一个文件保存对话框
 * @param parent 当前操作的对象指针（通常是父窗口）
 * @param title 对话框的标题
 * @param directory 默认保存的路径
 * @param filter 可保存的文件类型过滤器
 * @return 返回用户选择的保存路径，如果未选择则返回空字符串
 */
QString fileName = QFileDialog::getSaveFileName(this, "保存文件", QCoreApplication::applicationFilePath(), "*.txt");
```

### 2. 保存文件内容

#### 使用说明

```cpp
// 创建一个 QFile 对象，传递要保存的文件路径
QFile file(fileName);

// 打开文件（只写模式）
if (!file.open(QIODevice::WriteOnly)) {
    // 如果打开失败，弹出错误提示
    QMessageBox::warning(this, "错误", "无法写入文件！");
    return;
}

// 获取用户输入的内容并写入文件
QString textContent = ui->textEdit->toPlainText();
file.write(textContent.toUtf8());

// 关闭文件
file.close();
```

---

### 完整代码示例

#### 打开文件

```cpp
void MainWindow::on_openFileButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "选择一个文件", QCoreApplication::applicationFilePath(), "*.cpp");

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择一个文件");
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "错误", "无法打开文件！");
        return;
    }

    QByteArray fileContent = file.readAll();
    ui->textEdit->setText(QString(fileContent));
    file.close();
}
```

#### 保存文件

```cpp
void MainWindow::on_saveFileButton_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "保存文件", QCoreApplication::applicationFilePath(), "*.txt");

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入保存的文件名");
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "错误", "无法写入文件！");
        return;
    }

    QString textContent = ui->textEdit->toPlainText();
    file.write(textContent.toUtf8());
    file.close();
}
```

---

### UI 说明

- **`QTextEdit`**: 用于显示或编辑文本内容，需确保在 UI 中添加，并命名为 `textEdit`。
- **`on_openFileButton_clicked`** 和 **`on_saveFileButton_clicked`**：分别是打开文件和保存文件的按钮事件，需通过 Qt Designer 或手动绑定。

--- 
