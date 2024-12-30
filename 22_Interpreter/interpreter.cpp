// interpreter
// by chatgpt 4o
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <memory>
#include <cctype>
#include <map>

// 抽象表达式类
class Expression {
public:
    virtual int interpret() const = 0;
    virtual ~Expression() = default;
};

// 数字表达式
class NumberExpression : public Expression {
    int value;

public:
    explicit NumberExpression(int value) : value(value) {}
    int interpret() const override {
        return value;
    }
};

// 加法表达式
class AddExpression : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    AddExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left(std::move(left)), right(std::move(right)) {}

    int interpret() const override {
        return left->interpret() + right->interpret();
    }
};

// 乘法表达式
class MultiplyExpression : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    MultiplyExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left(std::move(left)), right(std::move(right)) {}

    int interpret() const override {
        return left->interpret() * right->interpret();
    }
};

// 解析器类
class ExpressionParser {
    std::map<std::string, int> precedence{
        {"+", 1}, {"*", 2} // 定义操作符优先级
    };

    bool isOperator(const std::string& token) const {
        return token == "+" || token == "*";
    }

    int getPrecedence(const std::string& op) const {
        return precedence.at(op);
    }

    // 构造操作符表达式
    std::shared_ptr<Expression> createOperatorExpression(
        const std::string& op,
        std::shared_ptr<Expression> left,
        std::shared_ptr<Expression> right) const {
        if (op == "+") {
            return std::make_shared<AddExpression>(left, right);
        } else if (op == "*") {
            return std::make_shared<MultiplyExpression>(left, right);
        }
        throw std::invalid_argument("Unsupported operator: " + op);
    }

public:
    std::shared_ptr<Expression> parse(const std::string& input) {
        std::istringstream tokens(input);
        std::stack<std::shared_ptr<Expression>> values; // 保存操作数
        std::stack<std::string> operators;             // 保存操作符

        std::string token;
        while (tokens >> token) {
            if (isdigit(token[0])) {
                // 如果是数字，直接创建数字表达式并压入操作数栈
                values.push(std::make_shared<NumberExpression>(std::stoi(token)));
            } else if (isOperator(token)) {
                // 如果是操作符，处理操作符优先级
                while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token)) {
                    auto right = values.top();
                    values.pop();
                    auto left = values.top();
                    values.pop();
                    auto op = operators.top();
                    operators.pop();

                    values.push(createOperatorExpression(op, left, right));
                }
                // 当前操作符入栈
                operators.push(token);
            }
        }

        // 处理剩余的操作符
        while (!operators.empty()) {
            auto right = values.top();
            values.pop();
            auto left = values.top();
            values.pop();
            auto op = operators.top();
            operators.pop();

            values.push(createOperatorExpression(op, left, right));
        }

        // 栈顶元素就是整个表达式的结果
        return values.top();
    }
};

int main() {
    std::string line;

    // 读取输入行
    while (std::getline(std::cin, line)) {
        if (line.empty()) break;

        try {
            ExpressionParser parser;
            auto expression = parser.parse(line);
            std::cout << expression->interpret() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}

