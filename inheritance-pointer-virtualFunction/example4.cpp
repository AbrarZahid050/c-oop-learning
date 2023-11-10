#include <iostream>

using namespace std;

class Base {
public:
    virtual void print() {
        cout << "-> [base] print.\n";
    }
};

class Drived : public Base {
public:
    void print() {
        cout << "-> [drived] print.\n";
    }
};

int main() {
    Base* basePtr;
    Drived drive;

    basePtr = &drive;

    basePtr->print();
    return 0;
}

