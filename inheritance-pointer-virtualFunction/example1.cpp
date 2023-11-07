#include <iostream>
#include <string>

using namespace std;

class petType {
public:
    void print() const;
    petType(string = "");

private:
    string name;
};

class dogType : public petType {
public:
    void print() const;
    dogType(string = "", string = "");

private:
    string breed;
};

petType::petType(string n) {
    cout << "-> [petType] constructor.\n";
    name = n;
}

void petType::print() const {
    cout << "-> [petType] print: " << name << endl;
}

dogType::dogType(string n, string b) : petType(n) {
    cout << "-> [dogType] constructor.\n";
    breed = b;
}

void dogType::print() const {
    petType::print();
    cout << "-> [dogType] print: " << breed << endl;
}

void callPrint(petType& p);

int main() {
    petType pet("Lucky");
    dogType dog("Tommy", "German Shepherd");

    pet.print();
    dog.print();

    cout << "*** Calling callPrint function ***\n";
    callPrint(pet);
    return 0;
}

void callPrint(petType& p) {
    p.print();
}