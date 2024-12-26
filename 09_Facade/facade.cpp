// facade
#include<iostream>
#include<memory>
#include<unordered_map>

class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class AirConditioner : public Device {
public:
    void turnOn() override {}
    void turnOff() override {}
};

class DeskLamp : public Device {
public:
    void turnOn() override {}
    void turnOff() override {}
};

class Television : public Device {
public:
    void turnOn() override {}
    void turnOff() override {}
};

class ControllerFacade {
public:
    ControllerFacade(std::shared_ptr<AirConditioner> airConditioner,
                     std::shared_ptr<DeskLamp> deskLamp,
                     std::shared_ptr<Television> television)
        : airConditioner(airConditioner), deskLamp(deskLamp), television(television) {}
    void action(int option) {
        switch (option) {
            case 1:
                airConditioner->turnOff();
                std::cout << "Air Conditioner is turned off." << std::endl;
                break;
            case 2:
                deskLamp->turnOff();
                std::cout << "Desk Lamp is turned off." << std::endl;
                break;
            case 3:
                television->turnOff();
                std::cout << "Television is turned off." << std::endl;
                break;
            case 4:
                airConditioner->turnOff();
                deskLamp->turnOff();
                television->turnOff();
                std::cout << "All devices are off." << std::endl;
                break;
            default:
                std::cout << "Invalid device code" << std::endl;
        }
    }
private:
    std::shared_ptr<AirConditioner> airConditioner;
    std::shared_ptr<DeskLamp> deskLamp;
    std::shared_ptr<Television> television;
};

int main() {
    int n;
    int option;
    std::shared_ptr<AirConditioner> airConditioner = std::make_shared<AirConditioner>();
    std::shared_ptr<DeskLamp> deskLamp = std::make_shared<DeskLamp>();
    std::shared_ptr<Television> television = std::make_shared<Television>();
    ControllerFacade controllerFacade(airConditioner, deskLamp, television);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> option;
        controllerFacade.action(option);
    }
}
