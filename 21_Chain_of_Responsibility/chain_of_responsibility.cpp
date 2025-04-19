// chain of responsibility
#include <iostream>
#include <memory>

class Handler {
public:
    Handler(std::shared_ptr<Handler> s = nullptr) : success(s) {}
    virtual void handleRequest(const std::string& name, int day) = 0;
protected:
    std::shared_ptr<Handler> success;
};

class Supervisor : public Handler {
public:
    Supervisor(std::shared_ptr<Handler> s) : Handler(s) {}
    void handleRequest(const std::string& name, int day) override {
        if (day <= 3) {
            std::cout << name << " Approved by Supervisor." << std::endl;
        } else if (success != nullptr) { // check if there is a successor
            success->handleRequest(name, day);
        }
    }
};

class Manager : public Handler {
public:
    Manager(std::shared_ptr<Handler> s) : Handler(s) {}
    void handleRequest(const std::string& name, int day) override {
        if (day <= 7) {
            std::cout << name << " Approved by Manager." << std::endl;
        } else if (success != nullptr) {
            success->handleRequest(name, day);
        }
    }
};

class Director : public Handler {
public:
    Director() : Handler() {}
    Director(std::shared_ptr<Handler> s) : Handler(s) {}
    void handleRequest(const std::string& name, int day) override {
        if (day <= 10) {
            std::cout << name << " Approved by Director." << std::endl;
        } else {
            std::cout << name << " Denied by Director." << std::endl;
        }
    }
};

std::shared_ptr<Handler> createChain() {
    auto director = std::make_shared<Director>(nullptr);
    auto manager = std::make_shared<Manager>(director);
    auto supervisor = std::make_shared<Supervisor>(manager);
    return supervisor;
}

int main() {
    int n;
    std::string name;
    int day;

    auto chain = createChain();
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> day;
        chain->handleRequest(name, day);
    }
}
