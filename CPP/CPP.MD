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
```

# dynamic_cast 关键字

`dynamic_cast` 用于进行安全的类型转换，特别是在有继承关系的情况下。它可以在运行时检查对象的实际类型，并在需要时将基类指针或引用转换为派生类指针或引用。下面是 `dynamic_cast` 的基本语法：

```cpp
dynamic_cast<目标类型>(对象)
```

### 语法解释：
- `目标类型`：你希望将对象转换成的类型，通常是派生类类型。你可以将基类指针或引用转换为派生类指针或引用。
- `对象`：你希望转换的对象。这个对象通常是基类指针或引用。

### 使用 `dynamic_cast` 的前提条件：
1. **需要多态**：类必须至少有一个虚函数，这样才能开启运行时类型识别（RTTI）。如果没有虚函数，`dynamic_cast` 将无法工作。
2. **目标类型必须是指针或引用**：`dynamic_cast` 主要用于指针或引用的类型转换。
   
### 例子：

#### 1. 基类指针转换为派生类指针：

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void speak() { cout << "Base speaking\n"; }
    virtual ~Base() {}  // 必须有虚析构函数来支持多态
};

class Derived : public Base {
public:
    void speak() override { cout << "Derived speaking\n"; }
    void onlyInDerived() { cout << "Only in Derived\n"; }
};

int main() {
    Base* basePtr = new Derived();  // 基类指针指向派生类对象

    // 使用 dynamic_cast 将基类指针转换为派生类指针
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->speak();  // 调用派生类的 speak 方法
        derivedPtr->onlyInDerived();  // 调用派生类特有的方法
    } else {
        cout << "Failed to cast\n";
    }

    delete basePtr;
    return 0;
}
```

- **解释**：`dynamic_cast<Derived*>(basePtr)` 将基类指针 `basePtr` 转换为派生类指针 `derivedPtr`。如果 `basePtr` 实际上指向一个 `Derived` 对象，转换会成功，返回派生类指针。如果 `basePtr` 并不是指向 `Derived` 类的对象，转换会返回 `nullptr`。

#### 2. 基类引用转换为派生类引用：

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void speak() { cout << "Base speaking\n"; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void speak() override { cout << "Derived speaking\n"; }
    void onlyInDerived() { cout << "Only in Derived\n"; }
};

int main() {
    Base& baseRef = Derived();  // 基类引用绑定派生类对象

    // 使用 dynamic_cast 将基类引用转换为派生类引用
    try {
        Derived& derivedRef = dynamic_cast<Derived&>(baseRef);
        derivedRef.speak();
        derivedRef.onlyInDerived();  // 调用派生类的方法
    } catch (std::bad_cast& e) {
        cout << "Failed to cast: " << e.what() << endl;
    }

    return 0;
}
```

- **解释**：`dynamic_cast<Derived&>(baseRef)` 将基类引用 `baseRef` 转换为派生类引用。如果 `baseRef` 不是指向 `Derived` 对象的引用，`dynamic_cast` 会抛出 `std::bad_cast` 异常。

### 总结：
- `dynamic_cast` 是一种类型安全的转换方式，确保类型转换是合法的。
- 它只能在存在继承关系并且类中有虚函数的情况下使用。
- 当父类指针或引用指向一个派生类对象时，`dynamic_cast` 可以将其转换为派生类类型的指针或引用。
- 如果转换不合法，`dynamic_cast` 返回 `nullptr`（对于指针）或抛出 `std::bad_cast` 异常（对于引用）。



# 构造函数初始化列表

在 C++ 中，构造函数的初始化列表是一个非常重要的部分，用于在构造函数体执行之前初始化类的成员变量。我们可以用它来执行多种类型的初始化操作。下面是一些扩展和说明，展示了如何在构造函数初始化列表中使用不同的初始化方式。

### 1. **初始化成员变量**
在初始化列表中，我们可以直接初始化类的成员变量，而不是在构造函数体内进行赋值。这是 C++ 的一种标准做法，特别是对于 `const` 和引用类型的成员变量，它们只能在初始化列表中初始化。

#### 示例：
```cpp
class MyClass {
public:
    MyClass(int val, const std::string &name);

private:
    int m_value;
    const std::string &m_name; // 需要在初始化列表中初始化引用成员
};
  
MyClass::MyClass(int val, const std::string &name)
    : m_value(val), m_name(name) // 使用初始化列表来初始化成员
{
    // 这里不需要再初始化 m_value 和 m_name
}
```

### 2. **使用 `const` 和引用成员变量**
`const` 成员变量和引用成员变量必须在构造函数的初始化列表中初始化，因为它们在对象构造后无法改变。

#### 示例：
```cpp
class MyClass {
public:
    MyClass(int x, const std::string &str);
  
private:
    const int m_constValue;  // const 成员变量
    const std::string &m_refValue;  // 引用类型成员变量
};
  
MyClass::MyClass(int x, const std::string &str)
    : m_constValue(x), m_refValue(str) // 初始化 const 和引用成员变量
{
    // 成员已经在初始化列表中初始化，无需在此修改
}
```

### 3. **调用基类构造函数**
如果你的类继承自一个基类，并且基类有构造函数，你需要在初始化列表中调用基类的构造函数。尤其是基类没有默认构造函数的情况下，必须显式调用。

#### 示例：
```cpp
class Base {
public:
    Base(int x) {
        std::cout << "Base constructor, x = " << x << std::endl;
    }
};

class Derived : public Base {
public:
    Derived(int x) : Base(x) {  // 在初始化列表中调用基类构造函数
        std::cout << "Derived constructor" << std::endl;
    }
};
  
int main() {
    Derived d(10);  // 输出 "Base constructor, x = 10" 和 "Derived constructor"
    return 0;
}
```

### 4. **调用其他成员函数或设置默认值**
你还可以在初始化列表中调用成员函数，或者为某些成员变量提供默认值。

#### 示例：
```cpp
class MyClass {
public:
    MyClass(int x);
  
private:
    int m_value;
    void setValue(int x) { m_value = x; }
};
  
MyClass::MyClass(int x)
    : m_value(x)  // 初始化 m_value
{
    setValue(x);  // 在构造函数体内调用成员函数
}
```

### 5. **成员对象的初始化**
对于包含成员对象的类，如果成员对象没有默认构造函数，那么它必须在初始化列表中初始化。

#### 示例：
```cpp
class Engine {
public:
    Engine() {
        std::cout << "Engine started" << std::endl;
    }
};

class Car {
public:
    Car();
  
private:
    Engine engine;  // 成员对象
};
  
Car::Car()
    : engine()  // 显式初始化成员对象 engine
{
    std::cout << "Car created" << std::endl;
}
```

### 6. **使用委托构造函数**
C++11 引入了构造函数委托，允许一个构造函数调用另一个构造函数。这通常用于减少代码重复。

#### 示例：
```cpp
class MyClass {
public:
    MyClass() : MyClass(42) {  // 委托构造函数
        std::cout << "Default constructor" << std::endl;
    }

    MyClass(int x) {
        std::cout << "Constructor with value: " << x << std::endl;
    }
};
  
int main() {
    MyClass obj;  // 输出 "Constructor with value: 42" 和 "Default constructor"
    return 0;
}
```

### 7. **使用初始化列表初始化 STL 容器或自定义容器**
如果类中包含 STL 容器或自定义容器，可以在初始化列表中初始化容器。

#### 示例：
```cpp
#include <vector>

class MyClass {
public:
    MyClass() : m_data({1, 2, 3, 4, 5}) {}  // 在初始化列表中初始化 vector
    
private:
    std::vector<int> m_data;
};
```

### 8. **防止循环依赖**
有时，我们可能会遇到需要防止循环依赖的情况，比如成员变量依赖于另一个成员的初始化。这种情况下，应该通过初始化列表将初始化顺序正确设置。

### 总结：
构造函数的初始化列表是初始化成员变量、调用基类构造函数、以及其他相关初始化操作的最佳位置。它不仅提高了程序的效率，还使得代码更为简洁和易于维护。

# 模板

## 模板类

在 C++ 中，**模板类**（Template Class）是一个非常强大的特性，它使得类可以根据不同的类型来进行实例化，从而实现代码的复用和通用性。模板类允许我们在编写代码时不必关心具体的数据类型，而是通过一个占位符（通常是 `T` 或 `typename`）来表示数据类型，编译器会在使用模板时自动为其指定合适的类型。

### 模板类的基本语法
```cpp
template <typename T>  // T 是一个类型参数
class MyClass {
private:
    T data;  // 使用类型 T 来定义成员变量

public:
    MyClass(T value) : data(value) {}  // 构造函数

    void setData(T value) {
        data = value;
    }

    T getData() const {
        return data;
    }
};
```

### 模板类的使用
```cpp
int main() {
    MyClass<int> intObject(5);        // 使用 int 类型
    MyClass<double> doubleObject(3.14); // 使用 double 类型

    std::cout << intObject.getData() << std::endl;     // 输出: 5
    std::cout << doubleObject.getData() << std::endl;  // 输出: 3.14

    return 0;
}
```

在这个例子中，`MyClass` 是一个模板类。`T` 是一个占位符，表示任意类型。当我们创建 `MyClass<int>` 时，编译器会实例化一个 `MyClass` 类型，并且 `T` 会被替换为 `int` 类型；同理，当我们创建 `MyClass<double>` 时，`T` 会被替换为 `double` 类型。这样，通过模板类，我们可以在不重复代码的情况下实现对多种类型的支持。

### 模板类的特性
1. **类型独立性**：
   模板类让我们编写与数据类型无关的代码，只要传入合适的数据类型，模板类就能工作。我们可以根据需要对不同的类型进行操作，而不需要编写多个类或重复的代码。

2. **编译时生成代码**：
   模板类并不会在定义时生成代码，而是在实例化时（即在程序中使用模板时）由编译器生成代码。例如，`MyClass<int>` 会生成一份针对 `int` 类型的类，而 `MyClass<double>` 会生成一份针对 `double` 类型的类。

3. **模板类的实例化**：
   当模板类被实例化时，编译器会将占位符类型替换为实际的类型，并生成相应的代码。例如，`MyClass<int>` 就会生成一个包含 `int` 类型的成员变量和方法的类。

### 模板类的成员函数
模板类的成员函数定义通常有两种方式：一种是在类内部定义，另一种是在类外部定义。

#### 在类内部定义成员函数
```cpp
template <typename T>
class MyClass {
private:
    T data;

public:
    MyClass(T value) : data(value) {}

    void setData(T value) {
        data = value;
    }

    T getData() const {
        return data;
    }

    void printData() const {
        std::cout << "Data: " << data << std::endl;
    }
};
```

#### 在类外部定义成员函数
```cpp
template <typename T>
class MyClass {
private:
    T data;

public:
    MyClass(T value);  // 声明构造函数
    void setData(T value);
    T getData() const;
};

// 在类外部定义成员函数
template <typename T>
MyClass<T>::MyClass(T value) : data(value) {}

template <typename T>
void MyClass<T>::setData(T value) {
    data = value;
}

template <typename T>
T MyClass<T>::getData() const {
    return data;
}
```

### 模板类的特化（Template Specialization）
有时候，我们可能需要为某些特定类型提供专门的实现。模板特化允许我们为某个类型或类型组合定义一个特定的实现。

#### 完全特化
```cpp
template <typename T>
class MyClass {
public:
    T data;
    MyClass(T value) : data(value) {}
};

template <>
class MyClass<int> {  // 完全特化为 int 类型
public:
    int data;
    MyClass(int value) : data(value) {}

    void printData() {
        std::cout << "This is an int: " << data << std::endl;
    }
};
```

#### 偏特化
偏特化允许我们在保留一些模板参数的基础上，对某些类型进行修改。

```cpp
template <typename T, typename U>
class MyClass {
public:
    T data1;
    U data2;
    MyClass(T val1, U val2) : data1(val1), data2(val2) {}
};

// 偏特化：当第一个类型是 int 时
template <typename U>
class MyClass<int, U> {
public:
    int data1;
    U data2;
    MyClass(int val1, U val2) : data1(val1), data2(val2) {}

    void printData() {
        std::cout << "This is an int with another type: " << data1 << ", " << data2 << std::endl;
    }
};
```

### 模板类的优缺点
#### 优点：
- **代码复用**：模板使得我们能够编写一次代码，处理多种类型。
- **灵活性**：通过模板，我们可以为多种类型提供通用的实现，而无需为每种类型重复编写类。
- **性能**：由于模板是在编译时生成代码，因此通常能够提供与手写代码相当的效率。

#### 缺点：
- **编译时间**：模板类会增加编译时间，因为编译器需要为每个类型实例化模板。
- **错误信息复杂**：模板编程中的错误信息有时非常难以理解，尤其是在模板实例化出错时。
- **代码膨胀**：每当模板类被实例化时，编译器会为该类型生成代码，这可能导致最终的二进制文件变得较大。

### 总结
模板类是 C++ 强大且灵活的特性，它允许我们编写与类型无关的代码，并在编译时为每个实际使用的类型生成对应的代码。模板类通过类型参数的替换，可以为不同的数据类型提供相同的实现，而不需要重复代码。模板特化则可以为特定类型提供特殊的实现方式。


## 模板函数

模板（Template）在 C++ 中不仅可以用于类的声明和定义，还可以用于多种不同的场景。模板的强大之处在于它的泛化特性，允许我们在编写代码时不依赖于特定的数据类型。除了用来声明类外，模板在 C++ 中还有以下几种常见应用：

### 1. **模板函数（Template Functions）**

模板不仅可以用于类，还可以用于函数。通过模板函数，函数可以在不同的类型上工作，而不需要为每种类型编写重复的代码。

#### 基本模板函数
```cpp
template <typename T>  // 声明一个模板函数，T 是一个占位符类型
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4) << std::endl;        // 使用 int 类型
    std::cout << add(3.5, 4.5) << std::endl;    // 使用 double 类型
}
```

在此例中，`add` 是一个模板函数，它可以接受任意类型的参数并返回相同类型的结果。`T` 是一个占位符，表示任意类型。

#### 函数模板的特化
函数模板也可以像类模板一样进行特化。例如，为某个类型提供特定的实现：
```cpp
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

// 特化版本，针对 `char` 类型
template <>
char multiply(char a, char b) {
    return a;  // 对于字符类型，只返回第一个字符
}

int main() {
    std::cout << multiply(3, 4) << std::endl;     // 输出: 12
    std::cout << multiply('a', 'b') << std::endl; // 输出: 'a'
}
```

### 2. **模板别名（Template Alias）**

C++11 引入了模板别名（`using`），它可以为模板类、模板函数等提供一个简短的别名。这样可以方便地进行类型简化。

#### 示例：
```cpp
template <typename T>
using Ptr = T*;  // 定义一个模板别名，表示指向类型 T 的指针

int main() {
    Ptr<int> p;  // 相当于 `int* p;`
    p = new int(10);
    std::cout << *p << std::endl;  // 输出: 10
    delete p;
}
```

### 3. **模板元编程（Template Metaprogramming）**

模板元编程是使用模板进行编译时计算的技术。通过模板特化、递归模板和常量表达式等方式，可以在编译时进行计算，而不需要在运行时进行。

#### 示例：计算阶乘
```cpp
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;  // 阶乘 0 的特殊情况
};

int main() {
    std::cout << Factorial<5>::value << std::endl;  // 输出: 120
}
```

在这个例子中，通过递归模板特化，我们计算了 5 的阶乘。在编译时，`Factorial<5>::value` 被计算为 120。

### 4. **模板特化（Template Specialization）**

模板特化允许我们为某些特定的类型提供专门的实现。除了完全特化（为某种类型提供完全不同的实现）外，还可以进行部分特化。

#### 完全特化
```cpp
template <typename T>
class MyClass {
public:
    T value;
    MyClass(T val) : value(val) {}
};

// 对 `int` 类型进行完全特化
template <>
class MyClass<int> {
public:
    int value;
    MyClass(int val) : value(val) {}
    void print() { std::cout << "Integer: " << value << std::endl; }
};

int main() {
    MyClass<double> obj1(3.14);   // 对 double 类型
    MyClass<int> obj2(42);         // 对 int 类型
    obj2.print();  // 输出: Integer: 42
}
```

#### 部分特化
```cpp
template <typename T, typename U>
class MyClass {
    T first;
    U second;
public:
    MyClass(T f, U s) : first(f), second(s) {}
};

// 部分特化：第二个类型为 `int` 时
template <typename T>
class MyClass<T, int> {
    T first;
    int second;
public:
    MyClass(T f, int s) : first(f), second(s) {}
    void print() { std::cout << "First: " << first << ", Second (int): " << second << std::endl; }
};

int main() {
    MyClass<float, int> obj(3.14f, 42);  // 部分特化
    obj.print();  // 输出: First: 3.14, Second (int): 42
}
```

### 5. **模板参数的默认值（Default Template Parameters）**

C++11 引入了为模板参数提供默认值的功能。这样，如果用户没有显式传递模板参数，编译器将使用默认值。

#### 示例：
```cpp
template <typename T = int>  // 默认类型为 int
class MyClass {
public:
    T value;
    MyClass(T val = T()) : value(val) {}
};

int main() {
    MyClass<> obj1;    // 默认使用 int 类型
    MyClass<double> obj2(3.14);  // 使用 double 类型
    std::cout << obj1.value << std::endl;   // 输出: 0
    std::cout << obj2.value << std::endl;   // 输出: 3.14
}
```

### 6. **非类型模板参数（Non-Type Template Parameters）**

C++ 允许模板接受不仅仅是类型的参数，还可以是常量值（例如整数、指针等）。这称为非类型模板参数。

#### 示例：
```cpp
template <typename T, int N>
class MyArray {
public:
    T arr[N];  // 数组大小是模板参数 N
    void printSize() { std::cout << "Size: " << N << std::endl; }
};

int main() {
    MyArray<int, 5> arr;   // 创建一个大小为 5 的整数数组
    arr.printSize();        // 输出: Size: 5
}
```

### 总结
模板不仅可以用于类的声明，还能广泛应用于函数、别名、模板特化、模板元编程、非类型模板参数等多种场景。模板在 C++ 中是一个非常强大的特性，使得我们能够编写类型无关、通用和高效的代码。通过模板，C++ 提供了灵活的方式来处理不同的类型，避免了重复的代码编写，并且能够在编译时进行优化。


# try语句块

在 C++ 中，`try` 和 `catch` 语句用于异常处理。`try` 块用于捕获可能抛出的异常，而 `catch` 块则用于处理这些异常。

下面是一个简单的 C++ 异常处理的例子：

### 示例：使用 `try` 和 `catch` 进行异常处理

```cpp
#include <iostream>
#include <stdexcept>  // 包含异常类，如 std::invalid_argument

void divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed!");  // 抛出异常
    }
    std::cout << "Result: " << a / b << std::endl;
}

int main() {
    try {
        int a = 10;
        int b = 0;  // 这里将会抛出异常
        divide(a, b);  // 调用可能抛出异常的函数
    }
    catch (const std::invalid_argument& e) {  // 捕获 std::invalid_argument 异常
        std::cout << "Error: " << e.what() << std::endl;  // 输出错误信息
    }
    catch (...) {  // 捕获任何其他类型的异常
        std::cout << "An unexpected error occurred!" << std::endl;
    }

    return 0;
}
```

### 代码解释：

1. **`divide` 函数**：
   - 它执行两个整数的除法操作。如果除数 `b` 是 0，它会抛出一个 `std::invalid_argument` 异常，错误信息为 `"Division by zero is not allowed!"`。

2. **`main` 函数**：
   - `try` 块中调用了 `divide` 函数。当 `b` 为 0 时，`divide` 会抛出异常。
   - `catch` 块捕获 `std::invalid_argument` 异常，并输出错误信息 `Division by zero is not allowed!`。
   - 如果出现其他类型的异常，`catch(...)` 会捕获并输出 `"An unexpected error occurred!"`。

### 输出：
```
Error: Division by zero is not allowed!
```

### 总结：
- `try` 块用于包含可能抛出异常的代码。
- `catch` 块用于捕获并处理异常。
- 在 C++ 中，`throw` 用来抛出异常，`catch` 用来捕获异常。
