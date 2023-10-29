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
#include "register.hpp"


using namespace std;

/**
 * @brief Classe CPU
 * 
 */

class CPU : public Component
{
private:
    int n_core;
    int freq;
    Register reg;
public:
    CPU(component_t type, string label, int n_core, int freq);
    ~CPU();
    dataValue_t read();
    void simulate();
};

#endif // _CPU_HPP_