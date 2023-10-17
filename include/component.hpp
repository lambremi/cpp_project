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
 * @brief Classe de base permettant de définir tous les autres composants
 * 
 */
class Component
{
public:
    // Constructeurs
    Component(string label);
    Component(string label, Component &source);

    // Destructeurs
    ~Component();

    // Méthodes get
    virtual string getLabel() const;
    virtual Component &getSource() const;

    // Interactions
    virtual dataValue read() const;
    virtual void simulate();
    
protected:
    string label;
    Component &source;
};

#endif // _COMPONENT_HPP_