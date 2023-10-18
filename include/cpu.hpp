/**
 * @file cpu.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _CPU_HPP_
#define _CPU_HPP_

#include <string>
#include "component.hpp"

using namespace std;

/**
 * @brief Classe CPU
 * 
 */

class CPU
{
private:
    int n_core;
    string program_path;
    int freq;
    int write(double value);
public:
    CPU(component_t type, string label, int n_core);
    ~CPU();
    dataValue read() const;
    void simulate();
};

#endif // _CPU_HPP_