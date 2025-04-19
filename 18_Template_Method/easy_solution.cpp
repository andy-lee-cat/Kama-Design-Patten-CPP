#include <iostream>
#include <vector>

int main() {
    int type;
    std::vector<std::string> same_ops = {
        "Grinding coffee beans\nBrewing coffee\n",
        "Adding condiments\n\n"
    };
    
    while (std::cin >> type) {
        if (type == 1) {
            std::cout << "Making American Coffee:" << std::endl;
            std::cout << same_ops[0];
            std::cout << same_ops[1];
        } else if (type == 2) {
            std::cout << "Making Latte:" << std::endl;
            std::cout << same_ops[0];
            std::cout << "Adding milk\n";
            std::cout << same_ops[1];
        } else {
            std::cout << "Invalid type" << std::endl;
        }
    }
}
