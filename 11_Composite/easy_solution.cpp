#include <iostream>
#include <vector>

int main() {
    std::string name;
    int n;
    std::vector<std::string> departmant_names;
    std::vector<std::vector<std::string>> departmant_employees;
    char info_type;
    std::string info_name;

    std::cin >> name;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> info_type;
        std::cin >> info_name;
        if (info_type == 'D') {
            departmant_names.push_back(info_name);
            departmant_employees.push_back(std::vector<std::string>());
        } else if (info_type == 'E') {
            departmant_employees.back().push_back(info_name);
        }
    }

    std::cout << "Company Structure:" << std::endl;
    std::cout << "MyCompany" << std::endl;
    for (int i = 0; i < departmant_names.size(); i++) {
        std::cout << "  " << departmant_names[i] << std::endl;
        for (int j = 0; j < departmant_employees[i].size(); j++) {
            std::cout << "    " << departmant_employees[i][j] << std::endl;
        }
    }
}
