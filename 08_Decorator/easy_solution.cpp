#include<iostream>
#include<unordered_map>

int main() {
    std::unordered_map<int, std::string> coffeeMenu = {
        {1, "Black Coffee"},
        {2, "Latte"}
    };
    std::unordered_map<int, std::string> flavorMenu = {
        {1, "Milk"},
        {2, "Sugar"}
    };

    int coffee, flavor;
    while (std::cin >> coffee >> flavor) {
        auto it = coffeeMenu.find(coffee);
        if (it != coffeeMenu.end()) {
            std::cout << "Brewing " << it->second << std::endl;
            auto it2 = flavorMenu.find(flavor);
            if (it2 != flavorMenu.end()) {
                std::cout << "Adding " << it2->second << std::endl;
            } else {
                std::cout << "Invalid flavor selection" << std::endl;
            }
        } else {
            std::cout << "Invalid coffee selection" << std::endl;
        }
    }
}
