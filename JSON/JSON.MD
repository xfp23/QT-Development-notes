以下是补充后的完整文档内容：

---

# 版权信息

© 2024 . 未经许可不得复制、修改或分发。 此文献为 [小風的藏書閣](https://t.me/xfp2333) 所有。

---

# QT JSON 解析

在 Qt 中，`QJsonDocument` 和 `QJsonObject` 提供了简便的方式来解析和生成 JSON 数据。以下是一个基本的 JSON 解析流程。

## 1. 解析 JSON 数据

首先，假设你从串口或其他途径获得了 JSON 格式的字符串数据，并存储在 `QByteArray` 中。接下来，使用 `QJsonDocument` 来解析这些数据。

```cpp
QByteArray data; // 存储需要解析的 JSON 数据
```

假设 `data` 包含如下 JSON 数据：
```json
{
  "ID": "1234",
  "Name": "example",
  "Enabled": true
}
```

## 2. 使用 `QJsonDocument` 解析

```cpp
// 使用 QJsonDocument 从 QByteArray 中读取 JSON 数据
QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

// 检查 JSON 是否有效
if (jsonDoc.isObject()) {
    QJsonObject jsonObj = jsonDoc.object(); // 获取 JSON 对象

    // 判断 "ID" 是否存在并且是字符串类型
    if (jsonObj.contains("ID") && jsonObj["ID"].isString()) {
        QString id = jsonObj["ID"].toString(); // 获取 ID 的值
        qDebug() << "ID: " << id;
    }

    // 判断 "Name" 是否存在并且是字符串类型
    if (jsonObj.contains("Name") && jsonObj["Name"].isString()) {
        QString name = jsonObj["Name"].toString(); // 获取 Name 的值
        qDebug() << "Name: " << name;
    }

    // 判断 "Enabled" 是否存在并且是布尔值
    if (jsonObj.contains("Enabled") && jsonObj["Enabled"].isBool()) {
        bool enabled = jsonObj["Enabled"].toBool(); // 获取 Enabled 的值
        qDebug() << "Enabled: " << enabled;
    }
} else {
    qDebug() << "Invalid JSON format!";
}
```

### 代码解析

- **`QJsonDocument::fromJson(data)`**：将 `QByteArray` 中的 JSON 字符串解析为 `QJsonDocument` 对象。
- **`jsonDoc.isObject()`**：判断解析是否成功，并且 JSON 数据是否是一个对象。
- **`jsonDoc.object()`**：获取 `QJsonObject`，这是 JSON 对象的容器。
- **`jsonObj.contains("key")`**：检查 `QJsonObject` 中是否包含指定的键（例如 `"ID"`、`"Name"`）。
- **`jsonObj["key"].isString()`**、**`jsonObj["key"].isBool()`** 等：检查值的类型是否符合预期。
- **`jsonObj["key"].toString()`**、**`jsonObj["key"].toBool()`** 等：获取对应键的值。

## 3. 处理 JSON 数组

如果你的 JSON 数据中包含数组，可以使用 `QJsonArray` 来解析和操作数组。

例如，假设 JSON 数据如下：

```json
{
  "IDs": ["1234", "5678", "91011"]
}
```

你可以这样解析数组：

```cpp
if (jsonObj.contains("IDs") && jsonObj["IDs"].isArray()) {
    QJsonArray jsonArray = jsonObj["IDs"].toArray();
    
    // 遍历数组中的每一项
    for (const QJsonValue &value : jsonArray) {
        if (value.isString()) {
            QString id = value.toString(); // 获取每一个ID
            qDebug() << "ID from array: " << id;
        }
    }
}
```

### 代码解析

- **`jsonObj["IDs"].isArray()`**：检查键 `"IDs"` 对应的值是否是数组类型。
- **`jsonObj["IDs"].toArray()`**：将该值转换为 `QJsonArray`。
- **`for (const QJsonValue &value : jsonArray)`**：遍历数组中的每个元素，`QJsonValue` 可以包含不同类型的数据，可以使用 `isString()`、`toString()` 等方法获取实际的值。

## 4. 完整示例

```cpp
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QDebug>

void parseJsonData(const QByteArray &data) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

    if (jsonDoc.isObject()) {
        QJsonObject jsonObj = jsonDoc.object();
        
        // 解析单个字段
        if (jsonObj.contains("ID") && jsonObj["ID"].isString()) {
            QString id = jsonObj["ID"].toString();
            qDebug() << "ID: " << id;
        }

        // 解析数组字段
        if (jsonObj.contains("IDs") && jsonObj["IDs"].isArray()) {
            QJsonArray jsonArray = jsonObj["IDs"].toArray();
            for (const QJsonValue &value : jsonArray) {
                if (value.isString()) {
                    QString id = value.toString();
                    qDebug() << "ID from array: " << id;
                }
            }
        }

        // 解析其他字段
        if (jsonObj.contains("Enabled") && jsonObj["Enabled"].isBool()) {
            bool enabled = jsonObj["Enabled"].toBool();
            qDebug() << "Enabled: " << enabled;
        }
    } else {
        qDebug() << "Invalid JSON format!";
    }
}
```

### 完整示例说明

1. **QByteArray data**：存储了 JSON 字符串数据。
2. **QJsonDocument**：用来解析 JSON 数据，并转换为 `QJsonObject` 或 `QJsonArray`。
3. **QJsonObject**：从 `QJsonDocument` 提取 JSON 对象，获取其中的字段。
4. **QJsonArray**：解析包含多个元素的字段（如数组）。

通过上述代码，你可以灵活地解析和操作 JSON 数据，并将解析的结果用于后续的程序逻辑中。

---