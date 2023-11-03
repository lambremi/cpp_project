/**
 * @file bus.cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "bus.hpp"
#include "cpu.hpp"
#include <iostream>

/**
 * @brief Constructeur de la classe Bus
 * 
 * @param type - Type du composant
 * @param label - Nom du composant
 * @param src - Nom de la source
 * @param width - Largeur du bus
 */

Bus::Bus(component_t type, string label, string src, int width) :   Component(type, label, src), 
                                                                    width(width), 
                                                                    read_count(0) {}
/**
 * @brief Destroy the Bus:: Bus object
 * 
 */

Bus::~Bus() {}

/**
 * @brief Méthode de lecture du bus
 * 
 * @return dataValue - Valeur lue dans le bus
 */

dataValue Bus::read() {
    dataValue value;
    if (ready_data.empty()) {
        value.flag = false;
        value.value = 0;
    }
    else {
        value = ready_data.front();
        ready_data.pop();
    }
    read_count++;
    return value;
}

/**
 * @brief Méthode de simulation du bus
 * 
 */

void Bus::simulate() {
    size_t pending_size = pending_data.size();
    for (size_t i = 0; i < pending_size; i++) {
        ready_data.push(pending_data.front());
        pending_data.pop();
    }
    for (int i = 0; i < width; i++) {
        dataValue value = source->read();
        if (value.flag) {
            pending_data.push(value);
        }
        else {
            break;
        }
    }
}

/**
 * @brief Retourne le nombre de lectures du bus
 * 
 * @return int - Nombre de lectures du bus
 */

int Bus::getReadCount() const {
    return read_count;
}

/**
 * @brief Retourne la largeur du bus
 * 
 * @return int - Largeur du bus
 */

int Bus::getWidth() const {
    return width;
}

/**
 * @brief Test l'instance du bus
 * 
 * @param label Label attendu du bus
 * @param tst_arg Largeur attendu du bus
 * @return int - 1 si erreur, 0 sinon
 */
int Bus::test(string label, int tst_arg) {
    Cpu cpu(CPU, "source", "data/basic_program.txt", 2, 3);
    Component* source = &cpu;

    if (this->getLabel() != label) {
        cout << "Error: label is not \"" << label << "\"" << endl;
        return 1;
    }
    if (this->getType() != BUS) {
        cout << "Error: type is not BUS" << endl;
        return 1;
    }
    if (this->getReadCount() != 0) {
        cout << "Error: Expected bus to have 0 read count\n" << endl;
        return 1;
    }
    if (this->getWidth() != tst_arg) {
        cout << "Error: Expected bus to have width" << tst_arg << "\n" << endl;
        return 1;
    }
    this->setSource(&cpu);
    this->getSource(source);
    if (source->getType() != CPU) {
        cout << "Error: Expected bus to have cpu as source\n" << endl;
        return 1;
    }
    if (this->read().flag) {
        cout << "Error: Expected bus to be empty\n" << endl;
        return 1;
    }
    cpu.simulate();
    this->simulate();
    this->simulate();
    dataValue value = this->read();
    if (this->getReadCount() != 2) {
        cout << "Error: Expected bus to have 2 read count\n" << endl;
        return 1;
    }
    if (!value.flag) {
        cout << "Error: Expected bus to be not empty 1\n" << endl;
        return 1;
    }
    if (value.value != 5) {
        cout << "Error: Expected bus to first read 5\n" << endl;
        return 1;
    }
    value = this->read();
    if (!value.flag) {
        cout << "Error: Expected bus to be not empty 2\n" << endl;
        return 1;
    }
    if (value.value != 5) {
        cout << "Error: Expected bus to second read 5\n" << endl;
        return 1;
    }
    value = this->read();
    if (value.flag) {
        cout << "Error: Expected bus to be empty\n" << endl;
        return 1;
    }
    return 0;
}