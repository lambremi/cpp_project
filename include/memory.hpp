/**
 * @file memory.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Module memory
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

#include "component.hpp"
// #include "test.hpp"

class Memory : public Component
{
private:
    // Rescources du circular buffer
    /**
     * @brief Circular buffer
     * https://en.wikipedia.org/wiki/Circular_buffer
     */
    typedef struct memElement {
        dataValue value;                    // Donnée
        memElement* next;                   // Pointeur vers l'élément suivant
    } memElement_t;

    memElement_t* readPtr;                  // Pointeur de lecture
    memElement_t* writePtr;                 // Pointeur d'écriture

    memElement_t* createMem(int size);
    void deleteMem(memElement_t* mem);
    void write(dataValue value);

    // Attributs
    int access;                             // Access time
    int wait;                               // Wait time

    // Rescources liées au test
    #ifdef _TEST_HPP_
    friend int test_memory(Memory mem, std::string label, int size, int access);
    #endif

public:
    // Constructeur
    Memory(
        component_t type,
        string label,
        int size,
        int access,
        string source
    );

    // Destructeur
    ~Memory();

    // Interface
    int getAccess();

    // Interaction
    dataValue read() override;
    void simulate()  override;

    // Test
    int test(string label, int access);
};

#endif // _MEMORY_HPP_