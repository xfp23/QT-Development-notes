# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

# UI添加

1. 通过可视化界面添加,没什么好说的。

# 通过代码设计添加

## 添加label

```cpp

label = new QLabel(this);
label->setObjectName(QString::fromUtf8("Qlabel")); //设置label标签的对象名称，可以在代码中搜索它


// 设置 label 控件的位置和大小
// QRect(x, y, width, height) 用来指定一个矩形区域，其中：
// x 是控件左上角的横坐标，y 是控件左上角的纵坐标，
// width 是控件的宽度，height 是控件的高度。
// 解释：
// 控件的左上角会放置在 (130, 100) 这个位置，
// 控件的宽度会是 61 像素，高度会是 21 像素。
// 这样，label 控件就会显示在距离父窗口左边 130 像素，
// 距离父窗口上边 100 像素的地方，且控件的尺寸为 61x21 像素。
label->setGeometry(QRect(130, 100, 61, 21));


lineEdit = new QLineEdit(this); // 创建一个文本行
lineEdit->setObjectName(QString::fromUtf8("QlineEdit"));

```

## 设置字体

```cpp
QFont font;
font.setPointSize(16); // 设置字体大小
label->setFont(font); // 应用设置


```

## 显示图片

### path方法
1. 新建文件路径保存要显示的图片

2. 创建要显示的图片的路径`QString`路径字符串表示图片路径

3. 调用代码实现:
```cpp

// 设置路径
QString path("D:\\图片路径\\");
path += QString::number(picID);
path += ".jpg";

QPixmap pix(path); // 创建图片变量
ui->label->setPixmap(pix); // 显示

```

### QImage类显示

- 适合大图片，速度快
```cpp
#include <QImage>

QImage img;
img.load("image path");

// label此处是显示图片的对象，要哪个对象显示这个图片
ui->label->setPixmap(QPixmap::formImage(img));

```



## 设置应用程式图标

1. 在自己的项目工程中添加`.ico`图标文件，必须是有效的`ico`文件，可以通过工具生成

- [图像转ico网站](https://www.ico51.cn/)

- [获取ico网站](https://www.iconfont.cn/)

- 不用敲代码


# 设计菜单栏(类似于VS code的新建文件夹)

1. 必须创建`MainWindow`工程才能设计菜单栏

2. 输入`(&F)`可显示字母带下划线的(F),其它也一样

3. 创建完之后双击已经创建过的，点击`添加分隔符`,可以创建其它选项


4. 添加菜单的槽函数(菜单不能自动生成槽函数，得自己connect()一个) 

- [此处可查看QT自带的信号机制](/SIGNAL/SIGNAL/SIGNAL_EX.MD)

```cpp

/**
*@brief 连接菜单栏的信号
*@param 具体的菜单
*@param 发出的信号类型 & QAction::triggred
*@param 处理的对象
*@param 回调函数 (槽函数)
*/
connect(ui->newAction,&QAction::triggred,this,callback);
```

这样就能触发动作了

## 设置窗口标题

```cpp
// MainWindow类

this->setWindowTitle("新建文本文档");
```

# 打开选择文件的选项框

- 包含头文件

```cpp

#include <QFileDialog>
#include <QMessageBox>

```
- 选择文件

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

//检查文件名是否为空
// return 空返回true ， 非空返回false
fileName.isEmpty();

// 弹出一个警告信息
// @param 父窗口
// @param 窗口警告标题
// 输出的警告信息
QMessageBox::warning(this,"警告","请选择一个文件");
```

- 打开文件

```cpp

QFile file(filename); // 文件对象,传递要打开的文件名
file.open(QIODevice::ReadOnly); // 只读模式打开文件
QByteArray ba = file.readALL(); // 读取文件
ui->textEdit->setText(QString(ba)); // 在ui显示文件
file.close(); // 关闭文件

```
