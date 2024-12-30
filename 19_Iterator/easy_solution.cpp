#include<iostream>
#include<vector>
#include<tuple>

int main() {
    int n;
    std::string name;
    std::string id;
    std::vector<std::pair<std::string, std::string>> students;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> id;
        students.push_back(std::make_pair(name, id));
    }

    for (auto student : students) {
        std::cout << student.first << " " << student.second << std::endl;
    }
}
