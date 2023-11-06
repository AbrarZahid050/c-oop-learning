#include <iostream>
#include <string>

using namespace std;

class studentType {
public:
    void setName(string = "none");
    string name;
};

int main() {
    studentType myStudent;
    studentType* studentPtr;

    studentPtr = &myStudent;

    studentPtr->setName();
    cout << myStudent.name << endl;
    studentPtr->setName("abrar");
    cout << myStudent.name << endl;
    return 0;
}

void studentType::setName(string studentName) {
    name = studentName;
}