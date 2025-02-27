# 设计模式专题之命令模式：15-自助点餐机

## 题目描述
小明去奶茶店买奶茶，他可以通过在自助点餐机上来点不同的饮品，请你使用命令模式设计一个程序，模拟这个自助点餐系统的功能。

## 输入描述
第一行是一个整数 `n`（1 ≤ n ≤ 100），表示点单的数量。
接下来的 n 行，每行包含一个字符串，表示点餐的饮品名称。

## 输出描述
输出执行完所有点单后的制作情况，每行输出一种饮品的制作情况。如果制作完成，输出 "XXX is ready!"，其中 XXX 表示饮品名称。

## 输入示例
```
4
MilkTea
Coffee
Cola
MilkTea
```

## 输出示例
```
MilkTea is ready!
Coffee is ready!
Cola is ready!
MilkTea is ready!
```

## 提示信息
请使用命令模式来实现自助点餐系统，确保每个点餐请求都能被正确地记录和执行，模拟饮品的制作和通知过程。
