#include "program.hpp"

int main() {
    Program program("../data/program.txt");
    decode_t instruction;
    double result;

    // test decode
    instruction = program.decode();
    if (instruction.instruction != ADD) {
        cout << "Error: Expected ADD but got something else" << endl;
        return 1;
    }
    if (instruction.a != 2) {
        cout << "Error: Expected 2 in a but got something else" << endl;
        return 1;
    }
    if (instruction.b != 3) {
        cout << "Error: Expected 3 in b but got something else" << endl;
        return 1;
    }
    if (program.getPC() != 1) {
        cout << "Error: Expected 1 as PC but got something else" << endl;
        return 1;
    }

    // test execute ADD
    result = program.execute(instruction);
    if (result != 5) {
        cout << "Error: Expected 5 as a result but got something else" << endl;
        return 1;
    }
    // test execute SUB
    instruction = program.decode();	
    result = program.execute(instruction);
    if (result != 3.3) {
        cout << "Error: Expected 3.3 as a result but got something else" << endl;
        return 1;
    }
    // test execute MUL
    instruction = program.decode();
    result = program.execute(instruction);
    if (result != 15.006) {
        cout << "Error: Expected 15.006 as a result but got something else" << endl;
        return 1;
    }
    // test execute DIV
    instruction = program.decode();
    result = program.execute(instruction);
    if (result != 4.2) {
        cout << "Error: Expected 4.2 as a result but got something else" << endl;
        return 1;
    }

    // test resetProg
    program.resetProg();
    if (program.getPC() != 0) {
        cout << "Error: Expected 0 as PC but got something else" << endl;
        return 1;
    }

    // test full program
    while (instruction.instruction != NOP) {
        instruction = program.decode();
    }
    if (program.getPC() != 50) {
        cout << "Error: Expected 50 as PC but got something else" << endl;
        return 1;
    }

    return 0;
}