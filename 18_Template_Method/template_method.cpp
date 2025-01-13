// template method
#include<iostream>
#include<memory>
#include<unordered_map>

class Coffee {
public:
    ~Coffee() = default;
    void make() {
        showType();
        grind();
        brew();
        addCondiments();
        std::cout << std::endl;
    }
protected:
    void showType() const {
        std::cout << "Making " << type << ": " << std::endl;
    }
    void grind() const {
        std::cout << "Grinding coffee beans" << std::endl;
    }
    void brew() const {
        std::cout << "Brewing coffee" << std::endl;
    }
    virtual void addCondiments() const {
        std::cout << "Adding condiments" << std::endl;
    }
    std::string type;
};

class AmericanCoffee : public Coffee {
public:
    AmericanCoffee() {
        type = "American Coffee";
    }
};

class Latte : public Coffee {
public:
    Latte() {
        type = "Latte";
    }
    void addCondiments() const override {
        std::cout << "Adding milk" << std::endl;
        Coffee::addCondiments();
    }
};

int main() {
    int type;
    std::unordered_map<int, std::shared_ptr<Coffee>> coffee_types = {
        {1, std::make_shared<AmericanCoffee>()},
        {2, std::make_shared<Latte>()}
    };

    while (std::cin >> type) {
        auto it = coffee_types.find(type);
        if (it != coffee_types.end()) {
            it->second->make();
        } else {
            std::cout << "Invalid type" << std::endl;
        }
    }
}
