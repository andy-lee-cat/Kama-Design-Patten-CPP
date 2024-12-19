# KamaCoder 设计模式练习

本项目旨在通过实践来深入理解和掌握设计模式，针对卡码网（KamaCoder）的题目。直接实现题目要求的功能，并展示如何使用设计模式来优化代码结构和提高代码的可维护性。

## 项目结构

```
KamaCoder-DesignPatterns/
│
├── include/             # 头文件目录
├── src/                 # 源代码目录
│   ├── 01_Singleton/     # 单例模式练习
│   │   ├── README.md    # 题意说明文件
│   │   ├── easy_solution.cpp  # 直接实现题意的代码
│   │   └── singleton.cpp    # 使用单例模式的实现代码
│   │   └── Makefile        # 构建文件
│   ├── 02_FactoryMethod/  # 工厂方法模式练习
│   │   ├── README.md
│   │   ├── easy_solution.cpp
│   │   └── factory_method.cpp
│   │   └── Makefile        # 构建文件
│   │   ...
│   └── 23_Visitor/       # 访问者模式练习
│       ├── README.md
│       ├── easy_solution.cpp
│       └── visitor.cpp
│       └── Makefile        # 构建文件
│
└── README.md            # 项目说明文件
```

## 构建和运行

在每个设计模式练习的目录下，都有一个`Makefile`用于构建和运行该模式的代码。

1. 进入具体的设计模式练习目录：
```
   cd 01_Singleton/
```

2. 使用Makefile构建和运行：
   ```
   make
   ```

这将编译并运行该目录下的代码。

## 设计模式

本项目将涉及以下设计模式：

- 单例模式（Singleton）
- 工厂方法模式（Factory Method）
- 策略模式（Strategy）
- 观察者模式（Observer）
- 装饰者模式（Decorator）
- 访问者模式（Visitor）
- 等等...

每个模式都将对应一个或多个题目的实现，展示如何将设计模式应用到实际问题中。

## 贡献

我们欢迎任何形式的贡献，包括但不限于：

- 提交bug报告
- 提交功能请求
- 提交代码补丁

请通过GitHub的Issues和Pull Requests系统来贡献。

## 许可证

本项目采用[MIT许可证](LICENSE)。请在分发或使用本项目时遵守许可证规定。
