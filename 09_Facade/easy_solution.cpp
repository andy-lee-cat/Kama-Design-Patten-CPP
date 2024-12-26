#include<iostream>
#include<unordered_map>

int main() {
    std::unordered_map<int, std::string> map = {
        {1, "Air Conditioner is turned off."},
        {2, "Desk Lamp is turned off."},
        {3, "Television is turned off."},
        {4, "All devices are off."}
    };
    int n;
    int option;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> option;
        auto it = map.find(option);
        if (it != map.end()) {
            std::cout << it->second << std::endl;
        } else {
            std::cout << "Invalid device code" << std::endl;
        }
    }
}
