// decorator
#include <iostream>
#include <memory>

class Coffee {
public:
    virtual void brew() = 0;
};

class BlackCoffee : public Coffee {
public:
    void brew() override {
        std::cout << "Brewing Black Coffee" << std::endl;
    }
};

class Latte : public Coffee {
public:
    void brew() override {
        std::cout << "Brewing Latte" << std::endl;
    }
};

class CoffeeDecorator : public Coffee {
public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(coffee) {}
    void brew() override {
        coffee->brew();
    }
private:
    std::shared_ptr<Coffee> coffee;
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    void brew() override {
        CoffeeDecorator::brew();
        std::cout << "Adding Milk" << std::endl;
    }
};  

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    void brew() override {
        CoffeeDecorator::brew();
        std::cout << "Adding Sugar" << std::endl;
    }
};

// 工厂函数：创建咖啡
std::shared_ptr<Coffee> createCoffee(int coffeeType) {
    switch (coffeeType) {
        case 1: return std::make_shared<BlackCoffee>();
        case 2: return std::make_shared<Latte>();
        default:
            std::cerr << "Invalid coffee selection!" << std::endl;
            return nullptr;
    }
}

// 工厂函数：创建调料
std::shared_ptr<Coffee> addFlavor(std::shared_ptr<Coffee> coffee, int flavorType) {
    if (!coffee) return nullptr;
    switch (flavorType) {
        case 1: return std::make_shared<MilkDecorator>(coffee);
        case 2: return std::make_shared<SugarDecorator>(coffee);
        default:
            std::cerr << "Invalid flavor selection!" << std::endl;
            return nullptr;
    }
}

int main() {
    int coffee, flavor;
    while (std::cin >> coffee >> flavor) {
        auto coffeePtr = createCoffee(coffee);
        if (!coffeePtr) continue;
        auto coffeeWithFlavor = addFlavor(coffeePtr, flavor);
        if (!coffeeWithFlavor) continue;
        coffeeWithFlavor->brew();
    }
}
