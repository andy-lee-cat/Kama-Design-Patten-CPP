// state
#include<iostream>
#include<memory>

class Context;

class State {
public:
    virtual void show() = 0;
    void handle(std::shared_ptr<Context>, const std::string&);
protected:
    virtual void changeState(std::shared_ptr<Context>, std::shared_ptr<State>) = 0;
};

// If you want to use the shared_from_this() function, 
// you must inherit from public std::enable_shared_from_this<CLASSNAME>.
class Context : public std::enable_shared_from_this<Context> {
public:
    Context(std::shared_ptr<State> state);
    void request(const std::string& message) {
        state->handle(shared_from_this(), message);
        state->show();
    }
    void setState(std::shared_ptr<State> state) {
        this->state = state;
    }
private:
    std::shared_ptr<State> state;
};

class StateOn : public State {
public:
    void show() {
        std::cout << "Light is ON\n";
    }
protected:
    void changeState(std::shared_ptr<Context> context, std::shared_ptr<State> nextState) override {
        context->setState(nextState);
    }
};

class StateOff : public State {
public:
    void show() {
        std::cout << "Light is OFF\n";
    }
protected:
    void changeState(std::shared_ptr<Context> context, std::shared_ptr<State> nextState) override {
        context->setState(nextState);
    }
};

class StateBlink : public State {
public:
    void show() {
        std::cout << "Light is Blinking\n";
    }
protected:
    void changeState(std::shared_ptr<Context> context, std::shared_ptr<State> nextState) override {
        context->setState(nextState);
    }
};

Context::Context(std::shared_ptr<State> state) {
    setState(state);
}

void State::handle(std::shared_ptr<Context> context, const std::string& message) {
    if (message == "ON") {
        changeState(context, std::make_shared<StateOn>());
    } else if (message == "OFF") {
        changeState(context, std::make_shared<StateOff>());
    } else if (message == "BLINK") {
        changeState(context, std::make_shared<StateBlink>());
    }
}

int main() {
    int n;
    std::string message;

    std::shared_ptr<State> state = std::make_shared<StateOff>();
    std::shared_ptr<Context> context = std::make_shared<Context>(state);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> message;
        context->request(message);
    }
}
