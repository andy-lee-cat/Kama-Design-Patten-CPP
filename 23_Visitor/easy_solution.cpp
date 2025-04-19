#include <iostream>
#include <limits>

int main() {
    int n;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string shape;
        std::cin >> shape;
        if (shape == "Circle") {
            int r;
            std::cin >> r;
            std::cout << 3.14 * r * r << std::endl;
        } else if (shape == "Rectangle") {
            int width, height;
            std::cin >> width >> height;
            std::cout << width * height << std::endl;
        } else {
            std::cerr << "Unknown shape: " << shape << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
