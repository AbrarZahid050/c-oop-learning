#include <iostream>

using namespace std;

template <class Type>
Type larger(Type x, Type y);

int main() {
    larger(5, 6);
    larger("hello", "hello world");
    return 0;
}

template <class Type>
Type larger(Type x, Type y) {
    if (x >= y) {
        cout << "-> [larger] " << x << " is larger\n";
        return x;
    }
    else {
        cout << "-> [larger] '" << y << "' is larger\n";
        return y;
    }
}