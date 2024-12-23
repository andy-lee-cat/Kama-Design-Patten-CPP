#include<iostream>
#include<unordered_set>

int main() {
    int n;
    int cnt;
    std::string block_type;
    std::unordered_set<std::string> set = {
        "Circle", 
        "Square"
    };

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> block_type >> cnt;
        auto it = set.find(block_type);
        if (it != set.end()) {
            for (int j = 0; j < cnt; j++) {
                std::cout << block_type << " " << "Block" << std::endl;
            }
        } else {
            std::cout << "Invalid Block Type" << std::endl;
        }
    }
}