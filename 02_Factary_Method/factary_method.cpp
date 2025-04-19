// factary method
#include <iostream>
#include <unordered_map>
#include <memory>

class Block {
public:
    virtual void info() = 0;
};

class CricleBlock : public Block {
public:
    void info() override {
        std::cout << "Circle Block" << std::endl;
    }
};

class SquareBlock : public Block {
public:
    void info() override {
        std::cout << "Square Block" << std::endl;
    }
};

class BlockCreator {
public:
    virtual std::unique_ptr<Block> createBlock() = 0; 
};

template <class T>
class StandardBlockCreator : public BlockCreator {
public:
    virtual std::unique_ptr<Block> createBlock() override {
        // 工厂方法的重点在于子类是特定"方法"，而抽象工厂的子类是特定工厂，工厂包含了相互关联的方法
        return std::make_unique<T>();
    }
};


int main() {
    int n;
    int cnt;
    std::string block_type;

    std::unordered_map<std::string, std::shared_ptr<BlockCreator>> factories = {
        {"Circle", std::make_shared<StandardBlockCreator<CricleBlock>>()},
        {"Square", std::make_shared<StandardBlockCreator<SquareBlock>>()}
    };

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> block_type >> cnt;
        auto it = factories.find(block_type);
        if (it != factories.end()) {
            for (int j = 0; j < cnt; j++) {
                auto block = it->second->createBlock();
                block->info();
            }
        } else {
            std::cout << "Invalid block type" << std::endl;
        }
    }
}