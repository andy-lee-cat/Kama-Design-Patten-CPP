#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n;
    std::string user, message;
    std::vector<std::string> users;
    std::unordered_set<std::string> user_set;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> user;
        users.push_back(user);
        user_set.insert(user);
    }

    while (std::cin >> user >> message) {
        if (user_set.find(user) == user_set.end()) {
            std::cout << "User: " << user << " not found" << std::endl;
        } else {
            for (const auto& u : users) {
                if (u != user) {
                    std::cout << u << " received: " << message << std::endl;
                }
            }
        }
    }
}
