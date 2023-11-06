#include <iostream>

class ptrMemberVarType {
public:
    void print() const;
    void insertAt(int index, int num);
    ptrMemberVarType(int size = 10); // Constructor
    ptrMemberVarType(const ptrMemberVarType& otherObject); // copy-constructor
    ~ptrMemberVarType(); // Destructor

private:
    int maxSize;
    int length;
    int* p;
};

using namespace std;

int main() {
    cout << "=> [main]\n";
    return 0;
}

ptrMemberVarType::ptrMemberVarType(int size) {
    cout << "-> [Constructor]\n";
    if (size <= 0) {
        cout << "<- [Constructor] array size must be greater than 0,\n";
        cout << "    creating an array of size 10.\n";
        maxSize = 10;
    }
    else {
        maxSize = size;
    }
    length = 0;
    p = new int[maxSize];
}

ptrMemberVarType::~ptrMemberVarType() {
    cout << "-> [Destructor] clean-up.\n";
    delete[] p; // deallocating the memory of dynamic array.
}

ptrMemberVarType::ptrMemberVarType(const ptrMemberVarType& otherObject) {
    cout << "-> [Copy-constructor]\n";
    maxSize = otherObject.maxSize;
    length = otherObject.length;
    p = new int[maxSize];

    for (int i = 0; i < length; i++) {
        p[i] = otherObject.p[i];
    }
}

void ptrMemberVarType::print() const {
    cout << "-> [print]\n";
    for (int i = 0; i < length; i++) {
        cout << "   p[" << i << "] - " << p[i] << endl;
    }
}

void ptrMemberVarType::insertAt(int index, int num) {
    assert(index >= 0 && index < maxSize);

    if (index < length) {
        p[index] = num;
    }
    else {
        p[length] = num;
        length++;
    }
}

