// mediator
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

class User {
public:
    User(const std::string& name) : name(name) {}
    std::string getName() const {
        return name;
    }
    void receiveMsg(const std::string& message) {
        std::cout << name << " received: " << message << std::endl;
    }
private:
    std::string name;
};

class Director {
public:
    void addUser(std::shared_ptr<User> user) {
        if (user_map.find(user->getName()) != user_map.end()) {
            std::cout << "User: " << user->getName() << " already exists" << std::endl;
            return;
        }
        users.push_back(user);
        user_map[user->getName()] = user;
    }
    void sendMessage(const std::string& user, const std::string& message) {
        if (user_map.find(user) == user_map.end()) {
            std::cout << "User: " << user << " not found" << std::endl;
        } else {
            for (const auto& u : users) {
                if (u->getName() != user) {
                    u->receiveMsg(message);
                }
            }
        }
    }
private:
    std::vector<std::shared_ptr<User>> users;
    std::unordered_map<std::string, std::shared_ptr<User>> user_map;
};

int main() {
    int n;
    std::string name, message;
    auto director = std::make_shared<Director>();
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> name;
        auto user= std::make_shared<User>(name);
        director->addUser(user);
    }

    while (std::cin >> name >> message) {
        director->sendMessage(name, message);
    }
}
