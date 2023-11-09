#include <iostream>

class petType {
public:
    virtual void print();
};

class dogType : public petType {
public:
    void print();
};

void petType::print() {
    std::cout << "-> [petType]\n";
}

void dogType::print() {
    std::cout << "-> [dogType]\n";
}

void callPrint(petType& p) {
    p.print();
}

int main() {
    petType pet;
    dogType dog;

    std::cout << "*** Calling callPrint ***\n";
    callPrint(dog);
}