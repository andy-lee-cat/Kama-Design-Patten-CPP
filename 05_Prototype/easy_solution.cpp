#include <iostream>

int main() {
    std::string color;
    int width, height;
    int cnt;

    std::cin >> color >> width >> height;
    std::cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        std::cout << "Color: " << color;
        std::cout << ", Width: " << width;
        std::cout << ", Height: " << height << std::endl;
    }
}