#include<iostream>

int main() {
    int n;
    std::string name;
    int day;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> day;
        if (day <= 3) {
            std::cout << name << " Approved by Supervisor." << std::endl;
        } else if (day <= 7) {
            std::cout << name << " Approved by Manager." << std::endl;
        } else if (day <= 10) {
            std::cout << name << " Approved by Director." << std::endl;
        } else {
            std::cout << name << " Denied by Director." << std::endl;
        }
    }
}
