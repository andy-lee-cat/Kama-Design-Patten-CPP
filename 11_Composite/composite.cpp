// composite
// 这道题的输入数据不支持在一个部门下还设有子部门，
// 所以main(client)的代码不涉及这部分，
// 但是在几个class的设计中是支持的，如果在部门下插入新部门，show()可以正确递归调用
#include <iostream>
#include <vector>
#include <memory>

class Component {
public:
    virtual void add(std::shared_ptr<Component> component) = 0;
    virtual void show(int level = 0) = 0;
};

class DepartmentComposite : public Component {
public:
    DepartmentComposite(std::string& name) : name(name) {}
    void add(std::shared_ptr<Component> component) override {
        composites.push_back(component);
    }
    void show(int level = 0) override {
        std::cout << std::string(level * 2, ' ') << name << std::endl;
        for (auto& composite : composites) {
            composite->show(level + 1);
        }
    }
private:
    std::string name;
    std::vector<std::shared_ptr<Component>> composites;
};

class EmployeeLeaf : public Component {
public:
    EmployeeLeaf(std::string& name) : name(name) {}
    void add(std::shared_ptr<Component> component) override {}
    void show(int level = 0) override {
        std::cout << std::string(level * 2, ' ') << name << std::endl;
    }
private:
    std::string name;
};

int main() {
    std::string name;
    int n;
    char info_type;
    std::string info_name;
    
    std::cin >> name;
    std::cin >> n;
    auto company = std::make_shared<DepartmentComposite>(name);
    auto now_department = company;
    for (int i = 0; i < n; i++) {
        std::cin >> info_type;
        std::cin >> info_name;
        if (info_type == 'D') {
            now_department = std::make_shared<DepartmentComposite>(info_name);
            company->add(now_department);
        } else if (info_type == 'E') {
            now_department->add(std::make_shared<EmployeeLeaf>(info_name));
        }
    }
    
    std::cout << "Company Structure:" << std::endl;
    company->show();
}
