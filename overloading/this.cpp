#include <iostream>

using namespace std;

class base {
public:
    void print() const {
        cout << "-> [print] x: " << one << endl;
    }

    void setOne(int num) {
        cout << "-> [setOne]\n";
        one = num;
    }

    base test();

private:
    int one;
};

// 
base base::test() {
    cout << "-> [test]\n";
    return *this;
}

int main() {
    base x, y;
    x.setOne(10);
    y.print();
    y = x.test(); // Copy the values (all the member variables x into y) of x into y.
    y.print();
    x.setOne(20);
    y.print();

    return 0;
}