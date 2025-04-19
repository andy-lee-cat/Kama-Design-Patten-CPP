#include <iostream>
#include <memory>

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual int getPrice(int price) = 0;
};

class FullSubtraction : public Strategy {
public:
    int getPrice(int price) override {
        int discount = 0;
        if (price >= 300) {
            discount = 40;
        } else if (price >= 200) {
            discount = 25;
        } else if (price >= 150) {
            discount = 15;
        } else if (price >= 100) {
            discount = 5;
        }
        return price - discount;
    }
}; 

class PercentageDiscount : public Strategy {
public:
    PercentageDiscount(double discount = 0.9) : discount(discount) {}
    int getPrice(int price) override {
        return static_cast<int>(price * discount);
    }
private:
    double discount;
};

class Context {
public:
    Context(std::shared_ptr<Strategy> strategy) : strategy(strategy) {}
    void setStrategy(std::shared_ptr<Strategy> strategy) {
        this->strategy = strategy;
    }
    int getPrice(int price) {
        if (!strategy) {
            throw std::runtime_error("Strategy is not set");
        }
        return strategy->getPrice(price);
    }
private:
    std::shared_ptr<Strategy> strategy;
};

int main() {
    int n;
    auto DiscountStrategy = std::make_shared<PercentageDiscount>();
    auto FullSubtractionStrategy = std::make_shared<FullSubtraction>();
    Context context(DiscountStrategy);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int price, type;
        std::cin >> price >> type;
        
        try {
            if (type == 1) {
                context.setStrategy(DiscountStrategy);
            } else if (type == 2) {
                context.setStrategy(FullSubtractionStrategy);
            } else {
                throw std::runtime_error("Invalid type");
            }
            std::cout << context.getPrice(price) << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
