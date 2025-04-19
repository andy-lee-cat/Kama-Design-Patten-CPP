#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> shapes = {
        "CIRCLE", "RECTANGLE", "TRIANGLE"
    };

    std::string shape;
    int x, y;
    std::unordered_set<std::string> existed_shapes;
    while (std::cin >> shape >> x >> y) {
        auto it = shapes.find(shape);
        if (it != shapes.end()) {
            if (existed_shapes.find(shape) == existed_shapes.end()) {
                std::cout << shape << " drawn at (" << x << ", " << y << ")" << std::endl;
                existed_shapes.insert(shape);
            } else {
                std::cout << shape << " shared at (" << x << ", " << y << ")" << std::endl;
            }
        } else {
            std::cout << "Invalid shape\n" << std::endl;
        }
    }
}
