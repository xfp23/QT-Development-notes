# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

# C++ 语法

## 继承

C++ 中的继承允许一个类（派生类）从另一个类（基类）获取属性和方法。

### 基本语法：

```cpp
class BaseClass {
public:
    // 基类的构造函数
    BaseClass() {
        // 构造函数内容
    }
    
    // 基类的成员函数
    void baseFunction() {
        std::cout << "This is a function of the base class." << std::endl;
    }
};

class DerivedClass : public BaseClass {  // public 继承
public:
    // 派生类的构造函数
    DerivedClass() {
        // 构造函数内容
    }
    
    // 派生类的成员函数
    void derivedFunction() {
        std::cout << "This is a function of the derived class." << std::endl;
    }
};