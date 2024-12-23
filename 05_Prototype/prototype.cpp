// prototype
#include<iostream>
#include<memory>

class Rectangle {
private:
    std::string __color;
    int __width;
    int __height;
public:
    Rectangle(const std::string& color, int width, int height) 
        : __color(color), __width(width), __height(height) {}
    std::unique_ptr<Rectangle> clone() const {
        return std::make_unique<Rectangle>(*this);
    }
    void info() const {
        std::cout << "Color: " << __color;
        std::cout << ", Width: " << __width;
        std::cout << ", Height: " << __height << std::endl;
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