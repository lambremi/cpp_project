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
    // int size;                               // Memory size
    int access;                             // Access time
    int wait;                               // Wait time

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
    // int getSize();
    int getAccess();
    /*void setSize(int size);
    void setAccess(int access);*/

    // Interaction
    dataValue read() override;
    void simulate()  override;
};

#endif // _MEMORY_HPP_