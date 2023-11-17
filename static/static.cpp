#include <iostream>


void func() {
    static int count = 0;
    count++;
    std::cout << "-> " << count << std::endl;
}

int main() {
    func();
    func();
    return 0;
}