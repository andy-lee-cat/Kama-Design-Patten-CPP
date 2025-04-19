// Abstract Factory Pattern
#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

class AbstractProductChair {
public:
    virtual void info() = 0;
    virtual ~AbstractProductChair() = default;
};

class AbstractProductSofa {
public:
    virtual void info() = 0;
    virtual ~AbstractProductSofa() = default;
};

class FurnitureAbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductChair> createChair() = 0;
    virtual std::unique_ptr<AbstractProductSofa> createSofa() = 0;
};

class ModernChair : public AbstractProductChair {
public:
    void info() override {
        std::cout << "modern chair" << std::endl;
    }
};

class ModernSofa : public AbstractProductSofa {
public:
    void info() override {
        std::cout << "modern sofa" << std::endl;
    }
};

class ClassicalChair : public AbstractProductChair {
public:
    void info() override {
        std::cout << "classical chair" << std::endl;
    }
};

class ClassicalSofa : public AbstractProductSofa {
public:
    void info() override {
        std::cout << "classical sofa" << std::endl;
    }
};

class ModernFurnitureFactory : public FurnitureAbstractFactory {
public:
    std::unique_ptr<AbstractProductChair> createChair() override {
        return std::make_unique<ModernChair>();
    }
    std::unique_ptr<AbstractProductSofa> createSofa() override {
        return std::make_unique<ModernSofa>();
    }
};

class ClassicalFurnitureFactory : public FurnitureAbstractFactory {
public:
    std::unique_ptr<AbstractProductChair> createChair() override {
        return std::make_unique<ClassicalChair>();
    }
    std::unique_ptr<AbstractProductSofa> createSofa() override {
        return std::make_unique<ClassicalSofa>();
    }
};

int main() {
    int n;
    std::string s;
    std::unordered_map<std::string, std::shared_ptr<FurnitureAbstractFactory>> factories = {
        {"modern", std::make_shared<ModernFurnitureFactory>()},
        {"classical", std::make_shared<ClassicalFurnitureFactory>()}
    };

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        auto it = factories.find(s);
        if (it != factories.end()) {
            auto factory = it->second;
            auto mychair = factory->createChair();
            auto mysofa = factory->createSofa();
            mychair->info();
            mysofa->info();
        } else {
            std::cout << "Invalid Furniture Type" << std::endl;
        }
    }
}
