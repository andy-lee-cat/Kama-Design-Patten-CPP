// observer
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Subject;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(std::shared_ptr<Subject> theChangedSubject) = 0;
};

class Subject : public std::enable_shared_from_this<Subject> {
public:
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }
    void detach(std::shared_ptr<Observer> observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }
    void notify() {
        for (auto& observer : observers) {
            observer->update(shared_from_this());
        }
    }
    void updateState() {
        state++;
    }
    int getState() const {
        return state;
    }
private:
    std::vector<std::shared_ptr<Observer>> observers;
    int state = 0;
};

class Student : public Observer {
public:
    Student(std::string name) : name(name) {}
    void update(std::shared_ptr<Subject> theChangedSubject) override {
        std::cout << name << " " << theChangedSubject->getState() << std::endl;
    }
private:
    std::string name;
};

int main() {
    int n;
    auto aClock = std::make_shared<Subject>();
    int time;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string student_name;
        std::cin >> student_name;
        auto student = std::make_shared<Student>(student_name);
        aClock->attach(student);
    }

    std::cin >> time;
    for (int i = 1; i <= time; i++) {
        aClock->updateState();
        aClock->notify();
    }
}
