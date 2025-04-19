// Need to use Python eval function
#include <iostream>

std::string eval(std::string content) {
    // python eval
    // eval("1+1*2") -> 3
    std::string ans = "0";
    return ans;
}

int main() {
    std::string content;
    std::string ans = "0";
    
    std::cin >> content;
    // no easy solution for this problem
    ans = eval(content);  
    std::cout << ans << std::endl;
}
