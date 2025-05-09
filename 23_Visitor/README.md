# 设计模式专题之访问者模式：23-图形的面积

## 题目描述
小明家有一些圆形和长方形面积的土地，请你帮他实现一个访问者模式，使得可以通过访问者计算每块土地的面积。

图形的面积计算规则如下：
- 圆形的面积计算公式为：3.14 * 半径 * 半径
- 矩形的面积计算公式为：长 * 宽

## 输入描述
- 第一行是一个整数 `n`（1 <= n <= 1000），表示图形的数量。
- 接下来的 `n` 行，每行描述一个图形，格式为 "Circle r" 或 "Rectangle width height"，其中 `r`、`width`、`height` 是正整数。

## 输出描述
对于每个图形，输出一行，表示该图形的面积。

## 输入示例
```
3
Circle 5
Rectangle 3 4
Circle 2
```

## 输出示例
```
78.5
12
12.56
```

## 提示信息
请使用访问者模式来实现图形面积的计算，确保可以灵活地为不同类型的图形计算面积，同时保持代码的扩展性和维护性。