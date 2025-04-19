#include <iostream>

int main() {
    int n;
    std::string s;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        if (s == "mountain") {
            std::cout << "Aluminum Frame Knobby Tires" << std::endl;
        } else if (s == "road") {
            std::cout << "Carbon Frame Slim Tires" << std::endl;
        } else {
            std::cout << "Invalid Bicycle Type" << std::endl;
        }
    }
}