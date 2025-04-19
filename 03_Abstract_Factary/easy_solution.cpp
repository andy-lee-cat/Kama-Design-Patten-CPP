#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::vector<std::string> furnitures = {
        "chair",
        "sofa"
    };
    std::set<std::string> valid_types = {
        "modern",
        "classical"
    };
    std::cin >> n;
    std::string s;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        auto it = valid_types.find(s);
        if (it != valid_types.end()) {
            for (auto furniture : furnitures) {
                std::cout << s << " " << furniture << std::endl;
            }
        } else {
            std::cout << "Invalid Furniture Type" << std::endl;
        }
    }
}
