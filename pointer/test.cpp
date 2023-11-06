#include <iostream>
#include <string>

class ptrMemberVarType {
public:
    ptrMemberVarType();

private:
    int x;
    int lenP;
    int* p;
};

using namespace std;

int main() {
    ptrMemberVarType objectOne;
    ptrMemberVarType objectTwo;

    return 0;
}

ptrMemberVarType::ptrMemberVarType() {
    cout << "-> [Constructor] " << endl;
}