// iterator
#include <iostream>
#include <memory>
#include <vector>

class Student {
public:
    Student(const std::string& name, const std::string& id) :
        name(name), id(id) {}
    std::string getName() const { return name; }
    std::string getId() const { return id; }
private:
    std::string name;
    std::string id;
};

template<class T>
class Iterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T currentItem() const = 0;
};

template<class T>
class ListIterator : public Iterator<T> {
public:
    // if you don't change the list, you should use "const".
    ListIterator(const std::vector<T>& list) : list(list), current(0) {}
    void first() override { current = 0; }
    void next() override { current++; }
    bool isDone() const override { return current >= list.size(); }
    T currentItem() const override { return list[current]; }
private:
    const std::vector<T>& list;
    int current;
};

// traverser use an iterator to traverse a list of items
// so that we can change the traversal algorithm easily by changing the iterator
template<class T>
class Traverser {
public:
    Traverser(std::vector<T>& items) : items(items) {}
    void traverse(std::shared_ptr<Iterator<T>> iterator) {
        for (iterator->first(); !iterator->isDone(); iterator->next()) {
            auto item = iterator->currentItem();
            processItem(item);
        }
    }
    virtual void processItem(const T& item) = 0;
private:
    std::vector<T>& items;
};

class StudentTraverser : public Traverser<Student> {
public:
    StudentTraverser(std::vector<Student>& students) : Traverser(students) {}
    void processItem(const Student& student) override {
        std::cout << student.getName() << " " << student.getId() << std::endl;
    }
};

int main() {
    int n;
    std::string name;
    std::string id;
    std::vector<Student> students;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> id;
        students.push_back(Student(name, id));
    }

    StudentTraverser traverser(students);
    traverser.traverse(std::make_shared<ListIterator<Student>>(students));
}
