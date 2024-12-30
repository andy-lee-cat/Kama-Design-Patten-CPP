// command
#include<iostream>
#include<memory>
#include<queue>
#include<unordered_map>

class Command {
public:
    virtual void execute() = 0;
};

class MilkTeaCommand : public Command {
public:
    void execute() override {
        std::cout << "MilkTea is ready!" << std::endl;
    }
};

class CoffeeCommand : public Command {
public:
    void execute() override {
        std::cout << "Coffee is ready!" << std::endl;
    }
};

class ColaCommand : public Command {
public:
    void execute() override {
        std::cout << "Cola is ready!" << std::endl;
    }
};

class Invoker {
public:
    void addCommand(std::shared_ptr<Command> command) {
        commands.push(command);
    }
    void executeCommands() {
        while (!commands.empty()) {
            auto command = commands.front();
            command->execute();
            commands.pop();
        }
    }
private:
    std::queue<std::shared_ptr<Command>> commands;    
};

class CommandFactory {
public:
    std::shared_ptr<Command> createCommand(const std::string& command) {
        auto it = mune.find(command);
        if (it != mune.end()) 
            return it->second;
        return nullptr;
    }
private:
    std::unordered_map<std::string, std::shared_ptr<Command>> mune = {
        {"MilkTea", std::make_shared<MilkTeaCommand>()},
        {"Coffee", std::make_shared<CoffeeCommand>()},
        {"Cola", std::make_shared<ColaCommand>()}
    };
};

int main() {
    int n;
    std::string command;
    CommandFactory factory;
    Invoker invoker;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> command;
        auto cmd = factory.createCommand(command);
        if (cmd) {
            invoker.addCommand(cmd);
        } else {
            std::cout << command << " is not on the menu!" << std::endl;
        }
    }
    invoker.executeCommands(); 
}
