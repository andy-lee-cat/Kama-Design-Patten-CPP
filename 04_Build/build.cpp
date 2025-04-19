// build
#include <iostream>
#include <memory>
#include <unordered_map>

class Bike {
private:
    std::string frame;
    std::string tires;
public:
    void setFrame(std::string frame) {
        this->frame = frame;
    }

    void setTires(std::string tires) {
        this->tires = tires;
    }

    std::string getInfo() {
        return frame + " " + tires;
    }
};

class Builder {
public:
    virtual void buildFrame() = 0;
    virtual void buildTires() = 0;
    virtual std::shared_ptr<Bike> getBike() = 0;
};

class Director {
public:
    void construct(std::shared_ptr<Builder> builder) {
        builder->buildFrame();
        builder->buildTires();
    }
};

class MountainBikeBuilder : public Builder {
private:
    std::shared_ptr<Bike> bike;
public:
    MountainBikeBuilder() : bike(std::make_shared<Bike>()) {}
    void buildFrame() override {
        bike->setFrame("Aluminum Frame");
    }
    void buildTires() override {
        bike->setTires("Knobby Tires");
    }
    std::shared_ptr<Bike> getBike() {
        return bike;
    }
};

class RoadBikeBuilder : public Builder {
private:
    std::shared_ptr<Bike> bike;
public:
    RoadBikeBuilder() {
        bike = std::make_shared<Bike>();
    }
    void buildFrame() override {
        bike->setFrame("Carbon Frame");
    }
    void buildTires() override {
        bike->setTires("Slim Tires");
    }
    std::shared_ptr<Bike> getBike() {
        return bike;
    }
};

int main() {
    int n;
    std::string s;
    std::unordered_map<std::string, std::shared_ptr<Builder>> builders = {
        {"mountain", std::make_shared<MountainBikeBuilder>()},
        {"road", std::make_shared<RoadBikeBuilder>()}
    };
    
    std::cin >> n;
    Director director;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        auto it = builders.find(s);
        if (it != builders.end()) {
            auto builder = it->second;
            director.construct(builder);
            auto bike = builder->getBike();
            std::cout << bike->getInfo() << std::endl;
        } else {
            std::cout << "Invalid Bike Type" << std::endl;
        }
    }
}
