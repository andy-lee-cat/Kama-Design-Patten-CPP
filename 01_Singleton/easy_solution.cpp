#include<iostream>

int main() {
    std::string name;
    int cnt;
    while (std::cin >> name >> cnt) {
        std::cout << name << " " << cnt << std::endl;
    } 
}