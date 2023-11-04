/**
 * @file test_platform.cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Test de la classe Platform
 * @version 0.1
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// #include <iostream>
// #include <vector>
// #include <string>

#include "test.hpp"

int main() {
    Platform platform("platform", "../data/platform.txt");

    return platform.test("platform",  7);
}