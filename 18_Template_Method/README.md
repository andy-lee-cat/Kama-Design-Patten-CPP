# 设计模式专题之模板方法模式：18-咖啡馆

## 题目描述
小明喜欢品尝不同类型的咖啡，她发现每种咖啡的制作过程有一些相同的步骤，他决定设计一个简单的咖啡制作系统，使用模板方法模式定义咖啡的制作过程。系统支持两种咖啡类型：美式咖啡（American Coffee）和拿铁（Latte）。

咖啡制作过程包括以下步骤：
1. 研磨咖啡豆 Grinding coffee beans
2. 冲泡咖啡 Brewing coffee
3. 添加调料 Adding condiments

其中，美式咖啡和拿铁的调料添加方式略有不同，拿铁在添加调料时需要添加牛奶 Adding milk。

## 输入描述
多行输入，每行包含一个数字，表示咖啡的选择（1 表示美式咖啡，2 表示拿铁）。

## 输出描述
根据每行输入，输出制作咖啡的过程，包括咖啡类型和各个制作步骤，末尾有一个空行。

## 输入示例
```
1
2
```

## 输出示例
```
Making American Coffee:
Grinding coffee beans
Brewing coffee
Adding condiments

Making Latte:
Grinding coffee beans
Brewing coffee
Adding milk
Adding condiments
```

## 提示信息
请使用模板方法模式来定义咖啡制作的基本步骤，并允许在具体实现中根据咖啡类型的不同进行适当的扩展和定制。
