#include <iostream>

int main() {
    int n;
    int area;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> area;
        if (area > 100) 
            std::cout << "YES" << std::endl;
        else 
            std::cout << "NO" << std::endl;
    }
}
