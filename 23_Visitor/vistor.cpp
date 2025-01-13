#include<iostream>
#include<limits>
#include<memory>

class Circle;
class Rectangle;

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(Circle&) = 0;
    virtual void visit(Rectangle&) = 0;
};

class AreaVisitor : public Visitor {
public:
    void visit(Circle&) override;
    void visit(Rectangle&) override;
};

class Shape {
public:
    virtual ~Shape() = default;
    virtual void accept(Visitor&) = 0;
};

class Circle : public Shape {
public:
    Circle(int r) : r(r) {}
    void accept(Visitor&) override;
    int getRadius() const { return r; }
private:
    int r;
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : w(w), h(h) {}
    void accept(Visitor&) override;
    int getWidth() const { return w; } 
    int getHeight() const { return h; }
private:
    int w, h;
};

void AreaVisitor::visit(Circle& circle) {
    std::cout << 3.14 * circle.getRadius() * circle.getRadius() << std::endl;
};

void AreaVisitor::visit(Rectangle& rectangle) {
    std::cout << rectangle.getWidth() * rectangle.getHeight() << std::endl;
};

void Circle::accept(Visitor& visitor) {
    visitor.visit(*this);
};

void Rectangle::accept(Visitor& visitor) {
    visitor.visit(*this);
};

int main() {
    int n;

    std::cin >> n;
    std::unique_ptr<Visitor> areaVisitor = std::make_unique<AreaVisitor>();
    
    for (int i = 0; i < n; i++) {
        std::string shape;
        std::cin >> shape;
        if (shape == "Circle") {
            int r;
            std::cin >> r;
            std::unique_ptr<Circle> circle = std::make_unique<Circle>(r);
            circle->accept(*areaVisitor);
        } else if (shape == "Rectangle") {
            int width, height;
            std::cin >> width >> height;
            std::unique_ptr<Rectangle> rectangle = std::make_unique<Rectangle>(width, height);
            rectangle->accept(*areaVisitor);
        } else {
            std::cerr << "Unknown shape: " << shape << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
