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