#include "test.hpp"

int test_bus(Cpu cpu, Bus bus) {
    Component* source = &cpu;
    if (bus.getReadCount() != 0) {
        cout << "Error: Expected bus to have 0 read count\n" << endl;
        return 1;
    }
    if (bus.getWidth() != 3) {
        cout << "Error: Expected bus to have width 3\n" << endl;
        return 1;
    }
    bus.setSource(&cpu);
    bus.getSource(source);
    if (source->getType() != CPU) {
        cout << "Error: Expected bus to have cpu as source\n" << endl;
        return 1;
    }
    if (bus.read().flag) {
        cout << "Error: Expected bus to be empty\n" << endl;
        return 1;
    }
    cpu.simulate();
    bus.simulate();
    bus.simulate();
    dataValue value = bus.read();
    if (bus.getReadCount() != 2) {
        cout << "Error: Expected bus to have 2 read count\n" << endl;
        return 1;
    }
    if (!value.flag) {
        cout << "Error: Expected bus to be not empty 1\n" << endl;
        return 1;
    }
    if (value.value != 5) {
        cout << "Error: Expected bus to first read 5\n" << endl;
        return 1;
    }
    value = bus.read();
    if (!value.flag) {
        cout << "Error: Expected bus to be not empty 2\n" << endl;
        return 1;
    }
    if (value.value != 5) {
        cout << "Error: Expected bus to second read 5\n" << endl;
        return 1;
    }
    value = bus.read();
    if (value.flag) {
        cout << "Error: Expected bus to be empty\n" << endl;
        return 1;
    }
    return 0;
}

int main() {
    Cpu cpu(CPU, "source", "../data/basic_program.txt", 2, 3);
    Bus bus(BUS, "bus", "source", 3);
    
    return test_bus(cpu, bus);
}