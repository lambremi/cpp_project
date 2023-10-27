#include <iostream>
#include "register.hpp"

using namespace std;

int main() {
    Register reg;

    // test vide
    if (!reg.isEmpty()) {
        cout << "Error: Expected register to be empty\n" << endl;
        return 1;
    }

    // test write
    reg.write(1.2);
    if (reg.isEmpty()) {
        cout << "Error: Expected register to be not empty\n" << endl;
        return 1;
    }

    // test read
    if (reg.read() != 1.2) {
        cout << "Error: Expected register to read 1.2\n" << endl;
        return 1;
    }
    if (!reg.isEmpty()) {
        cout << "Error: Expected register to be empty\n" << endl;
        return 1;
    }

    return 0;
}