#include<iostream>
#include<stack>

int main() {
    std::string cmd;
    enum class Command { inc, dec, undo, redo };
    std::stack<Command> history;
    std::stack<Command> redoHistory;
    int val = 0;

    while (std::cin >> cmd) {
        if (cmd == "Increment") {
            history.push(Command::inc);
            redoHistory.swap(std::stack<Command>());
            std::cout << ++val << '\n';
        } else if (cmd == "Decrement") {
            history.push(Command::dec);
            redoHistory.swap(std::stack<Command>());
            std::cout << --val << '\n';
        } else if (cmd == "Undo") {
            if (!history.empty()) {
                auto last = history.top(); history.pop();
                redoHistory.push(last);
                if (last == Command::inc) {
                    std::cout << --val << '\n';
                } else {
                    std::cout << ++val << '\n';
                }
            } else {
                std::cout << "Nothing to undo\n";
            }
        } else if (cmd == "Redo") {
            if (!redoHistory.empty()) {
                auto last = redoHistory.top(); redoHistory.pop();
                history.push(last);
                if (last == Command::inc) {
                    std::cout << ++val << '\n';
                } else {
                    std::cout << --val << '\n';
                }
            } else {
                std::cout << "Nothing to redo\n";
            }
        } else {
            std::cout << "Invalid command\n";
        }
    }
}
