#include<iostream>
#include<unordered_map>

int main() {
    int n;
    std::unordered_map<std::string, std::string> actions = {
        {"ON", "ON"},
        {"OFF", "OFF"},
        {"BLINK", "Blinking"},
    };
    std::string command;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> command;
        auto it = actions.find(command);
        if (it == actions.end()) {
            std::cout << "Unknown command" << std::endl;
        } else {
            std::cout << "Light is " << it->second << std::endl;
        }
    }
}
