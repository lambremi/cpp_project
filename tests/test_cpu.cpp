#include "test.hpp"

int main () {
    string label = "cpu";
    Cpu cpu(CPU, label, "data/basic_program.txt", 2, 3);
    
    return cpu.test(label);
}