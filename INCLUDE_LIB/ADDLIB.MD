# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。


# QT添加三方库

```qmake
QXLSX_PARENTPATH=./         # current QXlsx path is . (. 表示当前目录)

QXLSX_HEADERPATH=./header/  # 当前目录下的header子目录

QXLSX_SOURCEPATH=./source/  # 当前目录下的source子目录

include(./QXlsx.pri) #.pri文件应该包含了QXlsx库的配置信息

```

- 1. 将三方库拷贝至工程目录里面 
- 2. 按照上方方式更改`pro`文件