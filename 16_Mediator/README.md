# 设计模式专题之中介者模式：16-简易聊天室

## 题目描述
小明正在设计一个简单的多人聊天室系统，有多个用户和一个聊天室中介者，用户通过中介者进行聊天，请你帮他完成这个系统的设计。

## 输入描述
- 第一行包括一个整数 `N`，表示用户的数量（1 <= N <= 100）。
- 第二行是 `N` 个用户，比如 `User1 User2 User3`，用空格分隔。
- 第三行开始，每行包含两个字符串，表示消息的发出者和消息内容，用空格分隔。

## 输出描述
对于每个用户，输出一行，包含该用户收到的所有消息内容。

## 输入示例
```
3
User1 User2 User3
User1 Hello_All!
User2 Hi_User1!
User3 How_is_everyone?
```

## 输出示例
```
User2 received: Hello_All!
User3 received: Hello_All!
User1 received: Hi_User1!
User3 received: Hi_User1!
User1 received: How_is_everyone?
User2 received: How_is_everyone?
```

## 提示信息
请使用中介者模式来实现聊天室系统，确保用户之间的消息传递都通过中介者进行，以降低系统组件之间的耦合度。
