#include "test.hpp"

int test_cpu(Cpu cpu, string label) {
    dataValue value;
    if (cpu.getLabel() != label) {
        cout << "Error: label is not \"" << label << "\"" << endl;
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

int main () {
    string label = "cpu";
    Cpu cpu(CPU, label, "../data/basic_program.txt", 2, 3);
    
    return test_cpu(cpu, label);
}