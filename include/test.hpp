/**
 * @file test.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Test header file
 * @version 0.1
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TEST_HPP
#define TEST_HPP

#include "component.hpp"
#include "platform.hpp"
#include "cpu.hpp"
#include "bus.hpp"

int test_cpu(Cpu cpu, string label);
int test_bus(Bus bus);
int test_plateform(Platform platform);

#endif // TEST_HPP