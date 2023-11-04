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
    #ifdef _DEBUG_
    cout << "CPU constructor" << endl;
    #endif
}

/**
 * @brief Destroy the Cpu:: Cpu object
 * 
 */
Cpu::~Cpu()
{
    #ifdef _DEBUG_
    cout << "CPU destructor" << endl;
    #endif
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
            #ifdef _DEBUG_
            cout << "CPU " << label << " : reg write " << result << endl;
            #endif
            reg.write(result);
        }
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
/**
 * @brief Test l'instance du CPU
 * 
 * @param label Label attendu du CPU
 * @param tst_arg Ne pas utiliser
 * @return int - 1 si erreur, 0 sinon
 */
int Cpu::test(string label, int tst_arg) {
    dataValue value;

    // Changement des paramètres pour le test
    #ifdef _DEBUG_
    cout << "CPU " << label << "overriding test program" << endl;
    #endif
    prog = Program("data/basic_program.txt");
    if (this->n_core != 2) {
        #ifdef _DEBUG_
        cout << "CPU " << label << " : overriding n_core from " << this->n_core << " to 2" << endl;
        #endif
        this->n_core = 2;
    }
    if (this->freq != 3) {
        #ifdef _DEBUG_
        cout << "CPU " << label << " : overriding freq from " << this->freq << " to 3" << endl;
        #endif
        this->freq = 3;
    }

    if (this->getLabel() != label) {
        cout << "Error: label is not \"" << label << "\"" << endl;
        return 1;
    }
    if (this->getType() != CPU) {
        cout << "Error: type is not CPU" << endl;
        return 1;
    }
    if (this->read().flag != false) {
        cout << "Error: read() is not false but nothing happened yet" << endl;
        return 1;
    }
    
    this->simulate();
    value = this->read();
    if (value.flag != true) {
        cout << "Error: first read() is not true" << endl;
        return 1;
    }
    if (value.value != 5) {
        cout << "Error: first read() is not 5" << endl;
        return 1;
    }
    value = this->read();
    if (value.flag != true) {
        cout << "Error: second read() is not true" << endl;
        return 1;
    }
    if (value.value != 5) {
        cout << value.value << endl;
        cout << "Error: second read() is not 5" << endl;
        return 1;
    }
    value = this->read();
    if (value.flag != false) {
        cout << "Error: third read() is not false" << endl;
        return 1;
    }
    return 0;
}
#pragma GCC diagnostic pop