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