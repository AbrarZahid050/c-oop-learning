#include <iostream>

using namespace std;

class test {
public:
    test& setX(int val) {
        cout << "-> [setX]\n";
        x = val;
        return *this;
    }

    test& setY(int val) {
        cout << "-> [setY]\n";
        y = val;
        return *this;
    }

    void print() const {
        cout << "-> [print]\n";
        cout << x << y << endl;
    }

private:
    int x;
    int y = 22;
};

int main() {
    test myObj;
    myObj.setX(10).setY(20);
    myObj.print();

    return 0;
}