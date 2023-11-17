#include <iostream>

template<class callback>
void test(callback f) {
    f();
}

int main() {
    int i = 5;
    auto f = [&]() {
        std::cout << "hello from closure: i = " << i << std::endl;
        };
    test(f);
}