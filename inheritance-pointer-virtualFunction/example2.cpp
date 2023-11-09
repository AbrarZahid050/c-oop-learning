#include <iostream>

class petType {
public:
    virtual void print();
    petType(std::string = "");

private:
    std::string name;
};

class dogType : public petType {
public:
    void print();
    dogType(std::string = "", std::string = "");

private:
    std::string breed;
};

petType::petType(std::string n) {
    name = n;
}

dogType::dogType(std::string n, std::string b) : petType(n) {
    breed = b;
}

void petType::print() {
    std::cout << "-> [petType]: " << name << std::endl;
}

void dogType::print() {
    petType::print();
    std::cout << "-> [dogType]: " << breed << std::endl;
}

void callPrint(petType* p) {
    p->print();
}

int main() {
    petType* p;
    dogType* d;

    p = new petType("Jimmy");
    d = new dogType("Tommy", "husky");

    p->print();
    d->print();

    std::cout << "*** calling callPrint() ***\n";
    callPrint(p);
    std::cout << "-----------------------------\n";
    callPrint(d);

    return 0;
}