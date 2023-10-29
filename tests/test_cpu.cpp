#include "cpu.hpp"

int main () {
    Cpu cpu(CPU, "cpu", "../data/basic_program.txt", 2, 3);
    dataValue value;
    if (cpu.getLabel() != "cpu") {
        cout << "Error: label is not \"cpu\"" << endl;
        return 1;
    }
    if (cpu.getType() != CPU) {
        cout << "Error: type is not CPU" << endl;
        return 1;
    }
    if (cpu.read().flag != false) {
        cout << "Error: read() is not false but nothing happened yet" << endl;
        return 1;
    }
    cpu.simulate();
    value = cpu.read();
    if (value.flag != true) {
        cout << "Error: read() is not true" << endl;
        return 1;
    }
    if (value.value != 5) {
        cout << "Error: first read() is not 5" << endl;
        return 1;
    }
    value = cpu.read();
    if (value.flag != true) {
        cout << "Error: read() is not true" << endl;
        return 1;
    }
    if (value.value != 5) {
        cout << value.value << endl;
        cout << "Error: second read() is not 5" << endl;
        return 1;
    }
    value = cpu.read();
    if (value.flag != false) {
        cout << "Error: read() is not false" << endl;
        return 1;
    }
    return 0;
}