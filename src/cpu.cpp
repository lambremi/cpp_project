/**
 * @file cpu.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "cpu.hpp"

/**
 * @brief Construct a new Cpu:: Cpu object
 * 
 * @param type - type (CPU)
 * @param label - name of the CPU
 * @param path_to_prog - path to the program to execute
 * @param n_core - number of core
 * @param freq - frequency of the CPU
 */
Cpu::Cpu(component_t type, string label, string path_to_prog, int n_core, int freq) : Component(type, label), 
n_core(n_core),
active_core(0),
freq(freq),
reg(Register()),
prog(Program(path_to_prog))
{
    // cout << "CPU constructor" << endl;
}

/**
 * @brief Destroy the Cpu:: Cpu object
 * 
 */
Cpu::~Cpu()
{
    // cout << "CPU destructor" << endl;
}

/**
 * @brief read method of the CPU
 * 
 * @return dataValue - value read in the register with the validity flag
 */
dataValue Cpu::read()
{
    dataValue value;
    if (reg.isEmpty()) {
        value.flag = false;
        value.value = 0;
        return value;
    }
    else {
        value.flag = true;
        value.value = reg.read();
        return value;
    }
}

/**
 * @brief simualtion method for the CPU,
 * execute the program in the CPU
 */
void Cpu::simulate()
{
    for (int i = 0; i < freq; i++) {
        decode_t instruction = prog.decode();
        if (instruction.instruction == NOP && active_core < n_core) {
            active_core++;
            prog.resetProg();            
        }
        else if (instruction.instruction == NOP && active_core == n_core) {
            active_core = 0;
            prog.resetProg();
            break;
        }
        if (instruction.instruction != NOP){
            double result = prog.execute(instruction);
            reg.write(result);
        }
    }
}