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
    void setBreed(std::string);
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

void dogType::setBreed(std::string b) {
    breed = b;
}

void callPrint(petType* p) {
    p->print();
}

int main() {
    // petType pet("Jimmy");
    // dogType dog("Tommy", "husky");
    // pet = dog;
    // pet.print();

    // the above statement will only copy name member variable of drived class.
    // this is called "slicing problem" in C++.

    // ------------------------------------------------------------
    // C++ offers a way to treat a dogType object as a petType 
    // object without losing the additional properties of the class dogType by using pointers.
    petType* pet;
    dogType* dog;
    dog = new dogType("Tommy", "Husky");
    dog->setBreed("shintu");
    pet = dog;

    pet->print();

    return 0;
}