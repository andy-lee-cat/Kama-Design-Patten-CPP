// memento
#include<iostream>
#include<unordered_map>
#include<stack>
#include<memory>

enum class Operation {
    Inc,
    Dec,
    Undo,
    Redo
};

class Memento {
public:
    Memento(int state) : state(state) {}
private:
    friend class CounterOriginator;
    int getState() const { return state; }
    int state;
};

// Originator
class CounterOriginator {
public:
    CounterOriginator() : state(0) {}
    void increment() { state++; }
    void decrement() { state--; }
    void restore(const std::shared_ptr<Memento>& memento) {
        state = memento->getState();
    }
    void printState() const {
        std::cout << state << '\n';
    }
    std::shared_ptr<Memento> createMemento() const {
        return std::make_shared<Memento>(state);
    }
private:
    int state;
};

class Caretaker {
public:
    Caretaker(int initialState = 0) {
        history.push(std::make_shared<Memento>(initialState));
    }
    void execute(Operation op, CounterOriginator& originator) {
        switch(op) {
            case Operation::Inc:
            case Operation::Dec:
                action(originator, op);
                break;
            case Operation::Undo:
                undo(originator);
                break;
            case Operation::Redo:
                redo(originator);
                break;
        }
        originator.printState();
    }
    void action(CounterOriginator& originator, Operation op) {
        if (op == Operation::Inc)
            originator.increment();
        else
            originator.decrement();
        history.push(originator.createMemento());
        clearRedoHistory();
    }
    void undo(CounterOriginator& originator) {
        if (history.size() >= 2) {
            redoHistory.push(history.top());
            history.pop();
            auto memento = history.top();
            originator.restore(memento);
        } else {
            std::cout << "Nothing to undo\n";
        }
    }
    void redo(CounterOriginator& originator) {
        if (!redoHistory.empty()) {
            auto memento = redoHistory.top(); 
            redoHistory.pop();
            history.push(memento);
            originator.restore(memento);
        } else {
            std::cout << "Nothing to redo\n";
        }
    }
    void clearRedoHistory() {
        std::stack<std::shared_ptr<Memento>> empty;
        std::swap(redoHistory, empty);
    }
private:
    std::stack<std::shared_ptr<Memento>> history;
    std::stack<std::shared_ptr<Memento>> redoHistory;
};

int main() {
    Caretaker caretaker(0);
    CounterOriginator originator;
    std::unordered_map<std::string, Operation> commands = {
        {"Increment", Operation::Inc},
        {"Decrement", Operation::Dec},
        {"Undo", Operation::Undo},
        {"Redo", Operation::Redo}
    };

    std::string cmd;
    while (std::cin >> cmd) {
        auto it = commands.find(cmd);
        if (it == commands.end()) {
            std::cout << "Invalid command\n";
            continue;
        }
        caretaker.execute(it->second, originator);
    }
}
