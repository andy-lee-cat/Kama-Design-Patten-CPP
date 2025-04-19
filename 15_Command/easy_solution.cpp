#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::string command;
    std::unordered_set<std::string> mune = {
        "MilkTea",
        "Coffee",
        "Cola"
    };

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> command;
        auto it = mune.find(command);
        if (it != mune.end()) {
            std::cout << command << " is ready!" << std::endl;
        } else {
            std::cout << command << " is not on the menu!" << std::endl;
        }
    }
}
