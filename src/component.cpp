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

//----- Constructeurs
/**
 * @brief Instancie un composant sans source
 * 
 * @param label Nom de l'instance
 */
Component::Component(component_t type, string label) : type(type), label(label), source(*this) {}

/**
 * @brief Instancie un composant avec une source
 * 
 * @param label Nom de l'instance
 * @param source Référence vers le composant source
 */
Component::Component(component_t type, string label, Component &source) : type(type), label(label), source(source) {}

//----- Destructeur
/**
 * @brief Destroy the Component:: Component object
 * 
 */
Component::~Component() {}

//---- Méthodes get
/**
 * @brief Retourne le type du composant
 * 
 * @return component_t 
 */
component_t Component::getType() const{
    return type;
}

/**
 * @brief Retourne le label du composant
 * 
 * @return string 
 */
string Component::getLabel() const{
    return label;
}

/**
 * @brief Retourne la source du composant
 * 
 * @return Component& 
 */
Component &Component::getSource() const{
    return source;
}
