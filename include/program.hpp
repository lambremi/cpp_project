/**
 * @file program.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
/**
 * @brief Type d'instruction
 * 
 */
typedef enum {NOP, ADD, SUB, MUL, DIV} instruction_t;

/**
 * @brief Structure contenant le type d'instruction
 * et les 2 opérandes
 */
typedef struct {
    instruction_t instruction;
    double a;
    double b;
} decode_t;

/**
 * @brief class Program 
 * to be used within a CPU
 */
class Program {
    private:
        string path;
        int pc;
    public:
        Program(string path);
        ~Program();
        int getPC();
        void resetProg();
        decode_t decode();
        double execute(decode_t instruction);
};

#endif // PROGRAM_HPP