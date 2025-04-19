// prototype
#include <iostream>
#include <memory>

class Rectangle {
private:
    std::string color;
    int width;
    int height;
public:
    Rectangle(const std::string& color, int width, int height) 
        : color(color), width(width), height(height) {}
    std::unique_ptr<Rectangle> clone() const {
        return std::make_unique<Rectangle>(*this);
    }
    void info() const {
        std::cout << "Color: " << color;
        std::cout << ", Width: " << width;
        std::cout << ", Height: " << height << std::endl;
    } 
};

int main() {
    std::string color;
    int width, height;
    int cnt;


    std::cin >> color >> width >> height;   
    std::cin >> cnt;

    auto prototype = std::make_unique<Rectangle>(color, width, height);

    for (int i = 0; i < cnt; i++) {
        auto r = prototype->clone();  
        r->info();
    }
}
