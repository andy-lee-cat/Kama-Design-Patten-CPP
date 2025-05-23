# 设计模式专题之责任链模式：21-请假审批

## 题目描述
小明所在的公司请假需要在OA系统上发布申请，整个请求流程包括多个处理者，每个处理者负责处理不同范围的请假天数，如果一个处理者不能处理请求，就会将请求传递给下一个处理者，请你实现责任链模式，可以根据请求天数找到对应的处理者。

审批责任链由主管(Supervisor), 经理(Manager)和董事（Director)组成，他们分别能够处理3天、7天和10天的请假天数。如果超过10天，则进行否决。

## 输入描述
第一行是一个整数 `N`（1 <= N <= 100), 表示请求申请的数量。

接下来的N行，每行包括一个请求申请的信息，格式为"姓名 请假天数"

## 输出描述
对于每个请假请求，输出一行，表示该请求是否被批准。如果被批准/否决，输出被哪一个职级的人批准/否决。

## 输入示例
```
4
Alice 2
Bob 5
Tom 10
Jerry 12
```

## 输出示例
```
Alice Approved by Supervisor.
Bob Approved by Manager.
Tom Approved by Director.
Jerry Denied by Director.
```

## 提示信息
请使用责任链模式来实现请假审批流程，确保每个请假请求都能按照规定的天数范围被相应的处理者审批或否决。
