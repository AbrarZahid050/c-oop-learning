#include <iostream>
#include <string>

class ptrMemberVarType {
public:
    ptrMemberVarType(); // Constructor
    ~ptrMemberVarType(); // Destructor

private:
    int x;
    int lenP;
    int* p;
};

using namespace std;

int main() {
    ptrMemberVarType objectOne;
    ptrMemberVarType objectTwo;

    cout << "=> [main]" << endl;
    return 0;
}

ptrMemberVarType::ptrMemberVarType() {
    cout << "-> [Constructor] " << endl;
}

ptrMemberVarType::~ptrMemberVarType() {
    cout << "-> [Destructor] clean-up." << endl;
}