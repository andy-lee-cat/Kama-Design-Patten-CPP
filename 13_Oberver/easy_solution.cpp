#include<iostream>
#include<vector>

int main() {
    int n;
    std::vector<std::string> students;
    int time;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string student;
        std::cin >> student;
        students.push_back(student);
    }
    std::cin >> time;

    for (int i = 1; i <= time; i++) {
        for (auto& student : students) {
            std::cout << student << " " << i << std::endl;
        }
    }
}
