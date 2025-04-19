// Singleton
#include <iostream>
#include <vector>
#include <memory>
#include <tuple>
#include <mutex>

class ShoppingCart {
public:
    static std::shared_ptr<ShoppingCart> getInstance() {
        if (!instance) {
            std::lock_guard<std::mutex> lock(mtx);
            instance = std::shared_ptr<ShoppingCart>(new ShoppingCart);
        }
        return instance;
    }
    void addItem(const std::string& item, int cnt) {
        items.push_back({item, cnt});
    }
    void info() {
        for (const auto& [item, cnt] : items) {
            std::cout << item << " " << cnt << std::endl;
        }
    }
protected:
    ShoppingCart() {}
private:
    static std::shared_ptr<ShoppingCart> instance;
    static std::mutex mtx;
    std::vector<std::pair<std::string, int>> items;
    ShoppingCart(const ShoppingCart&) = delete;  // 禁止调用这个函数
    ShoppingCart& operator=(const ShoppingCart&) = delete;
};

std::mutex ShoppingCart::mtx;
std::shared_ptr<ShoppingCart> ShoppingCart::instance = nullptr;

int main() {
    std::string name;
    int cnt;

    auto cart = ShoppingCart::getInstance();
    while (std::cin >> name >> cnt) {
        cart->addItem(name, cnt);
    }
    cart->info();
    return 0;
}
