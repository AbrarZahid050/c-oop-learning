#include <iostream>
#include <string>

using namespace std;

class ptrMemberVarType {
public:
    void setArr();
    void getArr();
    ptrMemberVarType(string&);  // Constructor
    ~ptrMemberVarType(); // Destructor - testing when it runs.
    ptrMemberVarType(const ptrMemberVarType& otherObject); // Copy-constructor.

private:
    string name;
    int lenP;
    int* p;
};


ptrMemberVarType::ptrMemberVarType(string& name) {
    ptrMemberVarType::name = name;
    p = new int[2];
}

ptrMemberVarType::~ptrMemberVarType() {
    delete[] p;
    cout << "-> [Destructor] " << name << endl;
}

ptrMemberVarType::ptrMemberVarType(const ptrMemberVarType& otherObject) {
    cout << "-> [Copy-constructor] \n";
    p = new int[2];
    for (int i = 0; i < 2; i++) {
        p[i] = otherObject.p[i];
    }
}

void ptrMemberVarType::setArr() {
    p[0] = 10;
    p[1] = 20;
}

void ptrMemberVarType::getArr() {
    for (int i = 0; i <= 1; i++) {
        cout << "--> [getArr] " << name << " p[" << i << "] " << p[i] << endl;
    }
}

void destoryList(ptrMemberVarType objectThree) {
    cout << "-> [destoryList]\n";
}


int main() {
    string name1 = "Obj-1";
    string name2 = "Obj-2";
    ptrMemberVarType objectOne(name1);
    ptrMemberVarType objectTwo(name2);

    objectOne.setArr();

    // objectTwo = objectOne;
    // the above statement makes the two objects "this" pointer same, in other words
    // making the memory addr the same. so when the dynamic allocated memory is deallocated
    // in the Destructor, the compiler gives big fat error.

    cout << "-> [main] before copy-constructor\n";
    destoryList(objectOne);

    cout << "-> [main] before getArr().\n";
    objectOne.getArr();

    return 0;
}