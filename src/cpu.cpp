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

Cpu::Cpu(component_t type, string label, string path_to_prog, int n_core, int freq) : Component(type, label), 
n_core(n_core),
active_core(0),
freq(freq),
reg(Register()),
prog(Program(path_to_prog))
{
    // cout << "CPU constructor" << endl;
}

Cpu::~Cpu()
{
    // cout << "CPU destructor" << endl;
}

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