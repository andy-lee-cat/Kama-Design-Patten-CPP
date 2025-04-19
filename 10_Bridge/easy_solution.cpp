#include <iostream>

int main() {
    int n;
    int tv_brand;
    int tv_operation; 

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tv_brand >> tv_operation;
        if (tv_brand == 0) {
            if (tv_operation == 2) {
                std::cout << "Sony TV is ON" << std::endl;
            } else if (tv_operation == 3) {
                std::cout << "Sony TV is OFF" << std::endl;
            } else if (tv_operation == 4) {
                std::cout << "Switching Sony TV channel" << std::endl; 
            } else {
                std::cout << "Invalid operation" << std::endl;
            }
        } else if (tv_brand == 1) {
            if (tv_operation == 2) {
                std::cout << "TCL TV is ON" << std::endl;
            } else if (tv_operation == 3) {
                std::cout << "TCL TV is OFF" << std::endl;
            } else if (tv_operation == 4) {
                std::cout << "Switching TCL TV channel" << std::endl; 
            } else {
                std::cout << "Invalid operation" << std::endl;
            }
        } else {
            std::cout << "Invalid TV brand" << std::endl;
        }
    }
}