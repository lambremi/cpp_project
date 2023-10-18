/**
 * @file component.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Classe component
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>
#include "dataValue.hpp"

using namespace std;

/**
 * @brief Type énumérant des différents composants
 * 
 */
typedef enum {PLATFORM, CPU, BUS, MEMORY, DISPLAY} component_t;

/**
 * @brief Classe de base permettant de définir tous les autres composants
 * 
 */
class Component
{
public:
    // Constructeurs
    Component(component_t type, string label);
    Component(component_t type, string label, Component &source);

    // Destructeurs
    ~Component();

    // Méthodes get
    virtual component_t getType() const;
    virtual string getLabel() const;
    virtual Component &getSource() const;

    // Interactions
    virtual dataValue read() const = 0;
    virtual void simulate() = 0;
    
protected:
    component_t type;
    string label;
    Component &source;
};

#endif // _COMPONENT_HPP_