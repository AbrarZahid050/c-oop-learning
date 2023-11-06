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

void testCopyConst(ptrMemberVarType temp);

using namespace std;

int main() {
    cout << "=> [main]\n";
    ptrMemberVarType listOne;
    int num, index;

    cout << "Enter 5 numbers: \n";
    for (index = 0; index < 5; index++) {
        cin >> num;
        listOne.insertAt(index, num);
    }

    listOne.print();
    ptrMemberVarType listTwo(listOne); // this would invoke the copy-constructor.

    cout << "=> [main] listTwo:\n";
    listTwo.print();

    cout << "=> [main] just before testCopyConst.\n";
    testCopyConst(listOne);
    listOne.print();


    return 0;
}

void testCopyConst(ptrMemberVarType temp) {
    cout << "-> [testCopyConst] before change:\n";
    temp.print();
    temp.insertAt(3, 100);
    cout << "-> [testCopyConst] after change:\n";
    temp.print();
    cout << "-> [testCopyConst] before exiting\n";
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
    cout << "-> [print]";
    for (int i = 0; i < length; i++) {
        cout << "   p[" << i << "] - " << p[i] << " ";
    }
    cout << endl;
}

void ptrMemberVarType::insertAt(int index, int num) {
    // cout << "-> [insertAt] index at: " << index << endl;
    assert(index >= 0 && index < maxSize);

    if (index < length) {
        p[index] = num;
    }
    else {
        p[length] = num;
        length++;
    }
}

