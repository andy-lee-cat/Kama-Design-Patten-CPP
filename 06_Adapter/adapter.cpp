// adapter
#include <iostream>
#include <unordered_map>
#include <memory>

class USB {
public:
    void charge() {
        // do nothing
    }
};

class TypeC {
public:
    void charge() {
        std::cout << "TypeC" << std::endl;
    }
};

class USBAdapter {
public:
    USBAdapter(std::shared_ptr<USB> usb) : usb(usb) {}
    void charge() {
        std::cout << "USB Adapter" << std::endl;
        usb->charge(); 
    }
private:
    std::shared_ptr<USB> usb;
};

class Computer {
public:
    Computer(std::shared_ptr<USBAdapter> adapter) : adapter(adapter) {
        typeC = std::make_shared<TypeC>();
    }
    void chargeWithTypeC() {
        typeC->charge();
    }
    void chargeWithAdapter() {
        adapter->charge();
    }
private:
    std::shared_ptr<TypeC> typeC;  
    std::shared_ptr<USBAdapter> adapter;  
};


int main() {
    int n;
    int option;

    // I have a USB
    std::shared_ptr<USB> usb = std::make_shared<USB>();

    // I have a USB adapter
    std::shared_ptr<USBAdapter> adapter = std::make_shared<USBAdapter>(usb);

    // I have a computer with a USB adapter
    std::shared_ptr<Computer> computer = std::make_shared<Computer>(adapter);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> option;
        if (option == 1) {
            computer->chargeWithTypeC();
        } else if (option == 2) {
            computer->chargeWithAdapter();
        } else {
            std::cout << "Invalid option" << std::endl;
        }
    }
}
