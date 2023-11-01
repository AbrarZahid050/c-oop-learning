// testing protected members of a class:
#include <iostream>

using namespace std;

class baseClass {
public:
    baseClass();  // constructor
    void print() const;
    int publicVar = 10;

private:
    int privateVar = 20;

protected:
    int protectedVar = 30;
};

// Constructor:
baseClass::baseClass() {
    cout << "-> Constructor of baseClass.\n";
}

void baseClass::print() const {
    cout << "-- " << publicVar << " " << privateVar << " " << protectedVar << endl;
}


class drivedClass : public baseClass {
public:
    drivedClass(); // constructor
    void print() const;

};

drivedClass::drivedClass() {
    cout << "-> Constructor of the derivedClass.\n";
}

void drivedClass::print() const {
    cout << "-- " << publicVar << " " << protectedVar << endl;
}

int main() {

    drivedClass myClass;
    myClass.print();
    cout << myClass.publicVar;

    return 0;
}