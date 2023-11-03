/**
 * @file this->cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Module memory
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "memory.hpp"

#include <iostream>

/**
 * @brief Construct a new Memory:: Memory object
 * 
 * @param type Type de composant
 * @param label Label du composant
 * @param size Taille de la mémoire
 * @param access Temps d'accès de la mémoire
 * @param source Source de données de la mémoire
 */
Memory::Memory(
    component_t type,
    string label,
    int size,
    int access,
    string source
) : Component(type, label, source),
    // size(size),
    access(access) {
    // Création du circular buffer
    readPtr = createMem(size);
    writePtr = readPtr;
    wait = 0;
}

/**
 * @brief Destroy the Memory:: Memory object
 * 
 */
Memory::~Memory() {
    deleteMem(readPtr);
}

/**
 * @brief Créer un circular buffer
 * 
 * @param size Taille du circular buffer
 * @return memElement_t* Pointeur vers le
 * premier élément du circular buffer
 */
Memory::memElement_t* Memory::createMem(int size) {
    memElement_t* first;
    memElement_t* current;
    memElement_t* previous;

    // Création du premier élément
    first = new memElement_t;
    first->value.value = 0;
    first->value.flag = false;
    previous = first;

    // Création des éléments suivants
    for (int i = 1; i < size; i=i+1) {
        current = new memElement_t;
        current->value.value = 0;
        current->value.flag = false;
        previous->next = current;
        previous = current;
    }
    previous->next = first;

    return first;
}

/**
 * @brief Détruit un circular buffer
 * 
 * @param mem Pointeur sur un élément du 
 * circular buffer
 */
void Memory::deleteMem(memElement_t* mem) {
    memElement_t* current = mem;

    while (current->next != mem) {
        memElement_t* next = current->next;
        delete current;
        current = next;
    }
}

/**
 * @brief Retourne le temps d'accès de la mémoire
 * 
 * @return int - Temps d'accès
 */
int Memory::getAccess() {
    return access;
}

/**
 * @brief Lit la mémoire
 * 
 * @return dataValue - Dernière valeur disponible 
 */
dataValue Memory::read() {
    dataValue returnedValue = readPtr->value;
    readPtr->value.flag = false;
    readPtr = readPtr->next;
    return returnedValue;
}

void Memory::write(dataValue value) {
    writePtr->value = value;
    // writePtr->value.flag = true;            // Devrait déjà être à true
    writePtr = writePtr->next;
}

/**
 * @brief Simule la mémoire : si la mémoire
 * est prête elle lit toutes les données de 
 * la source
 * 
 */
void Memory::simulate() {
    dataValue readValue;
    // Mémoire en attente
    if (wait < access)
        wait = wait + 1;
    // Mémoire prête : on lit toutes les données disponibles sur la source
    else {
        wait = 0;
        if (source != NULL) {
            readValue = source->read();
            while (readValue.flag) {
                write(readValue);
                readValue = source->read();
            }
        }
        #ifdef _DEBUG_
        else
            cout << "Erreur : la mémoire " << label << " n'a pas de source" << endl;
        #endif
    }
}

/**
 * @brief Test l'instance de la classe Memory
 * 
 * @param label Label attendu
 * @param access Temps d'accès attendu
 * @return int - 1 si erreur, 0 sinon
 */
int Memory::test(string label, int access) {
    // Test the label and type
    if (this->getLabel() != label) {
        cout << "Error: label is not \"" << label << "\"" << endl;
        return 1;
    }
    if (this->getType() != MEMORY) {
        cout << "Error: type is not MEMORY" << endl;
        return 1;
    }

    // Test the access time
    if (this->getAccess() != access) {
        cout << "Error: access time is not " << access << endl;
        return 1;
    }

    // Test the read and write methods
    dataValue value;
    value.value = 10;
    value.flag = true;
    this->write(value);
    dataValue readValue = this->read();
    if (readValue.value != 10 || readValue.flag != true) {
        cout << "Error: read value is not correct" << endl;
        return 1;
    }

    // Test the simulate method
    this->simulate();
    readValue = this->read();
    if (readValue.flag != false) {
        cout << "Error: read flag is not false after simulate" << endl;
        return 1;
    }

    return 0;
}