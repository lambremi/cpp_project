/**
 * @file component.cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Implémentation de la classe Component
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "component.hpp"
#include <iostream>
#include <string>
#include "dataValue.hpp"

using namespace std;

// Constructeurs
/**
 * @brief Constructeur pour un composant sans source
 * 
 */
Component::Component(string label) : label(label), source(*this) {}

/**
 * @brief Constructeur pour un composant avec source
 * 
 */
Component::Component(string label, Component &source) : label(label), source(source) {}

// Méthodes get
/**
 * @brief Retourne le type du composant
 * 
 * @return component_t 
 */
component_t Component::getType() const{
    return this->type;
}

/**
 * @brief Retourne le label du composant
 * 
 * @return string 
 */
string Component::getLabel() const{
    return this->label;
}

/**
 * @brief Retourne la source du composant
 * 
 * @return Component& 
 */
Component &Component::getSource() const{
    return this->source;
}
