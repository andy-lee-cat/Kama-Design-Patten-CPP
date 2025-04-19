// bridge
#include <iostream>
#include <memory>

class TV {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void tuneChannel() = 0;
};

class SonyTV : public TV {
public:
    void on() override {
        std::cout << "Sony TV is ON" << std::endl;
    }
    void off() override {
        std::cout << "Sony TV is OFF" << std::endl;
    }
    void tuneChannel() override {
        std::cout << "Switching Sony TV channel" << std::endl;
    }
};

class TCLTV : public TV {
public:
    void on() override {
        std::cout << "TCL TV is ON" << std::endl;
    }
    void off() override {
        std::cout << "TCL TV is OFF" << std::endl;
    }
    void tuneChannel() override {
        std::cout << "Switching TCL TV channel" << std::endl;
    }
};

class RemoteControl {
public:
    RemoteControl(std::shared_ptr<TV> tv) : tv(tv) {}
    void on() {
        tv->on();
    }
    void off() {
        tv->off();
    }
    void tuneChannel() {
        tv->tuneChannel();
    }
private:
    std::shared_ptr<TV> tv;
};

int main() {
    int n;
    int tv_brand, tv_operation;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tv_brand >> tv_operation;

        std::shared_ptr<TV> tv;
        if (tv_brand == 0) {
            tv = std::make_shared<SonyTV>();
        } else if (tv_brand == 1) {
            tv = std::make_shared<TCLTV>();
        } else {
            std::cout << "Invalid TV brand" << std::endl;
            continue;  
        }

        RemoteControl remote(tv);

        if (tv_operation == 2) {
            remote.on();
        } else if (tv_operation == 3) {
            remote.off();
        } else if (tv_operation == 4) {
            remote.tuneChannel();
        } else {
            std::cout << "Invalid operation" << std::endl;
        }
    }
}
