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
#include "program.hpp"


using namespace std;

/**
 * @brief Classe CPU
 * 
 */

class Cpu : public Component
{
private:
    int n_core;
    int active_core;
    int freq;
    Register reg;
    Program prog;
public:
    Cpu(component_t type, string label, string path_to_prog, int n_core, int freq);
    ~Cpu();
    virtual dataValue read() override;
    virtual void simulate();
    virtual int  test(string label) /*override*/;
};

#endif // _CPU_HPP_