// flyweight
#include<iostream>
#include<memory>
#include<unordered_map>
#include<tuple>

class Shape {
public:
    virtual void draw(int x, int y, bool is_shared) = 0;
};

class Circle : public Shape {
public:
    void draw(int x, int y, bool is_shared) override {
        if (is_shared) {
            std::cout << "CIRCLE shared at (" << x << ", " << y << ")" << std::endl;
        } else {
            std::cout << "CIRCLE drawn at (" << x << ", " << y << ")" << std::endl;
        }
    }
};

class Rectangle : public Shape {
public:
    void draw(int x, int y, bool is_shared) override {
        if (is_shared) {
            std::cout << "RECTANGLE shared at (" << x << ", " << y << ")" << std::endl;
        } else {
            std::cout << "RECTANGLE drawn at (" << x << ", " << y << ")" << std::endl;
        }
    }
};

class Triangle : public Shape {
public:
    void draw(int x, int y, bool is_shared) override {
        if (is_shared) {
            std::cout << "TRIANGLE shared at (" << x << ", " << y << ")" << std::endl;
        } else {
            std::cout << "TRIANGLE drawn at (" << x << ", " << y << ")" << std::endl;
        }
    }
};

class ShapeFactory {
public:
    std::shared_ptr<Shape> get_shape(const std::string& shape, bool& is_shared) {
        auto it = shapes.find(shape);
        if (it != shapes.end()) {
            is_shared = true;
            return it->second;
        } else {
            is_shared = false;
            std::shared_ptr<Shape> new_shape;
            if (shape == "CIRCLE") {
                new_shape = std::make_shared<Circle>();
            } else if (shape == "RECTANGLE") {
                new_shape = std::make_shared<Rectangle>();
            } else if (shape == "TRIANGLE") {
                new_shape = std::make_shared<Triangle>();
            } else {
                std::cerr << "Invalid shape" << std::endl;
                return nullptr;
            }
            shapes[shape] = new_shape;
            return new_shape;
        }
    }
private:
    std::unordered_map<std::string, std::shared_ptr<Shape>> shapes;
};

class Context {
public:
    std::pair<int, int> get_xy(int id) {
        return pos[id];
    }
    void set_xy(int id, int x, int y) {
        pos[id] = std::make_pair(x, y);
    }
    void add_shape(int id, std::shared_ptr<Shape> shape) {
        shapes[id] = shape;
    }
    std::shared_ptr<Shape> get_shape(int id) {
        return shapes[id];
    }
private:
    std::unordered_map<int, std::pair<int, int>> pos;
    std::unordered_map<int, std::shared_ptr<Shape>> shapes;
};

int main() {
    int id = 0;
    std::string shape;
    int x, y;

    auto factory = std::make_shared<ShapeFactory>();
    auto context = std::make_shared<Context>();
    while (std::cin >> shape >> x >> y) {
        bool is_shared;
        std::shared_ptr<Shape> shape_ptr = factory->get_shape(shape, is_shared);
        if (shape_ptr == nullptr) continue;
        context->add_shape(id, shape_ptr);
        context->set_xy(id, x, y);
        context->get_shape(id)->draw(x, y, is_shared);
        id++;
    }
}
