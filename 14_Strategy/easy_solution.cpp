#include<iostream>

int main() {
    int n;
    int price;
    int strategy;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> price >> strategy;
        if (strategy == 1) {
            std::cout << static_cast<int>(price * 0.9) << std::endl;
        } else if (strategy == 2) {
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
            std::cout << price - discount << std::endl;
        } else {
            std::cout << "Invalid strategy" << std::endl;
        }
    }
}
