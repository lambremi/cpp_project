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

int main() {
    string label = "memory";
    Memory memory(MEMORY, label, 100, 10, "../data/basic_program.txt");

    return memory.test(label, 10);
}