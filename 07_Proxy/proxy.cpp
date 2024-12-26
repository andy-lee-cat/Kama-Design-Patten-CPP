// proxy
#include<iostream>
#include<memory>

class House {
public:
    House(int area) : area(area) {}
    int getArea() { return area; }
private:
    int area;
};

class People {
public:
    People(std::string name) : name(name) {}
    virtual void checkHouse(std::shared_ptr<House> house) = 0;
private:
    std::string name;
};

class NormalPeople : public People {
public:
    NormalPeople(std::string name) : People(name) {}
    void checkHouse(std::shared_ptr<House> house) override {}
};

class ProxyPeople : public People {
public:
    ProxyPeople(std::string name, std::shared_ptr<NormalPeople> normalPeople)
        : People(name), normalPeople(normalPeople) {}
    void checkHouse(std::shared_ptr<House> house) override {
        if (house->getArea() > 100) {
            std::cout << "YES" << std::endl;
            normalPeople->checkHouse(house);
        } else {
            std::cout << "NO" << std::endl;
        } 
    }
private:
    std::shared_ptr<NormalPeople> normalPeople;
};

int main() {
    int n;
    int area;
    std::shared_ptr<House> house;
    auto normalPeople = std::make_shared<NormalPeople>("Xiao Ming");
    auto proxyPeople = std::make_shared<ProxyPeople>("proxy", normalPeople);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> area;
        house = std::make_shared<House>(area);
        proxyPeople->checkHouse(house);
    }
}
