#include <iostream>

class petType {
public:
    virtual void print();
    petType(std::string = "");
    virtual ~petType();

private:
    std::string name;
};

class dogType : public petType {
public:
    void print();
    void setBreed(std::string);
    dogType(std::string = "", std::string = "");
    ~dogType();

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

void dogType::setBreed(std::string b) {
    breed = b;
}

petType::~petType() {
    std::cout << "~> [petType] destructor.\n";
}

dogType::~dogType() {
    std::cout << "~> [dogType] destructor.\n";
}

void callPrint(petType* p) {
    p->print();
}

int main() {
    petType* pet;
    dogType* dog;

    pet = new petType("Jimmy");
    dog = new dogType("Tommy", "Husky");

    // petType pet("Jimmy");
    // dogType dog("Tommy", "Husky");

    callPrint(dog);

    std::cout << "*** calling callPrint() ***\n";
    delete dog;

    return 0;
}