/**
 * @file program.cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "program.hpp"

/**
 * @brief Construct a new Program:: Program object
 * 
 * @param path 
 */
Program::Program(string path) : path("../" + path) {
    pc = 0;
}

/**
 * @brief Destroy the Program:: Program object
 * 
 */
Program::~Program() {} 

/**
 * @brief Return the program counter
 * 
 * @return int - The program counter
 */
int Program::getPC() {
    return pc;
}

/**
 * @brief Reset the program
 * i.e. Put it back to the first instr
 */
void Program::resetProg() {
    pc = 0;
}

/**
 * @brief Decode the next instruction in the program
 * 
 * @return decode_t - 
 */
decode_t Program::decode() {
    ifstream file(path);
    string line; 
    double a, b;
    string instr;
    instruction_t instruction;
    decode_t instr_decode;
    if (file.is_open()) {
        for (int i = 0; i < pc; i++) {
            getline(file, line);
        }
        if (file.eof()) {
            instr_decode.instruction = NOP;
            instr_decode.a = 0;
            instr_decode.b = 0;
            return instr_decode;
        }
        getline(file, line);
        istringstream iss(line);
        iss >> instr >> a >> b;
        if (instr == "ADD") {
            instruction = ADD;
        }
        else if (instr == "SUB") {
            instruction = SUB;
        }
        else if (instr == "MUL") {
            instruction = MUL;
        }
        else if (instr == "DIV") {
            instruction = DIV;
        }
        instr_decode.instruction = instruction;
        instr_decode.a = a;
        instr_decode.b = b;
        pc++;
        file.close();
        return instr_decode;
    }
    else {
        cout << "Error: Unable to open file " << path << endl;
        exit(1);
    }
}

/**
 * @brief Execute the instruction given
 * 
 * @param instruction - to be executed
 * @return double - result of the operation
 */
double Program::execute(decode_t instruction) {
    double result;
    switch (instruction.instruction) {
        case NOP:
            result = 0;
            break;
        case ADD:
            result = instruction.a + instruction.b;
            break;
        case SUB:
            result = instruction.a - instruction.b;
            break;
        case MUL:
            result = instruction.a * instruction.b;
            break;
        case DIV:
            result = instruction.a / instruction.b;
            break;
        default:
            cout << "Error: Unknown instruction" << endl;
            exit(1);
    }
    return result;
}
        