/**
 * @file test_memory.cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Teste la classe Memory
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "test.hpp"
// #include "memory.hpp"
#include <iostream>

int test_memory(Memory* mem, std::string label, int size, int access) {
    Memory memory = *mem;

    // Test the label and type
    if (memory.getLabel() != label) {
        std::cout << "Error: label is not \"" << label << "\"" << std::endl;
        return 1;
    }
    if (memory.getType() != MEMORY) {
        std::cout << "Error: type is not MEMORY" << std::endl;
        return 1;
    }

    // Test the access time
    if (memory.getAccess() != access) {
        std::cout << "Error: access time is not " << access << std::endl;
        return 1;
    }

    // Test the read and write methods
    dataValue value;
    value.value = 10;
    value.flag = true;
    memory.write(value);
    dataValue readValue = memory.read();
    if (readValue.value != 10 || readValue.flag != true) {
        std::cout << "Error: read value is not correct" << std::endl;
        return 1;
    }

    // Test the simulate method
    memory.simulate();
    readValue = memory.read();
    if (readValue.flag != false) {
        std::cout << "Error: read flag is not false after simulate" << std::endl;
        return 1;
    }

    return 0;
}

int main() {
    std::string label = "memory";
    Memory memory(MEMORY, label, 100, 10, "../data/basic_program.txt");

    return test_memory(&memory, label, 100, 10);
}