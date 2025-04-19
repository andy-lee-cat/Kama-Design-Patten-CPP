#include <iostream>
#include <unordered_map>

int main() {
    int n;
    int type_name;
    std::unordered_map<int, std::string> map = {
        {1, "TypeC"},
        {2, "USB Adapter"}
    };
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> type_name;
        auto it = map.find(type_name);
        if (it != map.end()) {
            std::cout << it->second << std::endl;
        } else {
            std::cout << "Unknown type" << std::endl;
        }
    }
}
